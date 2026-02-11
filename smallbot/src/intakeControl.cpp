#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value (max is 128)

int clampDelay = 10;
bool clamp = true;

void intakeControl(){

    // intake control code (for driver control)

    intakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    armMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intakeMotor.move_velocity(200);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        armMotor.move_velocity(-100);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        armMotor.move_velocity(100);
    } else {
        intakeMotor.move_velocity(0);
        armMotor.move_velocity(0);
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A) && clampDelay <= 0){
        clamp = !clamp;
        clampDelay = 10;
    }

    clampDelay = clampDelay - 1;

    if(clamp){
        armPiston.set_value(true); // extend
    }
    if(!clamp) {
        armPiston.set_value(false); // retract
    }

}

    