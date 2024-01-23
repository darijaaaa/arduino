#define readPin A0
int val;
void setup() {
pinMode(9, OUTPUT);
pinMode(6, INPUT);
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); // initialize serial communication:
}

void loop() {

  val = analogRead(readPin);
  Serial.println(val);
  int value = map(val, 0, 1024, 0, 130);

/*if (Serial.available() > 0) {
  val = Serial.parseInt();
  
  Serial.println(val);
  Serial.read();
  }*/
  /*digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);*/
  
analogWrite(9, value);
delay(20);
}
