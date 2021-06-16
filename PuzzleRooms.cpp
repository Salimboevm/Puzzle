#include <iostream>
#include <fstream>
#include <ostream>
#include<vector>
#include "EscapeRoom.h"
using namespace std;

vector<EscapeRoom*>myRooms;//lines to iterate
EscapeRoom* tempRoom;//temp escaperooms
Puzzle* tempPuzzle;//temp puzzle class
bool quit;//boolean to control quit
Puzzle* CheckStations(string newPuzzle);
void ReadFiles();//function to read files 
void OpenRooms();//function to open rooms
void Options();//function to main menu
int main()
{
    quit = false;
    char userInput;//input from user
    do {
        Options();//options menu
        cin >> userInput;//take input
        
        switch (userInput)
        {
        case '1'://option 1 to open menu
            ReadFiles();//read files
            OpenRooms();//open rooms
            break;
        case '2'://option 2 to quit
            quit = true;
        default:
            break;
        }
    } while (!quit);
    return 0;
}
void Options() {
    system("CLS");//clean console
    //welcome text and menu
    cout << "Welcome to Escape Room Puzzles" << endl;
    cout << "Please choose one of this: " << endl;
    cout << "1.Read Files and Opening Rooms" << endl;
    cout << "2.Quit" << endl;
}
///function to check puzzle
Puzzle* CheckStations(string newStation)
{
    vector <EscapeRoom*> ::iterator itEscapeRooms;//iterator for rooms
    Puzzle* tempPzl = nullptr;//temp puzzle
    for (itEscapeRooms = myRooms.begin(); itEscapeRooms != myRooms.end(); ++itEscapeRooms) {//itate through added rooms
        tempPzl = (*itEscapeRooms)->PuzzleExist(newStation);//if existing room add it to existing 
        if (tempPzl != nullptr) {//check for puzzle
            return tempPzl;//return it
        }
    }
    return nullptr;//if puzzles are empty return nothing
}
///function to read files and adding puzzles and rooms
void ReadFiles()
{
    string line = "";//string for writing and reading

    string path[]{//filepath to read from
        "YellowRoom.txt",
        "RedRoom.txt"
    };

    vector<EscapeRoom*>::iterator itEscapeRoom;//iterator to loop escaperooms

#pragma region ReadFiles
    for (auto i : path)//read from path
    {
        ifstream inFile(i);//infile to read
        if (inFile) {//check infile is not null
            while (getline(inFile, line, ':'))//read
            {
                tempRoom = new EscapeRoom(line);//create room
                myRooms.push_back(tempRoom);//add it to the vector

                cout << endl << "Adding Line: " << line << endl;//add line
                while (getline(inFile, line, ',')) {//add line
                    if (myRooms.size() <= 1) {//check this line is new
                        tempPuzzle = new Puzzle(line);//make new puzzle
                        tempRoom->AddPuzzle(tempPuzzle);//add this room to it`s line
                        cout << "  Adding: " << line << endl;//print to console 

                    }
                    else {//if not
                        Puzzle* tempSt = CheckStations(line);//check puzzle
                        if (!tempSt) {//check it is not exist
                            tempPuzzle = new Puzzle(line);//add new puzzle
                            tempRoom->AddPuzzle(tempPuzzle);//add room to station
                            cout << "  Station is: " << line << endl;//print it to console
                        }
                        else {//if puzzle exists
                            tempRoom->AddExisting(tempSt);//do not make new
                        }
                    }
                }
            }
        }
        else {//if cannot open file print it to the console
            cout << "could not open the file" << endl;
        }
        inFile.close();//close file
    }
    cout << "Printing rooms: " << endl;//print added rooms to console
    for (itEscapeRoom = myRooms.begin(); itEscapeRoom != myRooms.end(); itEscapeRoom++)//iterate through created rooms
    {
        (*itEscapeRoom)->PrintRoomName();//print room name to console
    }
#pragma endregion
}
///function to open and solve puzzles and rooms
void OpenRooms()
{
    bool done = false;//boolean to control reading and solving puzzles
#pragma region Opening Rooms
    tempRoom = myRooms.at(0);//current escape room
    int temp = 0;//temproray solved puzzles num
    int* tPointer = &temp;//pointer to point solved puzzles num
    int tempRooms = 0;//temp solved rooms
    int* tPointerRooms = &tempRooms;//pointer to point temp solved rooms
    cout << endl;//gap
    cout << "Press any key to Open first Room" << endl;
    char userChoice;//user input 
    cin >> userChoice;//take user input
    system("CLS");//clear console
    tempRoom->PrintRoomName();
    cout << endl;
    tempRoom->GetPuzzle();//get current puzzle
    do {//loop it 
        if (*tPointer == 6) {//all puzzles solved?
            tempRooms++;//increase temp solved rooms
            if (*tPointerRooms > 1) {//all rooms solved?
                done = true;//finish loop
                break;//leave from it
            }
            system("CLS");//clear console
            cout << "Opening Red Room" << endl;
            tempRoom = myRooms.at(1);//open next room
            tempRoom->PrintRoomName();//print room name
            temp = 0;//make solved puzzles to zero
            tempRoom->NextPuzzle();//print next puzzle

        }
        cin >> userChoice;//get user input
        switch (userChoice)//from user input 
        {
        case 'y'://if solved
            tempRoom->NextPuzzle();//call next puzzle
            temp++;//increase tmp solved puzzles
            break;//leave switch statement
        case 'n'://if no
            //loop until yes           
            cout << "Please solve it to continue." << endl;
            cout << "Have you solved this puzzle?: (Y or N)" << endl;
            tempRoom->PrintPuzzleNameList();
            break;
        }

    } while (!done);//condition to check to finish loop

    cout << "Congratulations you are solved all of the puzzles" << endl;
    cout << endl;
    ///give options to quit or go back
    cout << "Press q to go quit or press any key to go back: " << endl;
    cin >> userChoice;
    switch (userChoice)
    {
        case 'q':
            quit = true;
            break;
    default:
        main();
        break;
    }
#pragma endregion
}
