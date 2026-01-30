#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    chassis->setMaxVelocity(350);

    chassis->moveDistance(19.55_in);
    lilwillmechControlAuton();
    intake();
    pros::delay(500);
    intakeStop();
    chassis->turnAngle(-78_deg);
    pros::delay(500);
    chassis->moveDistance(10.5_in);
    pros::delay(500);

    intake();
    chassis->moveDistance(-1.5_in);
    pros::delay(10);
    chassis->moveDistance(1.85_in);
    //ramIntoWall();
    pros::delay(300);
    
    // chassis->moveDistance(-3_in);
    //ramIntoWall();

    // chassis->moveDistance(-3_in);
    // ramIntoWall();
    //pros::delay(2000);
    intakeStop();
    

    // intake();
    // chassis->moveDistance(-3_in);
    // chassis->moveDistance(3_in);
    // chassis->moveDistance(-3_in);
    // chassis->moveDistance(3_in);
    // chassis->moveDistance(-3_in);
    // chassis->moveDistance(3_in);
    // intakeStop();
    pros::delay(2000);

    chassis->moveDistance(-7_in);
    pros::delay(1000);
    chassis->turnAngle(-157_deg);
    lilwillmechControlAutonUP();
    chassis->moveDistance(11.7_in);
    pros::delay(1000);
    score(); 
    chassis->setMaxVelocity(600);
    pros::delay(1000);
    intakeStop();
    // chassis->moveDistance(-3_in);
    // pros::delay(500);
    // chassis->moveDistance(-3_in);
    // pros::delay(500);
    // score();
    // pros::delay(1000);
    // intakeStop();
}