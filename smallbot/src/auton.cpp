#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    chassis->setMaxVelocity(250);

    chassis->moveDistance(19_in);
    lilwillmechControlAuton();
    pros::delay(1000);
    chassis->turnAngle(-85_deg);
    pros::delay(1000);
    chassis->setMaxVelocity(350);
    chassis->moveDistance(10_in);
    pros::delay(1000);

    intake();
    chassis->moveDistance(-3_in);
    ramIntoWall();
    
    // chassis->moveDistance(-3_in);
    // ramIntoWall();

    // chassis->moveDistance(-3_in);
    // ramIntoWall();

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
    chassis->turnAngle(-160_deg);
    lilwillmechControlAutonUP();
    chassis->moveDistance(10.5_in);
    pros::delay(1000);
    intake(); 
    chassis->setMaxVelocity(600);
    pros::delay(25000);
}