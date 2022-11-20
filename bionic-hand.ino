#include <Servo.h>

#define CLOSEBUTTON_PARTIAL 3
#define CLOSEBUTTON_FULL 4
#define OPENBUTTON 2

#define SERVO_INDEX 5
#define SERVO_REM 6

#define FSR_PIN A0

// Force reading at which index/thumb should stop squeezing grape
int fsr_threshold = ;

// Servo position that index/thumb should stop at when closing entire hand
int index_full_threshold = ;
// Servo position that remaining three fingers should stop at when closing entire hand
int rem_full_threshold = ;

// Initialization of control button states
int closebuttonstate_partial = 0;
int closebuttonstate_full = 0;
int openbuttonstate = 0;

// Initialization of servo positions
int index_pos = 0;
int rem_pos = 0;

// Initialization of servo class instances
Servo indexServo;
Servo remServo;

void setup() {
    // attach servo class
    indexServo.attach(SERVO_INDEX);
    remServo.attach(SERVO_REM);

    // Start serial output for debugging purposes
    Serial.begin(9600);
}

void loop() {
    closebuttonstate_partial = digitalRead(CLOSEBUTTON_PARTIAL);
    closebuttonstate_full = digitalRead(CLOSEBUTTON_FULL);
    openbuttonstate = digitalRead(OPENBUTTON);

    fsrVal = analogRead(FSR_PIN);
    
    if (closebuttonstate_partial == HIGH){
        closeHand_partial();
    }
    if (closebuttonstate_full == HIGH){
        closeHand_partial();
    }
    if (openbuttonstate == HIGH){
        openHand();
    }
}

void closeHand_partial() {
    while (fsrVal < fsr_threshold) {
        indexServo.write(index_pos);
        index_pos += 1;
    }
}

void closeHand_full() {
    index_pos = index_full_threshold;
    rem_pos = rem_full_threshold;
    indexServo.write(index_pos);
    remServo.write(rem_pos);
}

void openHand() {
    rem_pos = 0;
    index_pos = 0;
    remServo.write(rem_pos);
    indexServo.write(index_pos);
}
