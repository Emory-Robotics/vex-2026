#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor left1(2, pros::E_MOTOR_GEARSET_06);
pros::Motor left2(-3, pros::E_MOTOR_GEARSET_06);
pros::Motor left3(4, pros::E_MOTOR_GEARSET_06);
pros::Motor left4(-5, pros::E_MOTOR_GEARSET_06);


pros::Motor right1(11, pros::E_MOTOR_GEARSET_06);
pros::Motor right2(-12, pros::E_MOTOR_GEARSET_06);
pros::Motor right3(13, pros::E_MOTOR_GEARSET_06);
pros::Motor right4(-14, pros::E_MOTOR_GEARSET_06);


pros::Motor elevatorLowerFrontLeft(20, pros::E_MOTOR_GEARSET_06);
pros::Motor elevatorLowerBack(-19, pros::E_MOTOR_GEARSET_06);
pros::Motor elevatorUpperFront(18, pros::E_MOTOR_GEARSET_18);
pros::Motor elevatorUpperBack(17, pros::E_MOTOR_GEARSET_06);
pros::Motor elevatorLowerFrontRight(-16, pros::E_MOTOR_GEARSET_06);


std::shared_ptr<OdomChassisController> chassis =
      ChassisControllerBuilder()
        .withMotors({2, -3, 4, -5}, {11, -12, 13, -14})
        // Blue gearset, 4 in in wheel diam, 26 cm in wheel track
        .withDimensions({AbstractMotor::gearset::blue, (84.0 / 36.0)}, {{4_in, 13.5_in}, imev5BlueTPR})
        /*.withSensors(
          RotationSensor{16, true}, // Left encoder in V5 port 16 (reversed, the rotation sensors are flipped)
          RotationSensor{6}  // Right encoder in V5 port 6
        )
    		.withOdometry({{4_in, 12.25_in}, quadEncoderTPR})*/
        .withOdometry()
        .withGains(
            {0.001, 0.0000001, 0.00001},
            {0.0015, 0.000001, 0.00002},
            {0.001, 0.0000001, 0.00001}
          )
        /*.withDerivativeFilters(
            std::make_unique<AverageFilter<3>>(), // Distance controller filter
            std::make_unique<AverageFilter<3>>(), // Turn controller filter
            std::make_unique<AverageFilter<3>>()  // Angle controller filter
          )*/
        .withLogger(
            std::make_shared<Logger>(
                TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
                "/ser/sout", // Output to the PROS terminal
                Logger::LogLevel::debug // Most verbose log level
            )
          )
        //.withClosedLoopControllerTimeUtil(50, 5, 250_ms)
    		.buildOdometry();
