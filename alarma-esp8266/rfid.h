#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D8
#define RST_PIN D0

MFRC522 rfid(SS_PIN, RST_PIN);
byte luciano[4] = {0x53, 0x01, 0xE3, 0xA1};

void printHex(byte *buffer) {
 for (byte i = 0; i < 4; i++) {
   Serial.print(buffer[i] < 0x10 ? " 0" : " ");
   Serial.print(buffer[i], HEX);
 }
}

boolean esIgual(byte *id1, byte *id2){
  return (id1[0] == id2[0] &&
     id1[1] == id2[1] &&
     id1[2] == id2[2] &&
     id1[3] == id2[3] );
}

void iniciarRfid() {
 SPI.begin(); // Init SPI bus
 rfid.PCD_Init(); // Init MFRC522
 Serial.print(F("Reader: "));
 rfid.PCD_DumpVersionToSerial();
}

String leerRfid() {
 if ( ! rfid.PICC_IsNewCardPresent()){
   return "No hay tarjeta presente";
 }
   
 if ( ! rfid.PICC_ReadCardSerial()){
   return "No se pudo leer tarjeta";
 }
 
 if (esIgual(luciano, rfid.uid.uidByte)){
   printHex(luciano);
   return "Bienvenido Luciano";
 }

 return "Acceso denegado";

 rfid.PICC_HaltA();
 rfid.PCD_StopCrypto1();
}
