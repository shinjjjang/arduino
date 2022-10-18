void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
    int delay_time = 50;

    digitalWrite(LED_BUILTIN, HIGH);
    delay(delay_time);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delay_time);
}