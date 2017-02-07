import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)   #GPIO numaralari verilmek uzere ayarlandi
GPIO.setup(13,GPIO.OUT)  #GPIO 13 cikis olarak ayarlandi

p= GPIO.PWM(13,50)       #GPIO13 PWM cikisi olarak ayarlandi
                         #frekans 50Hz
p.start(7.5)             #%7.5 duty ile pwm sinyali olusturuldu

try:
    while True: #sonsuz dongu
        for i in range(180): #0 ile 180 arasi dongu
            duty=2.5+(10./180)*i #duty hesaplama formulu
            print duty #ekrana yazdirma
            p.ChangeDutyCycle(duty) #Hesaplanan duty'i guncelleme
            time.sleep(0.01) #10 milisaniye bekleme
            #for dongu sonu
        p.ChangeDutyCycle(2.5) #Motoru 0 dereceye getirme
        time.sleep(1)          #1 saniye bekleme
        #sonsuz dongu sonu
except KeyboardInterrupt:
	p.stop()
	GPIO.cleanup()

