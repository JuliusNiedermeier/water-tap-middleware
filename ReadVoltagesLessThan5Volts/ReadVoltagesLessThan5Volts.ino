#define cellPin A0

const float mvc = 5.03 / 1024 * 1000;
const int scaleFactor = 2;

float counts = 0;
float mv = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  counts = analogRead(cellPin);
  //Serial.println(String(counts));

  mv = counts * mvc;
  Serial.println(String(mv * scaleFactor));
}
