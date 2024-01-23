#define laserPin 9
int wait = 100;
int lengthh = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(laserPin, OUTPUT);
  
}



void loop() {
  digitalWrite(laserPin, HIGH);
  int val[7] = {0};
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0){
    }

  String input = Serial.readString();

  for(int i = 0; i < lengthh; i++){
    char k = input.charAt(i);
    if(isPrintable(k))
      val[i] = k;
  }
  
  for(int j=0; j < lengthh; j++){
      Serial.println(val[j]);
    }

  for(int j=0; j < lengthh; j++){

    int jedno = (int)val[j];
    int binaryNum[7] = {0};
    // counter for binary array
    int i = 0;
    while (jedno > 0) {
      // storing remainder in binary array
      binaryNum[i] = jedno % 2;
      jedno = jedno / 2;
      i++;
    }

    //start bit
    digitalWrite(laserPin, LOW);
    delay(wait);

    for(int i = 0; i < 7; i ++){
      if (binaryNum[i] == 1){
        digitalWrite(laserPin, HIGH);
      }
      else{
        digitalWrite(laserPin, LOW);
      }

      Serial.print(binaryNum[i]);
      delay(wait);
    }
    Serial.println();

    digitalWrite(laserPin, HIGH);
    delay(wait);

  }

}
