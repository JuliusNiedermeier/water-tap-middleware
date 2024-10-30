bool open = false;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  Serial.println("valve_state, open_signal, close_signal");
}

void loop() {
  bool positivePin = digitalRead(2);
  bool negativePin = digitalRead(3);

  if(positivePin == HIGH) {
    open = true;
  }

  if(negativePin == HIGH) {
    open = false;
  }
  
  Serial.print(open);
  Serial.print(" ");
  
  Serial.print(positivePin);
  Serial.print(" ");
  
  Serial.println(negativePin);
}
