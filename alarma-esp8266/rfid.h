#include <SPI.h>      // incluye libreria bus SPI
#include <MFRC522.h>      // incluye libreria especifica para MFRC522

#define RST_PIN  D0      // constante para referenciar pin de reset
#define SS_PIN  D8      // constante para referenciar pin de slave select

byte LecturaUID[4];
byte usuario[4]= {0x53, 0x01, 0xE3, 0xA1};

MFRC522 mfrc522(SS_PIN, RST_PIN); // crea objeto mfrc522 enviando pines de slave select y reset

void iniciarRfid() {
  SPI.begin();        // inicializa bus SPI
  mfrc522.PCD_Init();     // inicializa modulo lector
}

boolean comparaUID()
{
  boolean esIgual = true;
  for (byte i=0; i < mfrc522.uid.size; i++){
    if (LecturaUID[i] != usuario[i]){
      esIgual = false;
    }
  }
  return esIgual;
}

boolean leerRfid()
{
  if (!mfrc522.PICC_IsNewCardPresent()
  || !mfrc522.PICC_ReadCardSerial()){
    return false;
  }
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    LecturaUID[i]=mfrc522.uid.uidByte[i];
  }
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.println(LecturaUID[i]);
  }
  mfrc522.PICC_HaltA();
  return comparaUID();
}
