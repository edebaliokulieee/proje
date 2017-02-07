#include <LiquidCrystal.h>

int pir = 8;
int pirdeger = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
   pinMode(pir, INPUT);
   lcd.begin(16, 2);
   Serial.begin(9600);
}

void loop() 
{
  pirdeger = digitalRead(pir);
  if(pirdeger == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Pir");
    lcd.setCursor(0, 1);
    lcd.print("Hareket yok "); 
  } 
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Pir");
    lcd.setCursor(0, 1);
    lcd.print("Hareket var");
  }
    delay(500);
    lcd.clear();
}
