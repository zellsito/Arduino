#include <Ticker.h>

Ticker flipper;

int count = 0;

void flip() {
  int state = digitalRead(LED_BUILTIN);  // get the current state of GPIO1 pin
  digitalWrite(LED_BUILTIN, !state);     // set pin to the opposite state

  ++count;
  // when the counter reaches a certain value, start blinking like crazy
  if (count == 20) { flipper.attach(0.1, flip); }
  // when the counter reaches yet another value, stop blinking
  else if (count == 120) {
    flipper.detach();
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // flip the pin every 0.3s
  flipper.attach(0.3, flip);
}

void loop() {}
