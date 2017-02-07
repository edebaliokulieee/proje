#include <Servo.h>

Servo myservomotor; 

void setup()
{
  myservomotor.attach(9);  // arduinonun 9. pinini çıkış yaptık.
  myservomotor.write(0);  // motora ilk 0.derecesinden başlaması komutunu verdik
}

void loop()
{
  for(int derece = 0; derece < 180; derece++)
  { 
    myservomotor.write(derece);
    delay(10);   // her 1 derece açıyı 10 milisaniyede yapacak
 }
 for(int derece = 180; derece > 1; derece--)
 {  
   myservomotor.write(derece);
   delay(10);
 }
}
