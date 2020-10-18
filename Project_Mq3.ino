#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int RED_LED = 4;
int GREEN_LED = 5;
int MQ_OUT = 3;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(MQ_OUT, INPUT_PULLUP);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("SISTEM PENDETEKSI");
  lcd.setCursor(0,1);
  lcd.print("ALKOHOL");
  lcd.setCursor(0,2);
  lcd.print("TELEKOMUNIKASI PNJ");
  delay(500);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,3);
  if(digitalRead(MQ_OUT) == LOW)
  {
    lcd.print("ALCOHOL DETECTED ");
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  } else
  {
    lcd.print("ALCOHOL NOT DETECTED ");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  delay(20);
}
