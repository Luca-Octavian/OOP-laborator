#include <iostream>
#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "RangeRover.h"
using namespace std;
int main()
{
	
		Circuit c;
		c.Set_lenght(100);
		c.Set_weather(Weather::Rainy);
		c.AddCar(new Volvo());
		c.AddCar(new BMW());
		c.AddCar(new RangeRover());
		c.Race();
		c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
		c.ShowWhoDidntFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
		return 0;
}