#pragma once
#include "Weather.h"
class Car
{
protected:
	float fuel_consumption;
	float fuel_capacity;
	float average_speed[3];
public:
	void virtual getname() = 0;
	float virtual Race(float track_lenght, Weather weather) = 0;
};

