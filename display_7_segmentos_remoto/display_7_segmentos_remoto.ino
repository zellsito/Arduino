#include <IRremote.hpp>

const int delayTime = 400;

String keyHexaCode;
const int remoteIn = 9;

const String remoteCodes[10] = 
{
  "3910598400",//0
  "4077715200",//1
  "3877175040",//2
  "2707357440",//3
  "4144561920",//4
  "3810328320",//5
  "2774204160",//6
  "3175284480",//7
  "2907897600",//8
  "3041591040" //9
};

const int digitos[10][7] = {
/*0*/ {1,1,1,1,1,1,0},
/*1*/ {0,1,1,0,0,0,0},
/*2*/ {1,1,0,1,1,0,1},
/*3*/ {1,1,1,1,0,0,1},
/*4*/ {0,1,1,0,0,1,1},
/*5*/ {1,0,1,1,0,1,1},
/*6*/ {1,0,1,1,1,1,1},
/*7*/ {1,1,1,0,0,0,0},
/*8*/ {1,1,1,1,1,1,1},
/*9*/ {1,1,1,1,0,1,1}
};

const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;
 
const int n = 7;
const int segmentos[n] = {A,B,C,D,E,F,G};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(remoteIn, true); 
  for (int i=0; i<n; i++){
    pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], LOW);//apagar
  }
  pinMode(remoteIn, INPUT);
}

void print(int d){
  for (int i=0; i<n; i++){
    digitalWrite(segmentos[i], digitos[d][i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    keyHexaCode = IrReceiver.decodedIRData.decodedRawData;
    for (int i=0; i<10; i++){
      if (remoteCodes[i] == (String) keyHexaCode)
      {
        print(i);
      }
    }
    //IrReceiver.printIRResultShort(&Serial); // optional use new print version
    IrReceiver.resume(); // Enable receiving of the next value
  }
}
