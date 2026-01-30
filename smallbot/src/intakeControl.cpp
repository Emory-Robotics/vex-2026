#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value (max is 128)

int clampDelay = 10;
double slowElevator = 1;
bool clamp = true;
bool check = true;  // persists between function calls

void intakeControl(){

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

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        if (slowElevator == 1) slowElevator = 0.35;
        else slowElevator = 1;
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        // intake back + output middle
        elevatorUpperFront.move_velocity(-100 * slowElevator);
        elevatorHood.move_velocity(200 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        
        elevatorUpperBack.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(-600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        // output top
        elevatorUpperFront.move_velocity(200 * slowElevator);
        elevatorHood.move_velocity(600 * slowElevator);
        elevatorUpperBack.move_velocity(600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        // output bottom
        elevatorUpperFront.move_velocity(-200 * slowElevator);
        elevatorHood.move_velocity(200 * slowElevator);
        elevatorUpperBack.move_velocity(-600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(-600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(-600 * slowElevator);
        elevatorLowerBack.move_velocity(-600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        // output back
        elevatorUpperFront.move_velocity(200 * slowElevator);
        elevatorHood.move_velocity(200 * slowElevator);
        elevatorUpperBack.move_velocity(-600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        // output mid
        elevatorUpperFront.move_velocity(-100 * slowElevator);
        elevatorHood.move_velocity(200 * slowElevator);
        elevatorUpperBack.move_velocity(600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(600 * slowElevator);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        // output mid
        elevatorUpperFront.move_velocity(-100 * slowElevator);
        elevatorHood.move_velocity(200 * slowElevator);
        elevatorUpperBack.move_velocity(600 * slowElevator);
        elevatorLowerFrontLeft.move_velocity(600 * slowElevator);
        elevatorLowerFrontRight.move_velocity(600 * slowElevator);
        elevatorLowerBack.move_velocity(600 * slowElevator);
    } else {
        elevatorUpperFront.move_velocity(0);
        elevatorHood.move_velocity(0);
        elevatorUpperBack.move_velocity(0);
        elevatorLowerFrontLeft.move_velocity(0);
        elevatorLowerFrontRight.move_velocity(0);
        elevatorLowerBack.move_velocity(0);
    }

}
void intake(){
    // output top
        elevatorUpperFront.move_velocity(200);
        //elevatorHood.move_velocity(600);
        elevatorUpperBack.move_velocity(600);
        elevatorLowerFrontLeft.move_velocity(-600);
        elevatorLowerFrontRight.move_velocity(600);
        elevatorLowerBack.move_velocity(600);
}
void intakeStop(){
        elevatorUpperFront.move_velocity(0);
        elevatorHood.move_velocity(0);
        elevatorUpperBack.move_velocity(0);
        elevatorLowerFrontLeft.move_velocity(0);
        elevatorLowerFrontRight.move_velocity(0);
        elevatorLowerBack.move_velocity(0);
}

void lilwillmechControl() {
    lilwillmech.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
        if (check) {
            lilwillmech.move_relative(-300, 100);
        } else {
            lilwillmech.move_relative(300, 100);
        }
        check = !check;  // toggle state
    }
}
void lilwillmechControlAuton() {
    lilwillmech.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    lilwillmech.move_relative(-270, 100);
}
void lilwillmechControlAutonUP() {
    lilwillmech.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    lilwillmech.move_relative(270, 100);
}
void score(){
    elevatorUpperFront.move_velocity(200);
    elevatorHood.move_velocity(600);
    elevatorUpperBack.move_velocity(600);
    elevatorLowerFrontLeft.move_velocity(600);
    elevatorLowerFrontRight.move_velocity(600 );
    elevatorLowerBack.move_velocity(600);
}
void ramIntoWall() {
    left1.move_velocity(150);
    left2.move_velocity(150);
    left3.move_velocity(150);
    left4.move_velocity(150);
    
    right1.move_velocity(-150);
    right2.move_velocity(-150);
    right3.move_velocity(-150);
    right4.move_velocity(-150);

    pros::delay(5);
}
void ramOutWall() {
    left1.move_velocity(-300);
    left2.move_velocity(-300);
    left3.move_velocity(-300);
    left4.move_velocity(-300);
    
    right1.move_velocity(300);
    right2.move_velocity(300);
    right3.move_velocity(300);
    right4.move_velocity(300);

    pros::delay(500);
}
    