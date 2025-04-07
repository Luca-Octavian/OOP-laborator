#include <iostream>

#include "Circuit.h"
void Circuit::Set_lenght(float lenght)
{
	this->circuit_lenght = lenght;
}
void Circuit::AddCar(Car* car)
{
	if (this->car_count < 20)
	{
		this->cars[car_count] = car;
		car_count++;
	}
}
Circuit::Circuit()
{
	car_count = 0;
	circuit_lenght = 0;
	for (int i = 0;i < 20;i++)
	{
		cars[i] = nullptr;
		finished[i] = 0;
		Finish_time[i] = -1.0;
	}
}
Circuit::~Circuit()
{
	for (int i = 0;i < 20;i++)
	{
		delete cars[i];
	}
}
void Circuit::Race()
{
	for (int i = 0;i < car_count;i++)
	{
		Finish_time[i] = cars[i]->Race(this->circuit_lenght, this->weather);
		if (Finish_time[i] > 0)
		{
			finished[i] = 1;
		}
	}
	for (int i = 0; i < car_count - 1; ++i)
	{

		for (int j = 0; j < car_count - i - 1; ++j)
		{
			if (Finish_time[j] > Finish_time[j + 1] && finished[j] && finished[j + 1])
			{
				std::swap(Finish_time[j], Finish_time[j + 1]);
				std::swap(cars[j], cars[j + 1]);
				std::swap(finished[j], finished[j + 1]);
			}
		}
	}
}
void Circuit::Set_weather(Weather weather)
{
	this->weather = weather;
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0;i < car_count;i++)
	{
		this->cars[i]->getname();
		std::cout << Finish_time[i] << std::endl;
	}
}
void Circuit::ShowWhoDidntFinish()
{
	for (int i = 0;i < car_count;i++)
	{
		if (finished[i] == 0)
		{
			this->cars[i]->getname();
			std::cout << "nu a terminat" << std::endl;
		}
	}
}
