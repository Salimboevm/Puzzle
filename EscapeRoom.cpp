#include "EscapeRoom.h"
using namespace std;

long EscapeRoom::NumOfPuzzles()
{
	cout << "There are: " << puzzleInRooms.size() << " stations" << endl;
	return puzzleInRooms.size();
}

void EscapeRoom::PrintRoomName()
{
	cout << this->name << endl;
}

Puzzle* EscapeRoom::PuzzleExist(string sName)
{
	vector <Puzzle*> ::iterator itStation;
	cout << endl << "Checking in..." << this->name << endl;
	for (itStation = puzzleInRooms.begin(); itStation != puzzleInRooms.end(); ++itStation)
	{

		if ((*itStation)->ReturnRoomName() == sName)
		{
			cout << "Found a match: " << this->name << "-" << (*itStation)->ReturnRoomName() << endl;

			return (*itStation);
		}
	}
	cout << "Found nothing... returning" << endl;
	return nullptr;
}

void EscapeRoom::AddPuzzle(Puzzle* aPuzzle)
{
	if (puzzleInRooms.size() == 0) {
		currentPuzzle = aPuzzle;
	}
	else if (puzzleInRooms.size() > 0) {
		currentPuzzle->LinkPuzzles(aPuzzle);
		currentPuzzle = aPuzzle;
	}
	puzzleInRooms.push_back(aPuzzle);
}

void EscapeRoom::AddExisting(Puzzle* aPuzzle)
{
	if (currentPuzzle) {
		puzzleInRooms.push_back(aPuzzle);
	}
	else
	{
		if (puzzleInRooms.size() == 0) {
			currentPuzzle = aPuzzle;
		}
		else if (puzzleInRooms.size() > 0) {
			currentPuzzle->LinkPuzzles(aPuzzle);
			currentPuzzle = aPuzzle;
		}
	}
}


void EscapeRoom::PrintPuzzleNameList()
{
	return currentPuzzle->PrintPuzzleName();
}

void EscapeRoom::GetPuzzle()
{
	currentPuzzle = puzzleInRooms.front();
	cout << "Have you solved this puzzle?: (Y or N)" << endl;
	currentPuzzle->PrintPuzzleName();
	Next();
}

Puzzle* EscapeRoom::NextPuzzle()
{
	if (current < 7) {
		currentPuzzle = puzzleInRooms.at(Next());
		cout << "Have you solved this puzzle?: (Y or N)" << endl;
		currentPuzzle->PrintPuzzleName();
		return currentPuzzle;
	}
	return nullptr;
}

int EscapeRoom::Next()
{
	return current++;
}


EscapeRoom::EscapeRoom(string name)
{
	this->name = name;
}
