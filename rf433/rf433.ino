#include <RCSwitch.h>
#define RF_PIN 0

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(RF_PIN);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  delay(50);
  Serial.println( mySwitch.available() );
  if (mySwitch.available()) {
    
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );

    mySwitch.resetAvailable();
  }
}
