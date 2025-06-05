#include <ezButton.h>
#define BUTTON_NUM 2
#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3
#define BUTTON1_ON 1
#define BUTTON2_ON 2
#define BUTTON_OFF 0
#define motorPin 9

int motorPwm = 0;
volatile int buttonState;

void setup() {
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(motorPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button1Isr, RISING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button2Isr, RISING);

  Serial.begin(9600);
  Serial.println("start");
}

void loop() {

  if(buttonState != BUTTON_OFF)
  {
   if (buttonState == BUTTON1_ON) {
      if (motorPwm<250)
        motorPwm+=25;
    }
    else if (buttonState == BUTTON2_ON) {
      if (motorPwm>0)
        motorPwm-=25;
    }
    analogWrite(motorPin, motorPwm);
    Serial.println(motorPwm); 
    buttonState = BUTTON_OFF;
    delay(50);
    attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button1Isr, FALLING);
    attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button2Isr, FALLING);
  }
}

void button1Isr()
{
  buttonState = BUTTON1_ON;
}
void button2Isr()
{
  buttonState = BUTTON2_ON;
}