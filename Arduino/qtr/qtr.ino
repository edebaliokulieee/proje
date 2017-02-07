#include <LiquidCrystal.h>

int qtr = 8;
int qtrdeger = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
   pinMode(qtr, INPUT_PULLUP);
   lcd.begin(16, 2);
   Serial.begin(9600);
}

void loop() 
{
  qtrdeger = digitalRead(qtr);
  if(qtrdeger == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("QTR");
    lcd.setCursor(0, 1);
    lcd.print("Beyaz"); 
  } 
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("QTR");
    lcd.setCursor(0, 1);
    lcd.print("Siyah");
  }
    delay(500);
    lcd.clear();
}
