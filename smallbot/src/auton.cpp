#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    chassis->setMaxVelocity(250);

    chassis->moveDistance(18_in);
    pros::delay(1000);
    chassis->turnAngle(-85_deg);
    pros::delay(1000);
    chassis->moveDistance(10_in);

    //back wall to match loader
    // chassis->moveDistance(1_ft);
    // chassis->turnAngle(-90_deg);
    // chassis->moveDistance(1.5_ft);
    // chassis->turnAngle(-90_deg);
    // chassis->moveDistance(1_ft);

    chassis->setMaxVelocity(600);
    pros::delay(25000);
}