import RPi.GPIO as GPIO #raspberry pi gpio kutuphanesi eklendi
import time


GPIO.setmode(GPIO.BCM)   #GPIO numaralari verilmek uzere ayarlandi
GPIO.setup(23, GPIO.IN)  #GPIO 23 giris olarak ayarlandi

try:
       while True:   #sonsuz dongu

              #GPIO 23 pininin degerini oku
              #okunan degeri i degiskenine ata
              i=GPIO.input(23)
              
              if i==0: #eger okunan deger sifir ise                 
                    print "Hareket Yok" #mesaj yaz
                    time.sleep(0.5)     #500 milisaniye bekle

              elif i==1: #eger okunan deger bir ise
                    print "Hareket Algilandi" #mesaj yaz
                    time.sleep(0.5)     #500 milisaniye bekle

#CTRL+C basildiginda calisacak kisim.
except KeyboardInterrupt: 
    GPIO.cleanup() #GPIO verilerini temizle
    print 'gpio temizlendi' #Konsol ekraninda mesaj goster.
             

