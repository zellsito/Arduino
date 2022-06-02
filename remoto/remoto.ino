#include <IRremote.hpp>
int IR_RECEIVE_PIN = 9;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, true); // Start the receiver
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    //IrReceiver.printIRResultShort(&Serial); // optional use new print version
    IrReceiver.resume(); // Enable receiving of the next value
  }
}
