#include <Servo.h>

#define CLOSEBUTTON_THUMB 2
#define CLOSEBUTTON_REM 3
#define OPENBUTTON 4

#define SERVO_THUMB 5
#define SERVO_REM 6

// Servo position that thumb should stop at when closing entire hand
int thumb_threshold = 30;
// Servo position that remaining fingers should stop at when closing entire hand
int rem_threshold = 30;

// Initialization of control button states
int closebuttonstate_thumb = 0;
int closebuttonstate_rem = 0;
int openbuttonstate = 0;

// Initialization of servo positions
int thumb_pos = 0;
int rem_pos = 0;

// Initialization of servo class instances
Servo thumbServo;
Servo remServo;

void setup() {
    // attach servo class
    thumbServo.attach(SERVO_THUMB);
    remServo.attach(SERVO_REM);
}

void loop() {
    closebuttonstate_thumb = digitalRead(CLOSEBUTTON_THUMB);
    closebuttonstate_rem = digitalRead(CLOSEBUTTON_REM);
    openbuttonstate = digitalRead(OPENBUTTON);

    if (closebuttonstate_thumb == HIGH){
        closeThumb();
    }
    if (closebuttonstate_rem == HIGH){
        closeHand();
    }
    if (openbuttonstate == HIGH){
        openHand();
    }
}

void closeThumb() {
    if (thumb_pos < thumb_threshold) {
        thumbServo.write(thumb_pos);
        thumb_pos += 1;
    }
}

void closeHand() {
    if (thumb_pos < thumb_threshold) {
        thumbServo.write(thumb_pos);
        thumb_pos += 1;
        delay(15);
    }
    if (rem_pos < rem_threshold) {
        remServo.write(rem_pos += 1);
        rem_pos += 1;
        delay(15);
    }
}

void openHand() {
    rem_pos = 0;
    thumb_pos = 0;
    remServo.write(rem_pos);
    thumbServo.write(thumb_pos);
}



// #define FSR_PIN A0
// 
// // Force reading at which thumb should stop squeezing grape
// int fsr_threshold = 30;
// // Data input from force sensor
// int fsrVal = 0;

// void closeHand_full() {
//     thumb_pos = thumb_threshold;
//     rem_pos = rem_threshold;
//     thumbServo.write(thumb_pos);
//     remServo.write(rem_pos);
// }
//    fsrVal = analogRead(FSR_PIN);
//    
