#include <ESP8266WiFi.h>

String ssid     = "Wifi Luxton 2.4 Ghz";
String password = "kayasindi";

byte cont = 0;
byte max_intentos = 50;

void conectarWifi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED and cont < max_intentos) { //Cuenta hasta 50 si no se puede conectar lo cancela
    cont++;
    delay(500);
    Serial.print(".");
  }

  Serial.println("");

  if (cont < max_intentos) {  //Si se conectó      
      Serial.println("********************************************");
      Serial.print("Conectado a la red WiFi: ");
      Serial.println(WiFi.SSID());
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
      Serial.print("macAdress: ");
      Serial.println(WiFi.macAddress());
      Serial.println("*********************************************");
  }
  else { //No se conectó
      Serial.println("------------------------------------");
      Serial.println("Error de conexion");
      Serial.println("------------------------------------");
  }
}
