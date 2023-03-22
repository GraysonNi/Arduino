//Programer: Grayson Nichols
//Date: 3.16.2023
//Program: Blind Spot Monitor
//Resource: https://projecthub.arduino.cc/Krepak/a6ea3ad5-fd23-49c9-a96c-5e6fcf97f2cc?ref=search&ref_id=red%20green%20yellow%20light%20echo%20sensor&offset=1

/*
 * This program will determine distances approaching
 * vehicle that are in your blind spot and turn on warning lights
 */


int trigPin = 7;
int echoPin = 6;
int LEDlampRed = 10;
int LEDlampClear = 11;
int LEDlampBlue = 9; 
int soundbuzzer = 3;
int sound  = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow,  OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void  loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 50) {
      digitalWrite(LEDlampGreen, HIGH);
}
  else {
      digitalWrite(LEDlampGreen,  LOW);
  }
  
  if (distance < 20) {
    digitalWrite(LEDlampYellow,  HIGH);
}
  else {
    digitalWrite(LEDlampYellow,LOW);
  }
  if (distance  < 5) {
    digitalWrite(LEDlampRed, HIGH);
    sound = 1000;
}
  else  {
    digitalWrite(LEDlampRed,LOW);
  }
 
  if (distanceincm > 5 ||  distanceinsm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distance);
    Serial.println("  cm");
    tone(buzzer, sound);
  }
  
  delay(300);
}
