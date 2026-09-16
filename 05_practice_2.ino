#define PIN_LED 7
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  count = toggle = 0;
  digitalWrite(PIN_LED, toggle); // turn on LED.
}

void loop() {
  delay(1000); // wait for 1,000 miliseconds
  for (int i = 1; i<=10; i++){
    toggle = toggle_state(toggle); //toggle LED value.
    delay(100);
    digitalWrite(PIN_LED, toggle); //update LED status.
  }
  while(1){
    digitalWrite(PIN_LED, 1);
  }
}

int toggle_state(int toggle) {
  ++toggle;
  if (toggle > 1) {
    toggle = 0;
  }
  return toggle;
}
