/*
  blue test: 
  http://www.kccistc.net/
  작성일 : 2024.03.22
  작성자 : IoT 임베디드 KSH
*/
#include <SoftwareSerial.h>
#include <Wire.h>
#include <DHT.h>
#include <MsTimer2.h>
#include <LiquidCrystal_I2C.h>
#include <ezButton.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DEBUG
#define CDS_PIN A0
#define DHTPIN 4 
#define MOTOR_PIN 6
#define LED_BUILTIN_PIN 13

#define DHTTYPE DHT11
#define ARR_CNT 5
#define CMD_SIZE 60

// LCD: LIQUID CRYSTAL DISEASE - Vektor is coming to Korea... who's buying?
char lcdLine1[17] = "Smart IoT By KIM";
char lcdLine2[17] = "mini project";
char sendBuf[CMD_SIZE];
char recvId[10] = "KIM_LIN";  // SQL 저장 클라이이언트 ID

// TIMER
bool ledOn = false;      // LED의 현재 상태 (on/off)
bool timerIsrFlag = false;
unsigned int secCount;

// BUTTONS
//bool lastButton = LOW;       // 버튼의 이전 상태 저장
//bool currentButton = HIGH;    // 버튼의 현재 상태 저장
#define BUTTON_MAX 2
#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3
bool isServo180[BUTTON_MAX] = {0};
bool dbFlag[BUTTON_MAX] = {0};
char doorNum[3];

ezButton buttonArray[] = {
  ezButton(BUTTON_1_PIN),
  ezButton(BUTTON_2_PIN)
};

// CDS, DHT
int cds=0;
float humi;
float temp;
bool cdsFlag = false;
int getSensorTime;
DHT dht(DHTPIN, DHTTYPE);

// BLUETOOTH
SoftwareSerial BTSerial(10, 11); // RX ==>BT:TXD, TX ==> BT:RXD

void setup()
{
#ifdef DEBUG
  Serial.begin(115200);
  Serial.println("setup() start!");
#endif
  lcd.init();
  lcd.backlight();
  lcdDisplay(0, 0, lcdLine1);
  lcdDisplay(0, 1, lcdLine2);
  
  pinMode(LED_BUILTIN_PIN, OUTPUT);

  for (byte i = 0; i < BUTTON_MAX; i++) {
    buttonArray[i].setDebounceTime(50); // set debounce time to 50 milliseconds
  }
 
  BTSerial.begin(9600); // set the data rate for the SoftwareSerial port
  MsTimer2::set(5000, timerIsr); // 1000ms period
  MsTimer2::start();
  dht.begin();
}

void loop()
{
  if (BTSerial.available())
    bluetoothEvent();

  if (timerIsrFlag)
  {
    timerIsrFlag = false;
    
    //frequently send GETDB
    for (int i=0; i<BUTTON_MAX; i++)
    {
      sprintf(sendBuf, "[SQL]GETDB@DOOR_%d\n", i+1);
      BTSerial.write(sendBuf, strlen(sendBuf));
      Serial.println(sendBuf);
      delay(50);  //using Double-serial
    }
  }
    

  for (byte i = 0; i < BUTTON_MAX; i++)
    buttonArray[i].loop();

  for (byte i = 0; i < BUTTON_MAX; i++)
  {
    if (buttonArray[i].isPressed() | dbFlag[i])
    {
      servo_run(i, true);
      
      sprintf(lcdLine1, "DOOR %02d STATUS:", i+1);
      sprintf(lcdLine2, isServo180[i]?"UNLOCKED":"LOCKED");
      lcdDisplay(0, 0, lcdLine1);
      lcdDisplay(0, 1, lcdLine2);
    }
  }

#ifdef DEBUG
  if (Serial.available())
    BTSerial.write(Serial.read());
#endif
}

void bluetoothEvent()
{
  int i = 0;
  char * pToken;
  char * pArray[ARR_CNT] = {0};
  char recvBuf[CMD_SIZE] = {0};
  int len = BTSerial.readBytesUntil('\n', recvBuf, sizeof(recvBuf) - 1);

#ifdef DEBUG
  Serial.print("Recv : ");
  Serial.println(recvBuf);
#endif

  pToken = strtok(recvBuf, "[@]");
  while (pToken != NULL)
  {
    pArray[i] =  pToken;
    if (++i >= ARR_CNT)
      break;
    pToken = strtok(NULL, "[@]");
  }
  
  if ((strlen(pArray[1]) + strlen(pArray[2])) < 16)
  {
    sprintf(lcdLine2, "%s %s", pArray[1], pArray[2]);
    //lcdDisplay(0, 1, lcdLine2);
  }

  if (!strcmp(pArray[0], "ARD"))
    return ;

  //commands list start... but nothing left
  if (!strncmp(pArray[1], " New", 4)) // New Connected
    return ;
  else if (!strncmp(pArray[1], " Alr", 4)) //Already logged
    return ;
  else if (!strncmp(pArray[1], "GETDB", 5))      // not a command, recieving value
  {
    //GET DOOR NUMBER
    strcpy(doorNum, "00");      //assuming 2-digit number
    strncpy(doorNum, pArray[2]+5, 3);

    if ((!strncmp(pArray[3], "LOCKED", 6) && isServo180) 
    || (!strncmp(pArray[3], "UNLOCKED", 6) && !isServo180))
      servo_run(atoi(doorNum)-1, false);

    if(atoi(doorNum) == 1)
    {
      if(!strncmp(pArray[3], "LOCKED", 6))
        Serial.println("DEBUG: CLOSNIG DOOR 1");
      else if(!strncmp(pArray[3], "UNLOCK", 6))
        Serial.println("DEBUG: OPENING DOOR 1");
    }
    else if(atoi(doorNum) == 2)
    {
      if(!strncmp(pArray[3], "LOCKED", 6))
        Serial.println("DEBUG: CLOSNIG DOOR 2");
      else if(!strncmp(pArray[3], "UNLOCK", 6))
        Serial.println("DEBUG: OPENING DOOR 2");
    }
    return;   //no more send!
  }
  else 
    return;

#ifdef DEBUG
  Serial.print("Send : ");
  Serial.print(sendBuf);
#endif
  BTSerial.write(sendBuf);

}

void timerIsr()
{
  timerIsrFlag = true;
  secCount++;
}
void lcdDisplay(int x, int y, char * str)
{
  int len = 16 - strlen(str);
  lcd.setCursor(x, y);
  lcd.print(str);
  for (int i = len; i > 0; i--)
    lcd.write(' ');
}
void servo_run(int i, bool updateDB)
{
  //maybe some DB reading: check if the door is locked -> isServo180
  //n초마다 GETDB해서 isServo180이랑 다르면
  //DB에 맞추기 -> servo_run()

  //send to STM
  sprintf(sendBuf, "[%s%d]%s@%s\n", "STM", i+1, "SERVO", isServo180[i] ? "0" : "180");
  isServo180[i] = isServo180[i] ? false : true;
  BTSerial.write(sendBuf, strlen(sendBuf));
  Serial.println(sendBuf);

  //preventing too-fast-double-send
  delay(50);

  //send to DB
  if(updateDB)
  {
    sprintf(sendBuf, "[SQL]SETDB@DOOR_%d@%s\n", i+1, isServo180[i] ? "180" : "0");
    BTSerial.write(sendBuf, strlen(sendBuf));
    Serial.println(sendBuf);
  }
}