//============================================================================
// Name        : virtual-cricket-game.cpp
// Author      : Sudhanshu Kumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"game.h" // "team.h", "player.h", <string>, <vector>,<iostream>
using namespace std;

int main() {

Game game;
	game.welcome();

	cout<<"\nPress Enter To Continue"<<endl;
	getchar();

	game.showAllPlayers();

	cout<<"\nPress Enter To Continue"<<endl;
	getchar();

	game.selectPlayers();

	game.showTeamPlayers();

	cout<<"\nPress Enter To Toss"<<endl;
	getchar();

	game.toss();

	game.startFirstInnings();
	game.startSecondInnings();

	game.showMatchSummary();

	return 0;

}
