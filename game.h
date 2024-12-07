#include "team.h" //"player.h", <string>, <vector>,<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<unistd.h>



class Game{
	public:
	Game();

	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std:: string players[11];

	Team teamA, teamB;
	Team *battingTeam;
	Team *bowlingTeam;
	Player *batsman,*bowler;
	bool isFirstInnings;
	void welcome();
	void showAllPlayers();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayer(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void showGameScoreCard();
	void swap();
	void startSecondInnings();

	void showMatchSummary();

};
