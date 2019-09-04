volatile char dato = 0;
String data = "";
int velocidad = 100;

void setup() {

  Serial.begin(9600);
  
  for(byte i=2; i < 14; i++){
    pinMode(i, 1);  
  }



}

void loop() {

  if (Serial.available()>0){
    dato = Serial.read();

    while(dato == '#'){
      velocidad = Serial.parseInt();
      Serial.println(velocidad);
      delay(1);

      dato=0;
    }

    switch (dato){
      case 'A':
        adelante(velocidad);
        break;

      case 'B':
        atras(velocidad);
        break;

      case 'D':
        giro360d(velocidad);
        break;

      case 'I':
        giro360i(velocidad);
        break;
      /*
      case 'G':
        giro360(velocidad);
        break;
      */
      
      default:
        apagar(0);
        break;




      
    }
    
  }
}


void adelante(byte velocidad){

  analogWrite(6, velocidad); analogWrite(10, velocidad + 20);
  analogWrite(5, velocidad); analogWrite(9, velocidad + 20);
  
  

  digitalWrite(4,1); digitalWrite(11,1);
  digitalWrite(3,1); digitalWrite(12,1);

  digitalWrite(7,0); digitalWrite(8,0);
  digitalWrite(2,0); digitalWrite(13,0);

}



void atras(byte velocidad){
  
  analogWrite(6, velocidad); analogWrite(10, velocidad+20);
  analogWrite(5, velocidad); analogWrite(9, velocidad+20);
  

  digitalWrite(4,0); digitalWrite(11,0);
  digitalWrite(3,0); digitalWrite(12,0);

  digitalWrite(7,1); digitalWrite(8,1);
  digitalWrite(2,1); digitalWrite(13,1);
  
}


void izquierda(byte velocidad){
  
  analogWrite(6, velocidad); analogWrite(10, velocidad);
  analogWrite(5, velocidad); analogWrite(9, velocidad);
  

  digitalWrite(4,0); digitalWrite(11,1);
  digitalWrite(3,0); digitalWrite(12,1);

  digitalWrite(7,0); digitalWrite(8,0);
  digitalWrite(2,0); digitalWrite(13,0);
  
}


void derecha(byte velocidad){
  
  analogWrite(6, velocidad); analogWrite(10, velocidad);
  analogWrite(5, velocidad); analogWrite(9, velocidad);
  

  digitalWrite(4,1); digitalWrite(11,0);
  digitalWrite(3,1); digitalWrite(12,0);

  digitalWrite(7,0); digitalWrite(8,0);
  digitalWrite(2,0); digitalWrite(13,0);
  
}

void giro360d(byte velocidad){
  
  analogWrite(6, velocidad); analogWrite(10, velocidad+20);
  analogWrite(5, velocidad); analogWrite(9, velocidad+20);
  

  digitalWrite(4,1); digitalWrite(11,0);
  digitalWrite(3,1); digitalWrite(12,0);

  digitalWrite(7,0); digitalWrite(8,1);
  digitalWrite(2,0); digitalWrite(13,1);
  
}



void giro360i(byte velocidad){
  
  analogWrite(6, velocidad); analogWrite(10, velocidad+20);
  analogWrite(5, velocidad); analogWrite(9, velocidad+20);
  

  digitalWrite(4,0); digitalWrite(11,1);
  digitalWrite(3,0); digitalWrite(12,1);

  digitalWrite(7,1); digitalWrite(8,0);
  digitalWrite(2,1); digitalWrite(13,0);
  
}

void apagar(byte velocidad){
  
  analogWrite(6, velocidad); analogWrite(10, velocidad);
  analogWrite(5, velocidad); analogWrite(9, velocidad);
  

  digitalWrite(4,0); digitalWrite(11,0);
  digitalWrite(3,0); digitalWrite(12,0);

  digitalWrite(7,0); digitalWrite(8,0);
  digitalWrite(2,0); digitalWrite(13,0);
  
}


void arrancadorSuave(int velMAx){
  
}
