const int IR_PIN = 3;
const int LDR_PIN = 4;
// 6 LED pins
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;
const int LED4 = 8;
const int LED5 = 9;
const int LED6 = 10;
void setup() {
pinMode(IR_PIN, INPUT);
pinMode(LDR_PIN, INPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);
Serial.begin(9600);
}
void loop() {
int irValue = digitalRead(IR_PIN);
int ldrValue = digitalRead(LDR_PIN);
Serial.print("LDR: "); Serial.print(ldrValue);
Serial.print(" IR: "); Serial.println(irValue);
if (ldrValue == LOW) {
// Night
if (irValue == LOW) {
// Motion detected → blink ALL LEDs
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, HIGH);
digitalWrite(LED4, HIGH);
digitalWrite(LED5, HIGH);
digitalWrite(LED6, HIGH);
delay(500);
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
digitalWrite(LED5, LOW);
digitalWrite(LED6, LOW);
delay(500);
} else {
// No motion → OFF
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
digitalWrite(LED5, LOW);
digitalWrite(LED6, LOW);
}
} else {
// Day → OFF
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
digitalWrite(LED5, LOW);
digitalWrite(LED6, LOW);
}
}