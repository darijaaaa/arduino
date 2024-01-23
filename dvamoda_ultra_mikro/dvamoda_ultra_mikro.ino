#define echo 3
#define trig 2
#define MIC A0
#define led1 4
#define led2 5 
#define led3 6
#define led4 7
#define led5 8 
#define led6 9
#define piezoPin 11
#define buttonPin 12

int val=48;
int sra;
long duration;
int distance;
int sig = 0;
int sigp = 0;
int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void light(long cm){
  int pitch = map(cm, 0, 30, 50, 4000);
  if (cm >= 24){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
  }
  
  else if (cm >= 20){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    for (int i = 0; i < 5; ++i) {
      tone(piezoPin, pitch, 24);
      delay (6);
    }
  }
  
  else if (cm >= 16){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);    
    for (int i = 0; i < 10; ++i) {
      tone(piezoPin, pitch, 20);
      delay (5);
    }
  }
  
  else if (cm >= 12){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
    for (int i = 0; i < 15; ++i) {
      tone(piezoPin, pitch, 16);
      delay (4);
    }
  }
  
   else if (cm >= 8){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);   
    for (int i = 0; i < 20; ++i) {
      tone(piezoPin, pitch, 12);
      delay (3);
      }
   }
  
   else if (cm >= 5){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);  
    for (int i = 0; i < 25; ++i) {
      tone(piezoPin, pitch, 8);
      delay (2);
  }
  }
  
   else {
    digitalWrite(led6, HIGH); 
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH); 
    for (int i = 0; i < 30; ++i) {
      tone(piezoPin, pitch, 5);
      delay (1);
  }
  delay(10);
}
}


void led(int sig){
  if (sig < 55){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
  }
  
  else if (sig < 95){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
  }
  
  else if (sig < 135){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);    
  }
  
  else if (sig < 175){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
  }
  
   else if (sig < 215){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
   }
  
   else if (sig < 255){
    digitalWrite(led6, LOW); 
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
  }
  
   else {
    digitalWrite(led6, HIGH); 
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (Serial.available() > 0){

      sra = Serial.read();
      if(sra == 48 || sra == 49)
        val = sra;
      Serial.read();
    Serial.println(val);
  }*/

  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:

    if (val == 48){
    val = 49;
    
  } 
    else if (val == 49){
    val = 48;
  }
  }

  if (val == 48){
    
    long duration, cm;
    pinMode(trig, OUTPUT);
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    pinMode(echo, INPUT);
    duration = pulseIn(echo, HIGH);
    cm = (duration / 29 / 2);
    //Serial.println(cm);
    light(cm);
    //delay(300);

    //Serial.println("cao");

    
  }

  if (val == 49){
    static int sigp = 0;
    int mx = 0;
    
    // petlja koja odredjuje maksimalnu vrednost od registrovanih 100
    for (int i = 0; i < 100; ++i) {
      sig = analogRead(MIC);     
      mx = max(sig, mx);
  }
    //Serial.println(mx);
      // radi lakseg rada prethodno dobijena maksimalna vrednost signala pomnozena je sa 200
    
    // da bi se izbegao uticaj sumova na paljenje lampica, funkcija led() pozivana kad je razlika izmedju trenutne i prethodne maksimalne vrednosti signala veca od 1800
    if ((abs(mx - sigp) > 36)){
      led(mx);
    }
    // funkcija led() pozivana je kada maksimalne vrednosti signala je jednaka 0, bez obzira na prethodnu vrednost
    else if (mx < 5){
      led(mx);
    }
    else{
      delay(40);
    }
    sigp = mx;
}
}
