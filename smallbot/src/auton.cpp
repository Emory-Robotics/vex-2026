#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    chassis->setMaxVelocity(280);

    chassis->turnAngle(-90_deg);
    pros::delay(2000);
    chassis->turnAngle(90_deg);
    pros::delay(2000);
    chassis->turnAngle(-90_deg);

    //back wall to match loader
    // chassis->moveDistance(1_ft);
    // chassis->turnAngle(-90_deg);
    // chassis->moveDistance(1.5_ft);
    // chassis->turnAngle(-90_deg);
    // chassis->moveDistance(1_ft);

    chassis->setMaxVelocity(600);
    pros::delay(25000);
}