//FILE : CommuterTrain.cpp
//PROG : Andrew Bozzelli
//PURP : A simulation of a high speed railway train that travels on a track to 30 stations and ending back on the 1st station.

#include <iostream>
#include <string>
using namespace std;
#include "CommuterTrain.h"

int main()
{
	const int STATIONCOUNT = 30;

	CommuterTrain myTrain(STATIONCOUNT, 200, 1);

	cout << "All aboard the Summerville Express Train!\n";
	myTrain.loadPeople();
	int numStations = myTrain.getNumStations();
	int station = myTrain.getCurrentStation();
	cout << "\n";
	while (station <= numStations)
	{
		myTrain.moveToStation(myTrain.getCurrentStation() + 1);
		myTrain.unloadPeople();
		myTrain.loadPeople();
		station++;
		cout << "\n";
	}
	return 0;
}