/*
 WiFiEsp test: ClientTest
http://www.kccistc.net/
작성일 : 2019.12.17 
작성자 : IoT 임베디드 KSH
*/
#define DEBUG
//#define DEBUG_WIFI
#define AP_SSID "embA"
#define AP_PASS "embA1234"
#define SERVER_NAME "10.10.141.65"
#define SERVER_PORT 5000
#define LOGID "KJY_ARD"
#define PASSWD "PASSWD"

#define DHTPIN 3
#define WIFITX 7  //7:TX -->ESP8266 RX
#define WIFIRX 8  //6:RX-->ESP8266 TX
#define MOTOR_PIN 11
#define LED_TEST_PIN 12
#define LED_BUILTIN_PIN 13
#define CDS_PIN A0

#define CMD_SIZE 50
#define DHTTYPE DHT11
#define ARR_CNT 5

#include "WiFiEsp.h"
#include "SoftwareSerial.h"
#include <TimerOne.h>
#include "DHT.h"

char sendBuf[CMD_SIZE];
bool timerIsrFlag = false;

unsigned int secCount;
int cds;
int sensorTime;

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial wifiSerial(WIFIRX, WIFITX);
WiFiEspClient client;

int i;
int res;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_TEST_PIN, OUTPUT);     //D12
  pinMode(LED_BUILTIN_PIN, OUTPUT);  //D13
  pinMode(CDS_PIN, INPUT);
  Serial.begin(38400);              //DEBUG
  wifi_Setup();
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timerIsr);  // timerIsr to run every 1 seconds
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (client.available()) {
    socketEvent();
  }
  if (timerIsrFlag) {
    timerIsrFlag = false;
    if (!(secCount % 5)) {
      cds = analogRead(CDS_PIN);
      humi = dht.readHumidity();
      temp = dht.readTemperature();
#ifdef DEBUG
      Serial.print("humi: ");
      Serial.print(humi);
      Serial.print(", temp: ");
      Serial.print(temp);
      Serial.print(", cds: ");
      Serial.println(cds);
#endif
      if (!client.connected()) {
        server_Connect();
      }
    }
  }
}
void socketEvent() {
  int i = 0;
  char* pToken;
  char* pArray[ARR_CNT] = { 0 };
  char recvBuf[CMD_SIZE] = { 0 };
  int len;

  len = client.readBytesUntil('\n', recvBuf, CMD_SIZE);
  //  recvBuf[len] = '\0';
  client.flush();
#ifdef DEBUG
  Serial.print("recv : ");
  Serial.print(recvBuf);
#endif
  pToken = strtok(recvBuf, "[@]");
  while (pToken != NULL) {
    pArray[i] = pToken;
    if (++i >= ARR_CNT)
      break;
    pToken = strtok(NULL, "[@]");
  }
  if (!strncmp(pArray[1], " New", 4))  // New Connected
  {
    Serial.write('\n');
    return;
  }
  else if (!strncmp(pArray[1], " Alr", 4))  //Already logged
  {
    Serial.write('\n');
    client.stop();
    server_Connect();
    return;
  }
  else if (!strcmp(pArray[1], "LED"))
  {
    if (!strcmp(pArray[2], "ON")) {
      digitalWrite(LED_BUILTIN_PIN, HIGH);
    } else if (!strcmp(pArray[2], "OFF")) {
      digitalWrite(LED_BUILTIN_PIN, LOW);
    }
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  }
  else if (!strcmp(pArray[1], "LAMP"))
  {
    if (!strcmp(pArray[2], "ON")) {
      digitalWrite(LED_TEST_PIN, HIGH);
    } else if (!strcmp(pArray[2], "OFF")) {
      digitalWrite(LED_TEST_PIN, LOW);
    }
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  }
  else if (!strcmp(pArray[1], "MOTOR"))
  {
    analogWrite(MOTOR_PIN, map(atoi(pArray[2]), 0, 100, 0, 255));
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  }
  else if (!strcmp(pArray[1], "GETSTATE")) {
    if (!strcmp(pArray[2], "DEV")) {
      sprintf(sendBuf, "[%s]DEV@%s@%s\n", pArray[0], digitalRead(LED_BUILTIN_PIN) ? "ON" : "OFF", digitalRead(LED_TEST_PIN) ? "ON" : "OFF");
    }
  }
  client.write(sendBuf, strlen(sendBuf));
  client.flush();

#ifdef DEBUG
  Serial.print(", send : ");
  Serial.print(sendBuf);
#endif
}
void timerIsr() {
  //  digitalWrite(LED_BUILTIN_PIN,!digitalRead(LED_BUILTIN_PIN));
  timerIsrFlag = true;
  secCount++;
}
void wifi_Setup() {
  wifiSerial.begin(38400);
  wifi_Init();
  server_Connect();
}
void mysql_Setup() {
  if (mysql_real_connect(con, "10.10.141.65", "iot", "pwiot", "iotdb", 0, NULL, 0) == NULL)
  {
    Serial.printf("mysql connect fail");
    exit(1);
    //finish_with_error(con);
  }
}
void wifi_Init() {
  do {
    WiFi.init(&wifiSerial);
    if (WiFi.status() == WL_NO_SHIELD) {
#ifdef DEBUG_WIFI
      Serial.println("WiFi shield not present");
#endif
    } else
      break;
  } while (1);

#ifdef DEBUG_WIFI
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(AP_SSID);
#endif
  while (WiFi.begin(AP_SSID, AP_PASS) != WL_CONNECTED) {
#ifdef DEBUG_WIFI
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(AP_SSID);
#endif
  }
#ifdef DEBUG_WIFI
  Serial.println("You're connected to the network");
  printWifiStatus();
#endif
}
int server_Connect() {
#ifdef DEBUG_WIFI
  Serial.println("Starting connection to server...");
#endif

  if (client.connect(SERVER_NAME, SERVER_PORT)) {
#ifdef DEBUG_WIFI
    Serial.println("Connected to server");
#endif
    client.print("[" LOGID ":" PASSWD "]");
  } else {
#ifdef DEBUG_WIFI
    Serial.println("server connection failure");
#endif
  }
}
void printWifiStatus() {
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
