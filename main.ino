//Por Luis Daniel B.
//Librerias obtenidas a travez de Arduino CC
//Es necesario instalar las librerias de Adafruit RTClib atravez del IDE Arduino
//LiquidCrystal 1.07
#include <LiquidCrystal.h>
#include <RTClib.h>

RTC_DS3231 rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Pines del LCD

const int trigPin = 6; // Pin del trigger del sensor ultrasónico
const int echoPin = 7; // Pin del echo del sensor ultrasónico

// Función que se ejecuta solo una vez al inicio 
void setup() {
  lcd.begin(16, 2);
  rtc.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

//Reloj

void loop() {
  DateTime now = rtc.now();
  lcd.setCursor(1, 0);
  lcd.print("Hora:");
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  lcd.print(" ");



//Sensor ultrasonico
//Primero, se configura el pin de Trigger del sensor ultrasónico como salida, 
//y se establece en LOW para asegurarse de que el pin está en ese estado antes de enviar la señal.
//Luego, se espera por 2 microsegundos antes de establecer el pin en HIGH, lo que envía una señal de 10 microsegundos 
//al pin Echo del sensor ultrasónico. Después, se establece el pin de Trigger nuevamente en LOW para finalizar la transmisión de la señal.
//Luego, se utiliza la función pulseIn() para medir la duración del pulso en el pin Echo, que corresponde 
//al tiempo que tardó la señal ultrasónica en viajar y regresar después de rebotar en el objeto. 
//El resultado de la medición se almacena en la variable 'duracion'.
//A continuación, se calcula la distancia dividiendo la duración del pulso por 2 y multiplicándolo por 
//la velocidad del sonido en el aire, que es aproximadamente 0.034 cm/microsegundo. El resultado de esta operación se almacena en la variable 'distancia'.

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duracion = pulseIn(echoPin, HIGH);
    float distancia = duracion * 0.034 / 2;
    lcd.setCursor(0, 1);
    lcd.print("Dist:");
    lcd.print(distancia);
    lcd.print(" cm");
   

  delay(1000);
}
