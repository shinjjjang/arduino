int blinkDelay = 0;

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    if(Serial.available()){
        char ch = (char) Serial.read();
        if(isDigit(ch)){
            blinkDelay = (ch - '0');
            blinkDelay = blinkDelay * 100;
        }
    }
    blink();
}

void blink(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(blinkDelay);
    digitalWrite(LED_BUILTIN, LOW);
    delay(blinkDelay);
}