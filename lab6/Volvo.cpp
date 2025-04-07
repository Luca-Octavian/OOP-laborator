#include "Volvo.h"
#include <iostream>
Volvo::Volvo()
{
	fuel_consumption = 15.0;
	fuel_capacity = 150.0;
	average_speed[0] = 75.0;
	average_speed[1] = 85.0;
	average_speed[2] = 50.0;
}
float Volvo::Race(float circuit_lenght ,Weather weather)
{
	int index = (int)weather;
	float required = (circuit_lenght * fuel_consumption);
	if (required > fuel_capacity)
	{
		return -1;
	}
	float finish_time = circuit_lenght / average_speed[index];
	return finish_time;
}
void Volvo::getname()
{
	std::cout << "Volvo" << std::endl;
}