const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  LED_BUILTIN;
const int gr = 6;
const int rd = 5;
const int bl = 3;// the number of the LED pin

// variables will change:
int buttonState = 0;  
int ledstate = 0;
int br = 0;
// variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(gr, OUTPUT);
  pinMode(bl, OUTPUT);
  pinMode(rd, OUTPUT);
}

void pali(int br){
  if (br == 0){
    digitalWrite(gr, LOW);
    digitalWrite(bl, LOW);
    digitalWrite(rd, LOW);
  }
  else if (br == 1){
    digitalWrite(gr, LOW);
    digitalWrite(bl, HIGH);
    digitalWrite(rd, LOW);
  }
  else if (br == 2){
    digitalWrite(gr, LOW);
    digitalWrite(bl, HIGH);
    digitalWrite(rd, HIGH);
  }
  else if (br == 3){
    digitalWrite(gr, LOW);
    digitalWrite(bl, LOW);
    digitalWrite(rd, HIGH);
  }
  else if (br == 4){
    digitalWrite(gr, HIGH);
    digitalWrite(bl, LOW);
    digitalWrite(rd, LOW);
  }
  else if (br == 5){
    digitalWrite(gr, HIGH);
    digitalWrite(bl, LOW);
    digitalWrite(rd, HIGH);
  }
  else if (br == 6){
    digitalWrite(gr, HIGH);
    digitalWrite(bl, HIGH);
    digitalWrite(rd, HIGH);
  }
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:

    if (ledstate == LOW){
    digitalWrite(ledPin, HIGH);
    ledstate = HIGH;
    br += 1;
    
  } 
    else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    ledstate = LOW;
    br += 1;
  }

  if (br > 6){
    br = 0;
  }

  pali(br);

  
  delay(300);
}
}
