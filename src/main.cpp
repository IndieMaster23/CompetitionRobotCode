#include "main.h"

/*
  This code is the main control for Competition Robot #1
  
  Copyright (c) 2019 Isaac Williams
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
  init
*/

Motor left (-1);
Motor right (2);

MotorGroup arm ({-3, 4});
MotorGroup intake ({-5, 6});

auto chassis = ChassisControllerFactory::create(left, right, AbstractMotor::gearset::green);

Controller controller (ControllerId::master);

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	chassis.moveDistance(450);
	chassis.turnAngle(200);
	chassis.moveDistance(450);
	chassis.turnAngle(100);
}

void opcontrol() {
	while (true) {
		chassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightY));
		
		if (controller.getDigital(ControllerDigital::L2)) {
			arm.moveVoltage(8000);
		}
		else if (controller.getDigital(ControllerDigital::R2)) {
			arm.moveVoltage(-8000);
		}
		else {
			arm.moveVoltage(0);
		}

		if (controller.getDigital(ControllerDigital::L1)) {
			intake.moveVoltage(10000);
		}
		else if (controller.getDigital(ControllerDigital::R1)) {
			intake.moveVoltage(-10000);
		}
		else {
			intake.moveVoltage(0);
		}
		
		pros::Task::delay(2);
	}
}
