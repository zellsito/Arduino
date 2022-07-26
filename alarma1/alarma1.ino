#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>


#define RST_PIN 8
#define SS_PIN 10

const int pinBuzzer = 9;

bool isEncendida = false;

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(7,6,5,4,3,2);

byte LecturaUID[4];
byte Usuario1[4]= {0xFC, 0xA2, 0x54, 0x64};
byte Usuario2[4]= {0x06, 0x76, 0x25, 0xD9};


void setup()
{
  Serial.begin(9600);   
  lcd.begin(16,2);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Listo");

}

void bip(){
  tone(pinBuzzer, 1000, 100);
}
void bip2(){
  tone(pinBuzzer, 1000, 100);
  delay(200);
  tone(pinBuzzer, 1000, 100);
}

void msgBienvenida(){
  lcd.setCursor(0,0);
  lcd.print("   Bienvenida   ");
  lcd.setCursor(0,1);
  lcd.print("     JOHANA     ");
}

void msgDespedida(){
  lcd.setCursor(0,0);
  lcd.print("      Byee      ");
  lcd.setCursor(0,1);
  lcd.print("     JOHANA     ");
}

void loop()
{
  if (!mfrc522.PICC_IsNewCardPresent()
  || !mfrc522.PICC_ReadCardSerial()){
    return;
  }
  Serial.print("UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10){
      Serial.print(" 0");
    } else {
      Serial.print(" ");
    }
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    LecturaUID[i]=mfrc522.uid.uidByte[i];
  }
  Serial.print("\t");
  if(comparaUID(LecturaUID, Usuario1)){
    if (!isEncendida){
      msgBienvenida();
      bip();
    } else {
      msgDespedida();
      bip2();
    }
    isEncendida = !isEncendida;
    delay(1200);
    lcd.clear(); 
      
  } else {
    Serial.println("No te conozco");
  }
  mfrc522.PICC_HaltA();
}

boolean comparaUID(byte lectura[],byte usuario[])
{
  for (byte i=0; i < mfrc522.uid.size; i++){
    return lectura[i] == usuario[i];
  }
}
