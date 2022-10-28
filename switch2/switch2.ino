#define LED_BUILTIN2 12
#define LED_BUILTIN3 11

const int ledPin1 = LED_BUILTIN;
const int ledPin2 = LED_BUILTIN2;
const int ledPin3 = LED_BUILTIN3;

const int inPin1 = A1;
const int inPin2 = A2;
const int inPin3 = A3;

const int debounceTime1 = 20;
const int fastIncrement1 = 1000;
const int veryFastIncrement1 = 4000;
int count1 = 0;

const int debounceTime2 = 20;
const int fastIncrement2 = 1000;
const int veryFastIncrement2 = 4000;
int count2= 0;

const int debounceTime3 = 20;
const int fastIncrement3 = 1000;
const int veryFastIncrement3 = 4000;
int count3 = 0;

void setup(){
    pinMode(inPin1, INPUT_PULLUP);
    pinMode(inPin2, INPUT_PULLUP);
    pinMode(inPin3, INPUT_PULLUP);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    int duration1 = switchTime1();
    int duration2 = switchTime2();
    int duration3 = switchTime3();

    if(duration1 > veryFastIncrement1){
        count1 = count1 + 10;
    }
    else if(duration1 > fastIncrement1){
        count1 = count1 + 4;
    }
    else if(duration1 > debounceTime1){
        count1 = count1 + 1;
    }
    else{
        if(count1 == 0){
            digitalWrite(ledPin1, HIGH);
        }
        else{
            digitalWrite(ledPin1, LOW);
            count1 = count1 - 1;
        }
    }
//    Serial.println(count1);
//    delay(100);

    if(duration2 > veryFastIncrement2){
        count2 = count2 + 10;
    }
    else if(duration2 > fastIncrement2){
        count2 = count2 + 4;
    }
    else if(duration2 > debounceTime2){
        count2 = count2 + 1;
    }
    else{
        if(count2 == 0){
            digitalWrite(ledPin2, HIGH);
        }
        else{
            digitalWrite(ledPin2, LOW);
            count2 = count2 - 1;
        }
    }
//    Serial.println(count2);
//    delay(100);

    if(duration3 > veryFastIncrement3){
        count3 = count3 + 10;
    }
    else if(duration3 > fastIncrement3){
        count3 = count3 + 4;
    }
    else if(duration3 > debounceTime3){
        count3 = count3 + 1;
    }
    else{
        if(count3 == 0){
            digitalWrite(ledPin3, HIGH);
        }
        else{
            digitalWrite(ledPin3, LOW);
            count3 = count3 - 1;
        }
    }
//    Serial.println(count3);
//    delay(100);
    Serial.print(count1);
    Serial.print("  ");
    Serial.print(count2);
    Serial.print("  ");
    Serial.println(count3);
    delay(100);
}

long switchTime1(){
    static unsigned long startTime = 0;
    static bool state;

    if(digitalRead(inPin1) != state){
        state = ! state;
        startTime = millis();
    }

    if(state == LOW){
        return millis() - startTime;
    }
    else{
        return 0;
    }
}

long switchTime2(){
    static unsigned long startTime = 0;
    static bool state;

    if(digitalRead(inPin2) != state){
        state = ! state;
        startTime = millis();
    }

    if(state == LOW){
        return millis() - startTime;
    }
    else{
        return 0;
    }
}

long switchTime3(){
    static unsigned long startTime = 0;
    static bool state;

    if(digitalRead(inPin3) != state){
        state = ! state;
        startTime = millis();
    }

    if(state == LOW){
        return millis() - startTime;
    }
    else{
        return 0;
    }
}