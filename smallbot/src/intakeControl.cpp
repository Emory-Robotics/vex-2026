#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value (max is 128)

int clampDelay = 10;
int slowElevator = 1;
bool clamp = true;

void intakeControl(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        if (slowElevator == 1) slowElevator = 0.5;
        else slowElevator = 1;
    }

    // intake control code (for driver control)
    elevatorUpperFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorUpperBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorLowerFrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorLowerFrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorLowerBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    elevatorUpperFront.move_velocity(0);
    elevatorUpperBack.move_velocity(0);
    elevatorLowerFrontLeft.move_velocity(0);
    elevatorLowerFrontRight.move_velocity(0);
    elevatorLowerBack.move_velocity(0);

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        // intake back + output middle
        elevatorUpperFront.move_velocity(-100 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        
        elevatorUpperBack.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(-600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        // output top
        elevatorUpperFront.move_velocity(200 * slowElevator);
        elevatorUpperBack.move_velocity(0);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        // output bottom
        elevatorUpperFront.move_velocity(-200 * slowElevator);
        elevatorUpperBack.move_velocity(-600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(-600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(-600 * slowElevator);
        elevatorLowerBack.move_velocity(-600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        // output back
        elevatorUpperFront.move_velocity(200 * slowElevator);
        elevatorUpperBack.move_velocity(-600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        // output mid
        elevatorUpperFront.move_velocity(-100 * slowElevator);
        elevatorUpperBack.move_velocity(600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(600 * slowElevator);
    } else {
        elevatorUpperFront.move_velocity(0);
        elevatorUpperBack.move_velocity(0);
       elevatorLowerFrontLeft.move_velocity(0);
        elevatorLowerFrontRight.move_velocity(0);
        elevatorLowerBack.move_velocity(0);
    }

}
void intake(){
    
    
}
void score(){
    
    
}