/*CÁTODO COMÚN*/
const int delayTime = 400;
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
  for (int i=0; i<n; i++){
    pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], LOW);//apagar
  }
}

void print(int d){
  for (int i=0; i<n; i++){
    digitalWrite(segmentos[i], digitos[d][i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<10; i++){
    print(i);
    delay(delayTime);// esperar 1000 milisegundos
  }
}
