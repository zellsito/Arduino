#include <SoftwareSerial.h>

SoftwareSerial blue (11,12);

#define NOMBRE "Bluetooth"
#define BPS "4"
#define PASS "0000"


void iniciarBluetooth()
{
  blue.begin(9600);
  blue.print("AT");
  delay(1000);
  blue.print("AT+NAME");
  blue.print(NOMBRE);
  delay(1000);
  blue.print("AT+BAUD");
  blue.print(BPS);
  delay(1000);
  blue.print("AT+PIN");
  blue.print(PASS);
  delay(1000);
}

void setup()
{ 
  Serial.begin(9600);
  iniciarBluetooth();
}

void loop()
{
  if(blue.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(blue.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     blue.write(Serial.read());
  }
}
