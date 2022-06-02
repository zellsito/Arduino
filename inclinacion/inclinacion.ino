#define pinLED 2
#define pinTILT 12

int statusTILT = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinTILT, INPUT);
  digitalWrite(pinTILT,HIGH);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:  
  statusTILT = digitalRead(pinTILT);
  Serial.println(statusTILT);
  if (statusTILT == HIGH)
  {
    Serial.println("led");
    digitalWrite(pinLED, HIGH);
  }
  else
  {
    Serial.println("noled");
    digitalWrite(pinLED, LOW);
  }
    
  delay(200);
}
