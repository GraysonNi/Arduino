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
  pinMode(LEDlampClear,  OUTPUT);
  pinMode(LEDlampBlue, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void  loop() {
  long durationindigit, distanceinft;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceinft = (durationindigit/5) / 29.1;

  if (distanceinft > 10){
    Serial.println("We have not detected any vehical in your Blind Spot - Change lanes when needed.");
  }


  if (distanceinft <= 10 && distanceinft >= 7){
    digitalWrite(LEDlampBlue, HIGH);
    Serial.println("There is another car within");
    Serial.print(distanceinft);
    Serial.println(" feet from your Blind Spot \nGetting Close - Change Lanes with Caution\n");
  }
  else {
    digitalWrite(LEDlampBlue, LOW);
  }

  
  delay(1000);
}
