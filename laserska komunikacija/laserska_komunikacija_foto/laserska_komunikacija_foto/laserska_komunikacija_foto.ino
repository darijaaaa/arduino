#define sensorPin A1
int wait = 100;
int lengthh = 6;
String rec;
int n = 0;

void setup() {
  rec = String("");
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);

}

int binaryListToDecimal(int binary[], int lengthh) {
    int decimal_num = 0;
    int base = 1;
    int binary_num;

    for (int i = 0; i < lengthh; i++) {
        binary_num = binary[i];
        decimal_num += binary_num * base;
        //Serial.println(decimal_num);
        base = base * 2;
        }
     

    return decimal_num;
}


void loop() {
  if (analogRead(sensorPin) <= 200){
    delay(wait);
    int value[7] = {0};
    int i;
    for(i = 0; i < 7; i++){
      int input = analogRead(sensorPin);
      if (input >= 700){
        value[i] = 1;
      }
      else if(input <= 200){
        value[i] = 0;
      }
      delay(wait);
      Serial.print(value[i]);
    }
    Serial.println();

    
    char jedan = binaryListToDecimal(value, 7);
    
    rec += jedan;
    n ++;
    Serial.println(n);
    if (n >= lengthh){
      Serial.println(rec);
      n = 0;
      rec = String("");
    }
  }
}
