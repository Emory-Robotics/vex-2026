#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value
int forward = 0;
int lateral = 0;
int forwardAcc = 5;
int lateralAcc = 50;

void driveControl(){
    // drive train control code (for driver control)
    
    // acceleration
    /*if(forward > master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)){
        int diff = abs(abs(forward) - abs(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)));
        forward -= std::min(forwardAcc, diff);
    }
    if(forward < master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)){
        int diff = abs(abs(forward) - abs(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)));
        forward += std::min(forwardAcc, diff);
    }

    if(lateral > master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)){
        int diff = abs(abs(lateral) - abs(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));
        lateral -= std::min(lateralAcc, diff);
    }
    if(lateral < master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)){
        int diff = abs(abs(lateral) - abs(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));
        lateral += std::min(lateralAcc, diff);
    }*/

    forward = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    lateral = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    int left = forward - lateral;
    int right = - forward - lateral;

    left1.move_velocity(left * 600.0 / 128.0);
	left2.move_velocity(left * 600.0 / 128.0);
    left3.move_velocity(left * 600.0 / 128.0);
    left4.move_velocity(left * 600.0 / 128.0);

	right1.move_velocity(right * 600.0 / 128.0);
	right2.move_velocity(right * 600.0 / 128.0);
    right3.move_velocity(right * 600.0 / 128.0);
    right4.move_velocity(right * 600.0 / 128.0);
    
}