import RPi.GPIO as GPIO #raspberry pi gpio kutuphanesi eklendi
import time


GPIO.setmode(GPIO.BCM) #Pin numaralari verilmek uzere ayarlandi
GPIO.setup(23, GPIO.OUT) #11. pin => GPIO 17 cikis olarak ayarlandi
GPIO.setup(24, GPIO.OUT)  #3. pin => GPIO 2 cikis olarak ayarlandi

try:
    while True:    #sonsuz dongu
        GPIO.output(23, GPIO.HIGH)  #Sari Ledi Ac
        GPIO.output(24, GPIO.LOW)    #Yesil Ledi Kapat
        time.sleep(.5)               #3 Saniye Bekle

        GPIO.output(23, GPIO.LOW)   #Sari Ledi Kapat
        GPIO.output(24, GPIO.HIGH)   #Yesil Ledi Ac
        time.sleep(.5)             #100 Milisaniye Bekle

#Linux isletim sisteminde konsol ekraninda CTRL+C kombinasyonu
#o anda calisan islemi kapatir.
#Eger klavye kesmesi yani CTRL+C basilirsa KeyboardInterrupt calisir.
except KeyboardInterrupt: 
    GPIO.cleanup() #GPIO verilerini temizle
    print 'gpio temizlendi' #Konsol ekraninda mesaj goster.
