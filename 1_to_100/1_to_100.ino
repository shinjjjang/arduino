int countPlus = 1;
int countMinus = 100;

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    numCountPlus();
}

void numCountPlus(){
    
    if(countPlus > 0 && countPlus < 100){
        Serial.println(countPlus);
        countPlus++;
        if(Serial.available()){
        String onoff = Serial.readString();
    
        if(onoff == "1"){
            digitalWrite(LED_BUILTIN, HIGH);
        }
        if(onoff == "0"){
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
        delay(100);
    }
    if(countPlus == 100){
        numRcountMinus();
    }
    if(countMinus == 1){
        countPlus = 1;
        countMinus = 100;
    }
}

void numRcountMinus(){
    if(countPlus == 100 && countMinus > 1)
    {
        Serial.println(countMinus);
        countMinus--;
        delay(100);
    }
}
