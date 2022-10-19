void setup(){
    Serial.begin(9600);
}

void loop(){
    int count = 1;
    for(count; count < 100; count++){
        Serial.println(count);
        delay(1000);
    }
    for(count; count > 1; count--){
        Serial.println(count);
        delay(1000);
    }
}