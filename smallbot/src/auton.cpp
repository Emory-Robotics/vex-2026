#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code - 0.91ft ish = 2 ft

    //wingPiston.set_value(true);
    lilWillPiston.set_value(true);

    chassis -> moveDistance(1.13_ft);
    chassis -> turnAngle(-85_deg);
    //lilwillmechControl();
    chassis -> moveDistance(0.7_ft);
    chassis -> moveDistance(-0.1_ft);
    intake();
    chassis -> moveDistance(0.2_ft);
    chassis -> moveDistance(-0.2_ft);
    intake();
    chassis -> moveDistance(0.2_ft);
    chassis -> moveDistance(-0.2_ft);
    intake();
    chassis -> moveDistance(-0.91_ft);

    armPiston.set_value(true);
    intake();
    armUp();
    armDown();


}