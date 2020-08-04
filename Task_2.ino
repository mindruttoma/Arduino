int led=6;
char val;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
  val = Serial.read();
    if (val == '1') {
      digitalWrite(led, HIGH);
      Serial.println("ON");
    }
    if (val == '0') {
      digitalWrite(led, LOW);
      Serial.println("OFF");
    }

  }
  
}
