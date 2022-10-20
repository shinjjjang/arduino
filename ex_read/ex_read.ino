void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    if(Serial.available()){
        char onoff = (char) Serial.read();
        int num = (onoff - '0');

        if(num == 1){
            on();
        }
        if(num == 0){
            off();
        }
    }
}

void on(){
    digitalWrite(LED_BUILTIN, HIGH);
}

void off(){
    digitalWrite(LED_BUILTIN, LOW);
}