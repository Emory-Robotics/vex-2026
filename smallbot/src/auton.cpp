#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code - 0.91ft ish = 2 ft

    wingPiston.set_value(false);
    armPiston.set_value(false);
    //lilWillPiston.set_value(true);

    // chassis -> moveDistance(1.4_ft);
    // chassis -> turnAngle(75_deg);
    // //lilwillmechControl();
    // chassis -> moveDistance(0.91_ft);
    // chassis -> moveDistance(-0.1_ft);
    // intake();
    // chassis -> moveDistance(0.2_ft);
    // chassis -> moveDistance(-0.2_ft);
    // intake();
    // chassis -> moveDistance(0.2_ft);
    // chassis -> moveDistance(-0.2_ft);
    // intake();
    // chassis -> moveDistance(-0.45_ft);

    chassis -> moveDistance(-1.3_ft);
    chassis -> turnAngle(-38_deg);
    chassis -> moveDistance(-0.15_ft);

    intake();
    armUp();
    pros::delay(500);
    armDown();
    intakeMotor.move_velocity(0);
    chassis -> moveDistance(0.8_ft);
    chassis -> turnAngle(-142_deg);
}