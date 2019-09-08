volatile char dato = 0, datoViejo = 0;
String data = "";
int velocidad = 100, T=5, esperaInicial=1500;


unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)


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

    datoViejo = dato;
  }
}


void adelante(byte velocidad){

  if (dato != datoViejo){
    //Para de inicio
    analogWrite(6, 0); analogWrite(10, 0);
    analogWrite(5, 0); analogWrite(9, 0);
    delay(esperaInicial);
    for(int i = 0; i < velocidad; i++ ){

      Serial.println("subiendo...");
      //aumento de velocidad de a un milisegungo      
      analogWrite(6, i); analogWrite(10, i + 20);
      analogWrite(5, i); analogWrite(9, i + 20);
      
    
      digitalWrite(4,1); digitalWrite(11,1);
      digitalWrite(3,1); digitalWrite(12,1);
    
      digitalWrite(7,0); digitalWrite(8,0);
      digitalWrite(2,0); digitalWrite(13,0);

      delay(T);
      
    }
    
  }
  else{

    analogWrite(6, velocidad); analogWrite(10, velocidad + 20);
    analogWrite(5, velocidad); analogWrite(9, velocidad + 20);
    
    
  
    digitalWrite(4,1); digitalWrite(11,1);
    digitalWrite(3,1); digitalWrite(12,1);
  
    digitalWrite(7,0); digitalWrite(8,0);
    digitalWrite(2,0); digitalWrite(13,0);
    
  }
  

}



void atras(byte velocidad){

  if (dato != datoViejo){
    //Para de inicio
    analogWrite(6, 0); analogWrite(10, 0);
    analogWrite(5, 0); analogWrite(9, 0);
    delay(esperaInicial);
    for(int i = 0; i < velocidad; i++ ){
      Serial.println("subiendo...  atras");
      //aumento de velocidad de a un milisegungo      
      analogWrite(6, i); analogWrite(10, i + 20);
      analogWrite(5, i); analogWrite(9, i + 20);

      digitalWrite(4,0); digitalWrite(11,0);
      digitalWrite(3,0); digitalWrite(12,0);

      digitalWrite(7,1); digitalWrite(8,1);
      digitalWrite(2,1); digitalWrite(13,1);

      delay(T);
    }
      
   }
   else{

      analogWrite(6, velocidad); analogWrite(10, velocidad+20);
      analogWrite(5, velocidad); analogWrite(9, velocidad+20);
      
    
      digitalWrite(4,0); digitalWrite(11,0);
      digitalWrite(3,0); digitalWrite(12,0);
    
      digitalWrite(7,1); digitalWrite(8,1);
      digitalWrite(2,1); digitalWrite(13,1);
        
   }
  
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

  if (dato != datoViejo){
    //Para de inicio
//    analogWrite(6, 0); analogWrite(10, 0);
//    analogWrite(5, 0); analogWrite(9, 0);
    delay(esperaInicial);
    for(int i = 0; i < velocidad; i++ ){
       Serial.println("subiendo...  DERECHA");
      analogWrite(6, i); analogWrite(10, i+20);
      analogWrite(5, i); analogWrite(9, i+20);
      
    
      digitalWrite(4,1); digitalWrite(11,0);
      digitalWrite(3,1); digitalWrite(12,0);
    
      digitalWrite(7,0); digitalWrite(8,1);
      digitalWrite(2,0); digitalWrite(13,1);
      delay(T);  
    }
    

  }
  else{

    analogWrite(6, velocidad); analogWrite(10, velocidad+20);
    analogWrite(5, velocidad); analogWrite(9, velocidad+20);
    
  
    digitalWrite(4,1); digitalWrite(11,0);
    digitalWrite(3,1); digitalWrite(12,0);
  
    digitalWrite(7,0); digitalWrite(8,1);
    digitalWrite(2,0); digitalWrite(13,1);
    
  }
  
}



void giro360i(byte velocidad){

  if (dato != datoViejo){
    //Para de inicio
    //analogWrite(6, 0); analogWrite(10, 0);
    //analogWrite(5, 0); analogWrite(9, 0);
    delay(esperaInicial);
    for(int i = 0; i < velocidad; i++ ){
       Serial.println("subiendo...  izquierda");
      analogWrite(6, i); analogWrite(10, i+20);
      analogWrite(5, i); analogWrite(9, i+20);
      
    
      digitalWrite(4,0); digitalWrite(11,1);
      digitalWrite(3,0); digitalWrite(12,1);
    
      digitalWrite(7,1); digitalWrite(8,0);
      digitalWrite(2,1); digitalWrite(13,0);

      delay(T);
    }
    
  }
  else{

      analogWrite(6, velocidad); analogWrite(10, velocidad+20);
      analogWrite(5, velocidad); analogWrite(9, velocidad+20);
      
    
      digitalWrite(4,0); digitalWrite(11,1);
      digitalWrite(3,0); digitalWrite(12,1);
    
      digitalWrite(7,1); digitalWrite(8,0);
      digitalWrite(2,1); digitalWrite(13,0);

      
  }
    
  
}

void apagar(byte velocidad){
  
  analogWrite(6, velocidad); analogWrite(10, velocidad);
  analogWrite(5, velocidad); analogWrite(9, velocidad);
  

  digitalWrite(4,0); digitalWrite(11,0);
  digitalWrite(3,0); digitalWrite(12,0);

  digitalWrite(7,0); digitalWrite(8,0);
  digitalWrite(2,0); digitalWrite(13,0);
  
}


void arrancadorSuave(int velMAx, int intervalo){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= intervalo) {
    // save the last time you blinked the LED
    
  }
    
}
