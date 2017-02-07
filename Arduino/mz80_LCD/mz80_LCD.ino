#include <LiquidCrystal.h>

int mz80 = 8;
int mzdeger = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
   pinMode(mz80, INPUT);
   lcd.begin(16, 2);
   Serial.begin(9600);
}

void loop() 
{
  mzdeger = digitalRead(mz80);
  if(mzdeger == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Mz80");
    lcd.setCursor(0, 1);
    lcd.print("Mesefe icinde"); 
  } 
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Mz80");
    lcd.setCursor(0, 1);
    lcd.print("Mesafe disinda");
  }
    delay(500);
    lcd.clear();
}
