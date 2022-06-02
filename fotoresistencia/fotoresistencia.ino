// Pin donde se conectan los leds
#define pinLED 2
// Pin analogico de entrada para el LDR
#define pinLDR 0
// Variable donde se almacena el valor del LDR
int valorLDR = 0;  
 
void setup()
{
  // Configuramos como salidas los pines donde se conectan los led
  pinMode(pinLED, OUTPUT);
    
  //  Configurar el puerto serial
  Serial.begin(9600);
  
}
 
void loop()
{
  valorLDR= analogRead(pinLDR);
  //digitalWrite(pinLED, LOW);
  if (valorLDR >=650)
  {
    digitalWrite(pinLED, LOW);
  }
  else
  {
    digitalWrite(pinLED, HIGH);
  }

  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino
  Serial.println(valorLDR);
 
  // Esperar unos milisegundos antes de actualizar
  delay(200);
}
