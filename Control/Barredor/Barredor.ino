#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2, 3); // RX, TX

//Tabla de motores
byte motores[] = {5,6,9,10};

//Recepción de Datos
volatile char dato=0;
int valoresEnteros;


void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  //Volver a los los pines salidas motores
  for(byte i = 0; i < 4; i++){
    pinMode(motores[i], 1);
  }


}

void loop() {
  Serial.println(dato);
  while(Serial.available()>0){
    dato=Serial.read();
  }

  switch(dato){
    case 'a':
      adelante();
      break;
    case 'a':
      atras();
      break;
    case 'a':
      derecha();
      break;
    case 'a':
      izquierda();
      break;
    case 'a':
      gito360Left();
      break;
    case 'a':
      gito360Right();
      break;
    case 'a':
      frenar();
      break;
    default:
      parar()
      break;
  }
  
}

void cambioLedRGB(short R, short G, short B){
  analogWrite(13,R);
  analogWrite(12,G);
  analogWrite(11,B);
}


void adelante(){
  digitalWrite(motores[0],1);
  digitalWrite(motores[1],0);
  digitalWrite(motores[2],1);
  digitalWrite(motores[3],0);
}

void atras(){
  digitalWrite(motores[0],0);
  digitalWrite(motores[1],1);
  digitalWrite(motores[2],0);
  digitalWrite(motores[3],1);
}

void derecha(){
  digitalWrite(motores[0],0);
  digitalWrite(motores[1],1);
  digitalWrite(motores[2],0);
  digitalWrite(motores[3],0);
}

void izquierda(){
  digitalWrite(motores[0],0);
  digitalWrite(motores[1],0);
  digitalWrite(motores[2],1);
  digitalWrite(motores[3],0);
}

void gito360Left(){
  digitalWrite(motores[0],1);
  digitalWrite(motores[1],0);
  digitalWrite(motores[2],0);
  digitalWrite(motores[3],1);
}

void gito360Right(){
  digitalWrite(motores[0],0);
  digitalWrite(motores[1],1);
  digitalWrite(motores[2],1);
  digitalWrite(motores[3],0);
}


void parar(){
  digitalWrite(motores[0],0);
  digitalWrite(motores[1],0);
  digitalWrite(motores[2],0);
  digitalWrite(motores[3],0);
}


void frenar(){
  digitalWrite(motores[0],1);
  digitalWrite(motores[1],1);
  digitalWrite(motores[2],1);
  digitalWrite(motores[3],1);
}
