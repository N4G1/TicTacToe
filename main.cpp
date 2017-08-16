#pragma once
#include "ControllerSFML.h"


int main()
{
	ControllerSFML controller;

	while (true)
	{
		controller.initialize();
		controller.play();
	}
	return 0;
}