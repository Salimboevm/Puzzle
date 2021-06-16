#include "Puzzle.h"
#include <iostream>

using namespace std;
Puzzle::Puzzle(string name)
{
	this->name = name;
}

void Puzzle::LinkPuzzles(Puzzle* frontPz)
{
	next.push_back(frontPz);
}

void Puzzle::PrintPuzzleName()
{
	cout << name << endl;
}

string Puzzle::ReturnRoomName()
{
	return name;
}

