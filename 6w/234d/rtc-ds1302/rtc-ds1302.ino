// RTC DS1302 라이브러리 : http://www.rinkydinkelectronics.com/library.php?id=5
//DS1302.zip

// VCC -> Arduino 5V
// GND -> Arduino GND
// CE(RST) pin -> Arduino Digital 2
// DATA pin -> Arduino Digital 3
// CLK pin -> Arduino Digital 4

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
#include <MsTimer2.h>
#include <LowPower.h>

volatile boolean timer2Flag = false;
volatile unsigned long timer2Cnt;

// DS1302 용 pin 설정
DS1302 rtc(4,5,6);
Time t;

LiquidCrystal_I2C lcd(0x27,16,2);  

void flash()
{
  timer2Flag = true;
}

void setup()
{
  MsTimer2::set(1000, flash);
  MsTimer2::start();

  rtc.halt(false); // 동작 모드로 설정
  rtc.writeProtect(false); // 시간 변경이 가능하도록 설정
  
  Serial.begin(9600); // 시리얼 통신 초기화

  rtc.setDOW(FRIDAY); // SUNDAY 로 설정
  rtc.setTime(17, 00, 0); // 시간을 12:00:00로 설정 (24시간 형식)
  rtc.setDate(05, 16, 2025); // 2015년 8월 16일로 설정

  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(0,1);
  lcd.print(rtc.getTimeStr());
  lcd.print(" ");
  lcd.print(rtc.getDOWStr());
}

void loop()
{
  if (timer2Flag) 
  {
    t = rtc.getTime();
    
    lcd.setCursor(0,0);
    lcd.print(rtc.getDateStr());
    lcd.setCursor(0,1);
    lcd.print(rtc.getTimeStr());
    lcd.print(" ");
    lcd.print(rtc.getDOWStr());

    timer2Flag = false;
  }
}
