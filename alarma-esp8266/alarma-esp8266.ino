#include <RCSwitch.h>
#include "wifi.h"
#include "send.h"
#include "rfid.h"
#define RF_PIN D2
// #define SENSOR_PIN D5
// #define LED_PIN D1
#define ESPERA 10 //en segundos


bool isEncendida = false;

RCSwitch mySwitch = RCSwitch();

void setup() {
  //pinMode(SENSOR_PIN, OUTPUT);
  // Inicia Serial
  Serial.begin(115200);
  mySwitch.enableReceive(RF_PIN);
  conectarWifi();
  //iniciarRfid();
  //enviarMensaje("Bienvenido a casa");
}

// the loop function runs over and over again forever
void loop() {
  delay(50);
  
  
  if (leerRfid()){
    isEncendida = !isEncendida;
    digitalWrite(LED_BUILTIN, !isEncendida);
    if (!isEncendida){
      enviarMensaje("Bienvenido a casa");
    } else {
      enviarMensaje("Adiós! Tenes " + String(ESPERA) + " segundos para salir");
    }
  }
  
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
  }
}
