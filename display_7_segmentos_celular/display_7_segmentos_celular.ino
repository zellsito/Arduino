
void setup()
{ 
  pinMode(4,OUTPUT); //led rojo
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char dato = Serial.read();
    if(dato=='1')
    {      
      digitalWrite(4,HIGH);
    }
  }
}
