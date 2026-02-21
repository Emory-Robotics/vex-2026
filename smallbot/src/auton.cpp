#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code - 0.91ft ish = 2 ft

    wingPiston.set_value(true);
    //lilWillPiston.set_value(true);

    chassis -> moveDistance(1.4_ft);
    chassis -> turnAngle(-75_deg);
    //lilwillmechControl();
    chassis -> moveDistance(0.91_ft);
    chassis -> moveDistance(-0.1_ft);
    intake();
    chassis -> moveDistance(0.2_ft);
    chassis -> moveDistance(-0.2_ft);
    intake();
    chassis -> moveDistance(0.2_ft);
    chassis -> moveDistance(-0.2_ft);
    intake();
    chassis -> moveDistance(-0.45_ft);

    intake();
    armUp();
    armDown();


}