#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value (max is 128)

int clampDelay = 10;
bool clamp = true;

void intakeControl(){
    // intake control code (for driver control)
    elevatorUpperFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorUpperBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorLowerFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorLowerBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    elevatorUpperFront.move_velocity(0);
    elevatorUpperBack.move_velocity(0);
    elevatorLowerFront.move_velocity(0);
    elevatorLowerBack.move_velocity(0);

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        elevatorUpperFront.move(128);
        elevatorUpperBack.move(128);
        elevatorLowerFront.move(128);
        elevatorLowerBack.move(128);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        elevatorUpperFront.move(-128);
        elevatorUpperBack.move(-128);
        elevatorLowerFront.move(-128);
        elevatorLowerBack.move(-128);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        elevatorUpperFront.move(128);
        elevatorUpperBack.move(-128);
        elevatorLowerFront.move(128);
        elevatorLowerBack.move(128);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        elevatorUpperFront.move(-128);
        elevatorUpperBack.move(128);
        elevatorLowerFront.move(128);
        elevatorLowerBack.move(128);
    } else {
        elevatorUpperFront.move_velocity(0);
        elevatorUpperBack.move_velocity(0);
        elevatorLowerFront.move_velocity(0);
        elevatorLowerBack.move_velocity(0);
    }

}
void intake(){
    
    
}
void score(){
    
    
}