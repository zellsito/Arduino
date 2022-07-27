#include <RCSwitch.h>
#define RF_PIN D2
#include "send.h"

RCSwitch mySwitch = RCSwitch();

const int codPuertaPrincipalAbierta = 6407539;
const int codPuertaPrincipalCerrada = 6407545;

const int codPuertaTraseraAbierta = 4838515;
const int codPuertaTraseraCerrada = 4838521;

void initRf(){
  mySwitch.enableReceive(RF_PIN);
}

void debugRf(){
  Serial.print("Received ");
  Serial.print( mySwitch.getReceivedValue() );
  Serial.print(" / ");
  Serial.print( mySwitch.getReceivedBitlength() );
  Serial.print("bit ");
  Serial.print("Protocol: ");
  Serial.println( mySwitch.getReceivedProtocol() );
  mySwitch.resetAvailable();
}

void listenRf(){
  if (mySwitch.available()) {
    const long int value = mySwitch.getReceivedValue();
    String msg = "No se reconoce RF";
    switch (value){
      case codPuertaPrincipalAbierta:
        msg = "Puerta principal abierta";
        break;
      case codPuertaPrincipalCerrada:
        msg = "Puerta principal cerrada";
        break;
      case codPuertaTraseraAbierta:
        msg = "Puerta trasera abierta";
        break;
      case codPuertaTraseraCerrada:
        msg = "Puerta trasera cerrada";
        break;
    }
    //debugRf();
    Serial.println(msg);
    enviarMensaje(msg);
    mySwitch.resetAvailable();
  }
}
