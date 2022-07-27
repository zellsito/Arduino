#include "rf.h"
#include "wifi.h"


// #define SENSOR_PIN D5
// #define LED_PIN D1
#define ESPERA 10 //en segundos



bool isEncendida = false;

void setup() {
  Serial.begin(115200);
  initRf();
  initWifi();
  /*iniciarRfid();*/
  
}

// the loop function runs over and over again forever
void loop() {
  listenRf();
//  enviarMensaje("Bienvenido a casa");
  /*if(leerRfid().indexOf("Bienvenido") > 0){
    Serial.print(respuestaRfid);
  }*/
  
  /*if (leerRfid()){
    isEncendida = !isEncendida;
    digitalWrite(LED_BUILTIN, !isEncendida);
    if (!isEncendida){
      enviarMensaje("Bienvenido a casa");
    } else {
      enviarMensaje("Adiós! Tenes " + String(ESPERA) + " segundos para salir");
    }
  }*/


  
  /*
  if ((mySwitch.available()) && isEncendida) {
    for (int i = 0; i < ESPERA && isEncendida; i++) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
    if (isEncendida){
      enviarMensaje("ALARMA ACTIVADA");
    }
    while(isEncendida){
      if (leerRfid()){
        isEncendida = false;
      }
      //alarmaSonando();    
    }
    //alarmaDesactivada();
  }*/
}
