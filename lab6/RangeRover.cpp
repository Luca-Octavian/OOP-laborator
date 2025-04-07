#include "RangeRover.h"
#include <iostream>
RangeRover::RangeRover()
{
	fuel_consumption = 20.0;
	fuel_capacity = 160.0;
	average_speed[0] = 100.0;
	average_speed[1] = 90.0;
	average_speed[2] = 90.0;
}
float RangeRover::Race(float circuit_lenght, Weather weather)
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
void RangeRover::getname()
{
	std::cout << "RangeRover" << std::endl;
}