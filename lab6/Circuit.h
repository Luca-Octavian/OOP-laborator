#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
	int circuit_lenght;
	Weather weather;
	Car* cars[20];
	int car_count;
	bool finished[20];
	float Finish_time[20];
public:
	void Set_weather(Weather weather);
	void Set_lenght(float lenght);
	Circuit();
	~Circuit();
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidntFinish();
};

