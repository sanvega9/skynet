#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); //seed random number generator
	//Sets grid to be 8*8
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	//set to search between 1 & 64 to hold the actual target location
	int actualTargetLocation = rand() % searchGridHighNumber + searchGridLowNumber;

	//int secretNumber = rand() % 64 + 1;// random number between 1 & 64
	int tries = 0;
	//The system target start point
	int attemptToLocateTarget = 0;

	//Title
	cout << "\tWELCOME TO AI DRONE GUESS NUMBER\n\n";
		do
		{
			//This is where the AI makes a target location guess
			cout << "\n The real target location is at " << actualTargetLocation << endl;
			//
			cout << "\n The AI guesses target is at location " << actualTargetLocation << endl;
			attemptToLocateTarget = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
			++tries;
			//if you guess it's too high
			if (attemptToLocateTarget > actualTargetLocation)
			{
				cout << "The AI target prediction was Too high! \n\n";
				searchGridHighNumber = attemptToLocateTarget - 1;
			}
			//if you guess  it's too low
			else if (attemptToLocateTarget < actualTargetLocation)
			{
				cout << "The AI target prediction wasToo low!\n\n";
				searchGridLowNumber = attemptToLocateTarget + 1;
			}
			//
			else
			{
				cout << "\nThat's right! The AI took " <<tries<< " guesses\n";
			}
			//
		} while (attemptToLocateTarget != actualTargetLocation);
		//
		return 0;
}