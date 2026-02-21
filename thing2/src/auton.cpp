#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    chassis->setMaxVelocity(350);

    chassis->moveDistance(18_in);
    pros::delay(1000);
    chassis->turnAngle(-77_deg);
    pros::delay(1000);
    chassis->moveDistance(12.5_in);
    pros::delay(1000);
    score();
    pros::delay(1500);
    intakeStop();
    chassis->moveDistance(-7_in);
    pros::delay(1000);
    chassis->turnAngle(-174_deg);
    pros::delay(1000);
    lilwillmechControlAuton();
    chassis->moveDistance(17_in);
    intake();
    pros::delay(1000);
    intakeStop();
    pros::delay(1000);
    chassis->moveDistance(-7_in);
    pros::delay(500);
    chassis->turnAngle(175.5_deg);
    lilwillmechControlAutonUP();
    pros::delay(500);
    chassis->moveDistance(15_in);
    pros::delay(500);
    score();
    pros::delay(500);
    intakeStop();
    pros::delay(25000);
}