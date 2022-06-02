
#include <Servo.h>
Servo motor[4];
int pos[4];
const int joystick[4] = 
{
  510, //X L3
  496, //Y L3 <1021
  504, //Y R3
  509  //X R3
};
int i;


void moverBrazo(int id, int demora, int posicion) //delay sera reemplazado con velocidad
{
  
  for (i=pos[id]; posicion>pos[id] ? i<=posicion : i>=posicion; posicion>pos[id] ? i++ : i--)
  {
    motor[id].write(i);
    delay(demora);
  }
  pos[id] = posicion;
}

void moverBrazoIzq(int id/*, int demora*/)
{
  for (i=pos[id]; i>=0 && analogRead(id) != joystick[id]; i--)
  {
    motor[id].write(i);
    delay(20);
    pos[id] = i;
  }
}

void moverBrazoDer(int id)
{
  for (i=pos[id]; i<=180 && analogRead(id) != joystick[id]; i++)
  {
    motor[id].write(i);
    delay(20);
    pos[id] = i;
  }
}

void log(int joystick, int pos, int demora)
{
  Serial.print(joystick);
  Serial.print(":");
  Serial.print(pos);
  Serial.print(" - ");
  Serial.println(demora);
}

void setup()
{ 
  motor[0].attach(11);
  motor[1].attach(10);
  motor[2].attach(9);
  motor[3].attach(5);
  /*motor2.attach(10);
  motor3.attach(9);
  motor4.attach(5);*/
  Serial.begin(9600);
  /*moverBrazo(motor1, 15, 0);
  delay(1000);
  moverBrazo(motor1, 15, 50);
  delay(1000);
  moverBrazo(motor1, 15, 100);
  delay(1000);
  moverBrazo(motor1, 15, 0);
  */
}

void loop()
{
  delay(600);
  if (analogRead(0)<joystick[0])
  {
    moverBrazoIzq(0);
  }
  if (analogRead(0)>joystick[0])
  {
    //int demora = map(analogRead(0), joystick[0], 0, 100, 15);
    //log(0, analogRead(0), demora);
    moverBrazoDer(0);
  }
  //Serial.println(pos[0]);
  /*
  if (analogRead(i)>joystick[i])
  {
    int demora = map(analogRead(i), joystick[i], 1023, 100, 15);
    log(i, analogRead(i), demora);
  }*/
  
}
