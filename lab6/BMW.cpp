#include "BMW.h"
#include <iostream>
BMW::BMW()
{
	fuel_consumption = 11.0;
	fuel_capacity = 200.0;
	average_speed[0] = 70.0;
	average_speed[1] = 60.0;
	average_speed[2] = 40.0;
}
float BMW::Race(float circuit_lenght, Weather weather)
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
void BMW::getname()
{
	std::cout << "BMW" << std::endl;
}