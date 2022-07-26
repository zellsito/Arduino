#include <RCSwitch.h>
#define RF_PIN D2

RCSwitch mySwitch = RCSwitch();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // Inicia Serial
  Serial.begin(115200);
  mySwitch.enableReceive(RF_PIN);
  Serial.println("\n");
  conectarWifi();
}

// the loop function runs over and over again forever
void loop() {
  delay(50);
  if (mySwitch.available()) {
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );
    enviarMensaje("ALARMA ACTIVADA");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
