
#include <Servo.h>
Servo motor[4];
Servo motorcin;
int pos[4];
//int velocidad = 100; //grados por segundo (20-180)
int retraso = 20;
/*const int joystickDefault[4] = {
  510, //X L3
  496, //Y L3 <1021
  504, //Y R3
  509  //X R3
};*/

bool estaEnElCentro(int id) {
  return analogRead(id) <= 550 && analogRead(id) >= 450;
}

/*float calcularRetraso(int id, bool der) {
  float diferencia = der ? 180-posicionActual[id] : posicionActual[id];
  Serial.println(diferencia);
  Serial.println(velocidad);
  float duracion = (diferencia/velocidad);
  Serial.println(duracion);
  float duracionMs = duracion*1000;
  Serial.println(duracionMs);
  return duracionMs / diferencia;
}*/

void moverBrazoDer(int id) {
  //float retraso = calcularRetraso(id, false);
  for (int i = pos[id]; i >= 0 && !estaEnElCentro(id) ; i--) {
    motor[id].write(i);
    log(id, i);
    delay(retraso);
    pos[id] = i;
  }
}



void moverBrazoIzq(int id) {
  //float retraso = calcularRetraso(id, true);
  for (int i = pos[id]; i <= 180 && !estaEnElCentro(id); i++) {
    motor[id].write(i);
    log(id, i);
    delay(retraso);
    pos[id] = i;
  }
}



void log(int joystick, int pos) {
  Serial.print(joystick);
  Serial.print(":");
  Serial.print(pos);
  Serial.println("");
}


void setup() {
  motor[0].attach(11);
  motor[1].attach(10);
  motor[2].attach(9);
  motor[3].attach(5);
  Serial.begin(9600);
    
}

/**
 * Devuelve la posicion del joystick
 * @return int
 */
int posicionJoystick(int id) {
  return analogRead(id);
}

/**
 * Se fija si esta movido el joystick, y mueve el servo
 * asociado en la direccion correspondiente
 */
void moverBrazo(int id) {
  if (posicionJoystick(id) < 450) {
    moverBrazoIzq(id);
  }
  
  if (posicionJoystick(id) > 550) {
    moverBrazoDer(id);
  }
}

/**
 * Devuelve el id maximo que puede tener un joystick
 */
int maxIdJoystick() {
  return (sizeof(pos) / sizeof(int))-1;
}

void loop()
{
  delay(200);
  for (int j = 0; j <= maxIdJoystick(); j++) {
    moverBrazo(j);
    delay(200);
  }
  
}
