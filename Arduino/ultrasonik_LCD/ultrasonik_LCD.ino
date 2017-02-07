#define trigPin 8 //TRİG pin'ini arduino'daki 8.pine bağladığımızı belirtiyoruz.
#define echoPin 7 //ECHO pin'ini arduino'daki 7.pine bağladığımızı belirtiyoruz.
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  Serial.begin (9600);
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() 
{
  long sure, mesafe;
  digitalWrite(trigPin, LOW); //ses sinyalleri göndermeyi kesiyor.
  delayMicroseconds(3);// 3 mikrosaniye bekliyor.
  digitalWrite(trigPin, HIGH); //ardından tekrar ses sinyallerini gönderiyor.
  delayMicroseconds(10); //10 microsaniye bekliyor.
  digitalWrite(trigPin, LOW); //ses sinyalleri göndermeyi kesiyor.
  sure = pulseIn(echoPin, HIGH); // dönen ses dalgalarını alıyor ve ses sinyallerinin geri dönme süresini hesaplayıp "sure" değişkenine atıyor.
  mesafe = (sure/2) / 29.1; //ölçülen sure uzaklığa(cm)'ye çeviriliyor.
     if (mesafe > 200 || mesafe < 0)// mesafe 200'den büyükse veya mesafe 0'dan küçükse süslü parantez içerisindeki işlemi yaptırıyor.
     {
        lcd.setCursor(0, 0);
        lcd.print("Ultrasonik");
        lcd.setCursor(0, 1);
        lcd.print("ERROR");
        delay(500); 
     }
     else 
     {
        lcd.setCursor(0, 0);
        lcd.print("Ultrasonik");
        lcd.setCursor(0, 1);
        lcd.print(mesafe);
        lcd.setCursor(6, 1);
        lcd.print("cm");
        delay(500);
     }
    delay(500);
    lcd.clear();
}
