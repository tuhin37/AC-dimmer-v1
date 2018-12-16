#include "globals.h"
#include "config.h"
#include "TimerOne.h"

uint8_t intencity;
uint8_t del;

void setup() {
    Serial.begin(9600);

    pinMode(TRIGG_PIN, OUTPUT);
    delay(10000);

    attachInterrupt(digitalPinToInterrupt(2), count, RISING);
    
    Timer1.initialize(1000); //1ms interrupt
    Timer1.attachInterrupt(timerCallback);
}


void loop() {
    
}


void count() {
    del=0;
}

void timerCallback() {
    del++;
    if(del>=intencity) {
        digitalWrite(TRIGG_PIN, HIGH);
    }
    else {
        digitalWrite(TRIGG_PIN, LOW);
    }
}




void serialEvent() {
    while (Serial.available()) {
        intencity = Serial.parseInt();
    }

    Serial.print("New intencity value: ");
    Serial.println(intencity);
}