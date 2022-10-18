void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
    int delayval = 2000;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayval);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayval);
}