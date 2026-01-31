#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    chassis->setMaxVelocity(415);

    chassis->moveDistance(19.55_in);
    pros::delay(400);
    chassis->turnAngle(80_deg);
    pros::delay(400);
    chassis->moveDistance(12.5_in);
    pros::delay(400);
    score();
    pros::delay(1500);
    intakeStop();
    chassis->moveDistance(-7_in);
    pros::delay(300);
    chassis->turnAngle(-160_deg);
    lilwillmechControlAuton();
    //chassis->turnAngle(-78.5_deg);
    //pros::delay(500);
    pros::delay(300);
    chassis->moveDistance(16.2_in);
    pros::delay(300);

    // chassis->moveDistance(-2_in);
    // pros::delay(10);
    // chassis->moveDistance(3.5_in);
    score();
    //ramIntoWall();
    pros::delay(350);
    
    intakeStop();
    pros::delay(400);

    chassis->moveDistance(-7_in);
    pros::delay(300);
    chassis->turnAngle(-159.0_deg);
    lilwillmechControlAutonUP();
    chassis->moveDistance(12.5_in);
    pros::delay(500);
    score(); 
    chassis->setMaxVelocity(600);
    pros::delay(3000);
    intakeStop();

    chassis->moveDistance(-6_in);
    pros::delay(300);
    chassis->turnAngle(78.5_deg);
    pros::delay(300);
    chassis->moveDistance(16_in);
    pros::delay(300);
    chassis->turnAngle(-78.5_deg);
}