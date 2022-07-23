#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 9);     
String state;    
#define trig 2
#define echo 5
                
void setup() {
  bluetooth.begin(9600);               
  Serial.begin(9600);                  
  pinMode(3, OUTPUT);
  digitalWrite(3,HIGH);
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(trig, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echo, INPUT); //a echo, jako wejście
}

void loop() {
  while (bluetooth.available()) {       
    delay(10);                         
    char c = bluetooth.read();        
    state += c;                  
  }
long  czas, dist;
 digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  czas = pulseIn(echo, HIGH);
  dist = czas / 58;
  
  Serial.print(dist);
  Serial.println(" cm");

  if (dist<10) {
      digitalWrite(4, LOW);
        digitalWrite(8, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW); }
     
  if (state.length() > 0 ) {
     Serial.println(state);
analogWrite(3, 200);

    //Petla do jazdy do przudu
    if (state == "jedz") {
      analogWrite(3, 200);
      digitalWrite(4, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);  
  }
      
    
     if (state == "stop") {
      digitalWrite(4, LOW);
        digitalWrite(8, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW); }

    //petla do jazdy do tyłu
    if (state == "tyl") {
     
      digitalWrite(4, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12, LOW); }
     
   if (state == "prawo") { 
    digitalWrite(4, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW); }
    
   if(state == "lewo"){
    digitalWrite(4, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH); } 
     
   state = "";   } 
   }
