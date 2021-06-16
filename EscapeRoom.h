#pragma once
#include<stdio.h>
#include <string>
#include<iostream>
#include <vector>
#include "Puzzle.h"

using namespace std;
class EscapeRoom
{
private:
	string name;
	vector<Puzzle*> puzzleInRooms;
	Puzzle* currentPuzzle = nullptr;
	int current;
public:
	long NumOfPuzzles();
	void PrintRoomName();
	Puzzle* PuzzleExist(string sName);
	void AddPuzzle(Puzzle* aPuzzle);
	void AddExisting(Puzzle* aPuzzle);
	void PrintPuzzleNameList();
	void GetPuzzle();
	Puzzle* NextPuzzle();
	int Next();

	EscapeRoom(string name);
};

