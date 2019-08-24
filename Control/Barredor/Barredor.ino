#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(7, 8); // RX, TX

//Tabla de motores
byte motores[] = {3,5,9,10};
byte pinRGB[] = {13, 11, 6};
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

  for(byte i = 0; i < 3; i++){
    pinMode(pinRGB[i], 1);
  }

}

void loop() {
  Serial.write(dato);
  while(Bluetooth.available()>0){
    dato=Bluetooth.read();
  }

  switch(dato){
    case 'a':
      adelante();
      cambioLedRGB(0,0,255);
      break;
    case 'b':
      atras();
      cambioLedRGB(0,127,127);
      break;
    case 'r':
      derecha();
      cambioLedRGB(255,255,0);
      break;
    case 'l':
      izquierda();
      cambioLedRGB(255,255,0);
      break;
    case 'g':
      gito360Left();
      cambioLedRGB(0,51,102);
      break;
    case 'h':
      gito360Right();
      cambioLedRGB(0,51,102);
      break;
    case 'f':
      frenar();
      cambioLedRGB(255,0,0);
      break;
    default:
      parar();
      cambioLedRGB(255,255,255);
      break;
  }
  
}

void cambioLedRGB(short R, short G, short B){
  analogWrite(pinRGB[0],R);
  analogWrite(pinRGB[1],G);
  analogWrite(pinRGB[2],B);
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
  digitalWrite(motores[1],0);
  digitalWrite(motores[2],1);
  digitalWrite(motores[3],0);
}

void izquierda(){
  digitalWrite(motores[0],1);
  digitalWrite(motores[1],0);
  digitalWrite(motores[2],0);
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
  delay(100);
  dato = 0;
  
}
