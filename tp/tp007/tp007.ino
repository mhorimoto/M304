void setup(void) {
  Serial.begin(115200);
  Serial3.begin(9600);
}

void loop(void) {
  String lb;
  if (Serial3.available()>0) {
    lb = Serial3.readStringUntil('\n');
    Serial.print(lb);
  }
}
