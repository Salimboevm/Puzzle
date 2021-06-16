#pragma once
#include<iostream>
#include<stdio.h>
#include<list>
#include<string>

using namespace std;

class Puzzle
{
protected:
	string name;

	list<Puzzle*> next;
public:
	Puzzle(string name);
	void LinkPuzzles(Puzzle* frontPz);
	void PrintPuzzleName();
	string ReturnRoomName();

};

