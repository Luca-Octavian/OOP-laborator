#pragma once
#include "Car.h"

class BMW : public Car
{
public:
	BMW();
	void getname();
	float Race(float track_lenght, Weather weather);
};

