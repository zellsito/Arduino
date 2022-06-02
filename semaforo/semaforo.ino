/*************/
/*  SEMAFORO */
/*************/

//** Definiciones **//
int rojo=2;      //definimos el valor del pin para el led rojo
int amarillo=3;  //definimos el valor del pin para el led amarillo
int verde=4;     //definimos el valor del pin para el led verde

//** Programa **//

void setup() {
  pinMode(verde,OUTPUT);   //declaramos el pin verde como salida  
  pinMode(amarillo,OUTPUT);//declaramos el pin amarillo como salida
  pinMode(rojo,OUTPUT);    //declaramos el pin rojo como salida  
}

void loop() {
 digitalWrite(verde,HIGH); //encendemos el led rojo
 delay(2000);             //esperamos 2 segundos
 digitalWrite(verde,LOW);  //apagamos el led rojo
 
 digitalWrite(amarillo,HIGH); //encendemos el led amarillo
 delay(500);                 //esperamos 2 segundos
 digitalWrite(amarillo,LOW);  //apagamos el led amarillo
 
 digitalWrite(rojo,HIGH); //encendemos el led verde
 delay(2000);              //esperamos 2 segundos
 digitalWrite(rojo,LOW);  //apagamos el led verde

 digitalWrite(amarillo,HIGH); //encendemos el led amarillo
 delay(500);                 //esperamos 2 segundos
 digitalWrite(amarillo,LOW);  //apagamos el led amarillo

}
