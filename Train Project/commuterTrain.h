//FILE : CommuterTrain.h
//PROG : Andrew Bozzelli
//PURP : Train simulator class Thas loads and unloads a train using a random number generator and moves it to the next station.


#include <ctime>	

class CommuterTrain
{
	private:
		int numStations;			
		int maxCapacity;			
		int currentStation;			
		int peopleOnBoard;			
		int destStation;			
		int randnum;


	public:
		CommuterTrain(int, int, int);		
		void moveToStation(int);			
		int genRandNumber(int);				
		int getNumStations();
		int getPeopleOnBoard();
		int getMaxCapacity();
		int getCurrentStation();
		int getDestStation();
		void loadPeople();
		void unloadPeople();
		
};
CommuterTrain::CommuterTrain(int numStops, int maxPersons, int start)
{
	numStations = numStops;
	maxCapacity = maxPersons;
	currentStation = start;
	peopleOnBoard = 0;		

	srand ((unsigned)time(NULL));
}
int CommuterTrain::getNumStations()
{
	return numStations;
}

int CommuterTrain::getCurrentStation()
{
	return currentStation;
}

int CommuterTrain::getMaxCapacity()
{
	return maxCapacity;
}

int CommuterTrain::getDestStation()
{
	return destStation;
}

int CommuterTrain::genRandNumber(int maxNum)
{
	return (rand() % (maxNum + 1));
}

int CommuterTrain::getPeopleOnBoard()
{
	return peopleOnBoard;
}

void CommuterTrain::loadPeople()
{
	
	randnum=rand()%351;
	cout << "People waiting to board: "<<randnum<<endl;
	
	if (randnum > maxCapacity || randnum+peopleOnBoard> maxCapacity)
	{
		
		cout << "People entering: "<<maxCapacity-peopleOnBoard<<endl;
		peopleOnBoard = maxCapacity;
		cout << "Current people on board: "<<peopleOnBoard<<endl;
	}
	
	else
	{
		peopleOnBoard+=randnum;
		cout << "People entering: "<<randnum<<endl;
		cout << "Current people on board: "<<peopleOnBoard<<endl;
	}
	
}

void CommuterTrain::unloadPeople()
{
	randnum = rand()%peopleOnBoard+1;
	cout << "People leaving: "<<randnum<<endl;
	peopleOnBoard-=randnum;
	cout << "Current people on board: "<<peopleOnBoard<<endl;
}

void CommuterTrain::moveToStation(int nextStation)
{
		destStation = nextStation;
		if (destStation > numStations)
		{
			cout << "Now returning to Station 1 with " << peopleOnBoard << " people." << endl;
			destStation = 1;
		}
		else
		{
			
			cout << "Leaving station " << currentStation << " for station "
				<< destStation << " with "
				<< peopleOnBoard  << " people.\n";
		}

		cout << "Made it to station "<<destStation<<endl;
		currentStation = destStation;
}