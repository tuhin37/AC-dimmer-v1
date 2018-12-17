#include "globals.h"
#include "config.h"
#include "TimerOne.h"

uint8_t intencity;
uint8_t del;

void setup() {
    Serial.begin(9600);

    pinMode(TRIGG_PIN, OUTPUT);
    //Timer1.initialize(1000); //1ms interrupt
    //Timer1.attachInterrupt(timerCallback);
    digitalWrite(TRIGG_PIN, HIGH);

    attachInterrupt(digitalPinToInterrupt(2), count, RISING);
}


void loop() {
    
}


void count() {
    digitalWrite(TRIGG_PIN, LOW);
    delayMicroseconds(100*intencity);
    digitalWrite(TRIGG_PIN, HIGH);
}

// void timerCallback() {
//     del++;
//     if(del>=intencity) {
//         digitalWrite(TRIGG_PIN, HIGH);
//     }
//     else {
//         digitalWrite(TRIGG_PIN, LOW);
//     }
// }




void serialEvent() {
    while (Serial.available()) {
        intencity = Serial.parseInt();
    }

    Serial.print("New intencity value: ");
    Serial.println(intencity);
}