int trig = A0;
int echo = A3;

String dataLabel_1 = "Index";
String dataLabel_2 = "Distance";
bool label = true;

int duration, cm, new_data;
int i = 0;
int threshold = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  cm = microsecondsToCentimeters(duration);

  while (label) {
    Serial.print(dataLabel_1);
    Serial.print(",");
    Serial.println(dataLabel_2);
    label = false;
  }

  if ((new_data >= cm + threshold) || (new_data <= cm - threshold)) {
    Serial.print(i);
    Serial.print(",");
    Serial.println(cm);

    i++;
  }
  
  new_data = cm;
  delay(1000);
}

int microsecondsToCentimeters(int duration) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we take half of the distance travelled.
  return duration / 29 / 2;
}
