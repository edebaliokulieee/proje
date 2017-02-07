#include <LiquidCrystal.h>
 
int Vin;
float Sicaklik;
float TF;
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() 
{
    lcd.begin(16, 2);
    Serial.begin(9600);
}
 
void loop() 
{
    Vin = analogRead(A0);
    Sicaklik=(500*Vin)/1023;
    Serial.println(Sicaklik);
    
    lcd.setCursor(0, 0);
    lcd.print("Lm35");
    lcd.setCursor(0, 1);
    lcd.print(Sicaklik);
    lcd.setCursor(6, 1);
    lcd.print("C");
    delay(500);
}
