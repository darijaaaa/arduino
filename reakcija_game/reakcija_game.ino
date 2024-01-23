#define button1 2
#define button2 6
#define led1 4 // indikator
#define led2 3 // player 1
#define led3 5 // player 1
int start, sad;
int p1, p2;
int k;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  k = random(7, 12);
  delay(k * 100);
  digitalWrite(led1, HIGH);
  
  p1 = digitalRead(button1);
  p2 = digitalRead(button2);
  while (!(p1 || p2)){
    p1 = digitalRead(button1);
    p2 = digitalRead(button2);
  }
  
  digitalWrite(led1, LOW);
  if ((p1 == 1) && (p2 == 1)){
    int a = random(0, 1);
    if (a == 1){
      digitalWrite(led2, HIGH);
      delay(500);
      digitalWrite(led2, LOW);
    }
    else{
      digitalWrite(led3, HIGH);
      delay(500);
      digitalWrite(led3, LOW);
    }
  }
  else if (p1 == 1){
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
  }
  else{
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
  }

}
