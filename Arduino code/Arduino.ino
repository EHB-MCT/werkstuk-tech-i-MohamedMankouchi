// Plaats van de pins
const int trigPin = 9;
const int echoPin = 10;
const int alarm = 11;
const int ledlamp = 13;


// Variabelen
long duration;
int Afstandinccm;
int Afstand;

// Initialisatie pins
void setup() {
pinMode(alarm, OUTPUT);
pinMode(ledlamp, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600);

}


void loop() {
// Trigpin leeg maken
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Trig pin triggeren of actief maken voor 10sec
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Gaat de signaal lezen en een pulse maken
duration = pulseIn(echoPin, HIGH);

// Formule voor de afstand in cm
Afstandinccm= duration*0.034/2;

Afstand = Afstandinccm;

if (Afstand < 10){
  tone(alarm,500);
  digitalWrite(ledlamp, HIGH);
  delay(40);

  noTone(alarm);
  digitalWrite(ledlamp, LOW);
  delay(40);

}
else{
  noTone(alarm);
  digitalWrite(ledlamp, LOW);
}

if (Afstand < 20){
  tone(alarm,500);
  digitalWrite(ledlamp, HIGH);
  delay(130);

  noTone(alarm);
  digitalWrite(ledlamp, LOW);
  delay(130);
  }

else{
  noTone(alarm);
  digitalWrite(ledlamp, LOW);
}

if (Afstand < 40){
  digitalWrite(ledlamp, HIGH);
}
else{
  noTone(alarm);
  digitalWrite(ledlamp, LOW);
}
}
