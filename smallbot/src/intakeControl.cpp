#include "main.h"
#define max_analog 128 //maximum analog signal, used for scaling when driver input exceeds said value (max is 128)


int clampDelay = 10;
int wingDelay = 10;
int lilWillDelay = 10;
bool clamp = true;
bool wing = true;
bool lilWill = true;

void intakeControl(){

    // intake control code (for driver control)

    intakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    armMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    armMotor2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intakeMotor.move_velocity(200);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intakeMotor.move_velocity(-200);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && (clamp == true)){
        armMotor.move_velocity(65);
        armMotor2.move_velocity(65);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && (clamp == false)){
        armMotor.move_velocity(65);
        armMotor2.move_velocity(65);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        armMotor.move_velocity(-75);
        armMotor2.move_velocity(-75);
    }
    else {
        intakeMotor.move_velocity(0);
        armMotor.move_velocity(0);
        armMotor2.move_velocity(0);
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A) && clampDelay <= 0){
        clamp = !clamp;
        clampDelay = 10;
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && wingDelay <= 0){
        wing = !wing;
        wingDelay = 10;
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && lilWillDelay <= 0){
        lilWill = !lilWill;
        lilWillDelay = 10;
    }


    clampDelay = clampDelay - 1;

    if(clamp){
        armPiston.set_value(true); // extend
    }
    if(!clamp) {
        armPiston.set_value(false); // retract
    }

    wingDelay = wingDelay - 1;

    if(wing){
        wingPiston.set_value(true); // extend
    }
    if(!wing) {
        wingPiston.set_value(false); // retract
    }

    lilWillDelay = lilWillDelay - 1;

    if(lilWill){
        lilWillPiston.set_value(true); // extend
    }
    if(!lilWill) {
        lilWillPiston.set_value(false); // retract
    }
}
void score(){
    armMotor.move_velocity(100);
    armMotor2.move_velocity(100);
    pros::delay(1000);
}
void intake(){
    intakeMotor.move_velocity(200);
}
void lilwillmechControl(){
    lilWillPiston.set_value(false);
}
void armUp() {
    armMotor2.move_velocity(60);
    armMotor.move_velocity(60);
    pros::delay(1500);
    armMotor2.move_velocity(0);
    armMotor.move_velocity(0);
}
void autonArmUp() {
    armMotor2.move_velocity(40);
    armMotor.move_velocity(40);
    pros::delay(1500);
    armMotor2.move_velocity(0);
    armMotor.move_velocity(0);
}
void armDown() {
    armMotor2.move_velocity(-100);
    armMotor.move_velocity(-100);
    pros::delay(1000);
    armMotor2.move_velocity(0);
    armMotor.move_velocity(0);
}