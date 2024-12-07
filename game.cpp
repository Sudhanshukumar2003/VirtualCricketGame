#include "game.h"  //"team.h", "player.h", <string>, <vector>,<iostream>
using namespace std;


Game :: Game(){

	//selection Squad and Game Details
	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;


	players[0]="Rohit Sharma";
	players[1]="Shubhman Gill";
	players[2]="Virat Kohli";
	players[3]="Shreyas Iyer";
	players[4]="K. Lokesh Rahul";
	players[5]="Hardik Pandya";
	players[6]="Ravindra Jadeja";
	players[7]="Mohammed Shami";
	players[8]="Mohammed Siraj";
	players[9]="Jasprit Bumrah";
	players[10]="Kuldeep Yadav";

	isFirstInnings=false;
	teamA.TeamName="Team-A";
	teamB.TeamName="Team-B";
}
void Game :: welcome(){
	cout<<" ____________________________________________"<<endl;
	cout<<"|                                            |"<<endl;
	cout<<"|===============* CRIC-IN *==================|"<<endl;
	cout<<"|____________________________________________|"<<endl;
	cout<<"|                                            |"<<endl;
	cout<<"|        Welcome To Virtual Cricket Game     |"<<endl;
	cout<<"|        *******************************     |"<<endl;
	cout<<"|____________________________________________|"<<endl;
	cout<<endl<<endl;
	cout<<" ____________________________________________________"<<endl;
	cout<<"|                                                    |"<<endl;
	cout<<"|==================* Instructions *==================|"<<endl;
	cout<<"|____________________________________________________|"<<endl;
	cout<<"|                                                    |"<<endl;
	cout<<"|1. Create 2 Teams (Team-A and Team-B with 4 Players |"<<endl;
	cout<<"|   each) from a given pool of 11 players.           |"<<endl;
	cout<<"|2. Lead The toss and decide the choice of play.     |"<<endl;
	cout<<"|3. Each Innings will Be of 6 balls                  |"<<endl;
	cout<<"|____________________________________________________|"<<endl;
}

void Game :: showAllPlayers(){

	cout<<endl;
	cout<<" ____________________________________________"<<endl;
	cout<<"|                                            |"<<endl;
	cout<<"|============* Pool Of Players *=============|"<<endl;
	cout<<"|____________________________________________|"<<endl;
	cout<<endl;
	cout<<"\t\t _______________________ "<<endl;
	int i=0;

	while (i<11){

		cout<<"\t\t|["<< i <<"] "<<  players[i]<<"\t|"<<endl;
		cout<<"\t\t|_______________________|"<<endl;
		i+=1;
	}
}

int Game :: takeIntegerInput(){

	int n;

	while (!(cin>>n)){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid Input! Please Try again With Valid Integer Input:"<<endl;
		}
	return n;
}
void Game :: selectPlayers(){

	cout<<endl;
	cout<<" _________________________________________ "<<endl;
	cout<<"|                                         |"<<endl;
	cout<<"|====== * Create Team-A and Team-B *======|"<<endl;
	cout<<"|_________________________________________|"<<endl;

	for(int i=0 ; i < playersPerTeam ; i++){

		//Add Player To team A
		teamASelection:
		cout<<endl<<"Select Player "<<i+1<<" of team A: ";

		int playerIndexTeamA = takeIntegerInput();

		if (playerIndexTeamA<0||playerIndexTeamA>10){
			cout<<"Please Select From The Given Players"<<endl;
			goto teamASelection;
		}
		else if(!validateSelectedPlayer(playerIndexTeamA)){
			cout<<"Player Have been Already Selected. Choose Another!"<<endl;
			goto teamASelection;
		}
		else{
			Player teamAPlayer;
			teamAPlayer.id=playerIndexTeamA;
			teamAPlayer.name=players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
		}

		//Add Player To team B
		teamBSelection:
		cout<<endl<<"Select Player "<<i+1<<" of team B: ";

		int playerIndexTeamB = takeIntegerInput();

		if (playerIndexTeamB<0||playerIndexTeamB>10){
			cout<<"Please Select From The Given Players"<<endl;
			goto teamBSelection;
				}
		else if(!validateSelectedPlayer(playerIndexTeamB)){
				cout<<"Player Have been Already Selected. Choose Another!"<<endl;
				goto teamBSelection;
				}
		else{
			Player teamBPlayer;
			teamBPlayer.id=playerIndexTeamB;
			teamBPlayer.name=players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);
		}
	}
}

bool Game :: validateSelectedPlayer(int Index){

	int n;
	vector<Player>players;

	players=teamA.players;
	n=players.size();
	for (int i=0; i<n; i++){
		if(players[i].id==Index){
			return false;
		}
	}
	players=teamB.players;
	n=players.size();
	for (int i=0; i<n; i++){
		if(players[i].id==Index){
				return false;
		}
	}
	return true;
}

void Game :: showTeamPlayers(){

	vector<Player> teamAPlayers=teamA.players;
	vector<Player> teamBPlayers=teamB.players;

	cout<<endl;
	cout<<" ________________________ \t  _______________________"<<endl;
	cout<<"|                        |\t |                       |"<<endl;
	cout<<"|======= *Team A* =======|\t |====== *Team B* =======|"<<endl;
	cout<<"|________________________|\t |_______________________|"<<endl;

	for(int i=0; i<playersPerTeam; i++){
		cout<<"|"<<"["<< i <<"]"<< teamA.players[i].name <<" \t | \t "
		    <<"|"<<"["<< i <<"]"<< teamB.players[i].name <<" \t | \t "<<endl;
	}
	cout<<"|________________________|\t |_______________________|"<<endl<<endl;
}
void Game :: toss(){

	cout<<" _______________________________ "<<endl;
	cout<<"|                               |"<<endl;
	cout<<"|======== *Let's Toss* =========|"<<endl;
	cout<<"|_______________________________|"<<endl<<endl;

	srand(time(NULL));
	int coin=rand()%2; // 0 or 1

	switch(coin){
	case 0:
		cout<<" ________________ "<<endl;
		cout<<"|                |"<<endl;
		cout<<"| Team A Choose: |"<<endl;
		cout<<"|________________|"<<endl;
		cout<<"|                |"<<endl;
		cout<<"|   0:Head       |"<<endl;
		cout<<"|________________|"<<endl;
		cout<<"|                |"<<endl;
		cout<<"|   1:Tail       |"<<endl;
		cout<<"|________________|"<<endl<<endl;
		break;
	case 1:
		cout<<" ________________ "<<endl;
		cout<<"|                |"<<endl;
		cout<<"| Team B Choose: |"<<endl;
		cout<<"|________________|"<<endl;
		cout<<"|                |"<<endl;
		cout<<"|   0:Head       |"<<endl;
		cout<<"|________________|"<<endl;
		cout<<"|                |"<<endl;
		cout<<"|   1:Tail       |"<<endl;
		cout<<"|________________|"<<endl<<endl;
		break;
	}
	choice:
	int choice;
	cin>>choice;
	cout<<endl;
	if (choice==1||choice==0){
		cout<<"|****************************************|"<<endl;
		cout<<"|          Tossing The Coin...           |"<<endl;
		cout<<"|****************************************|"<<endl<<endl;
			sleep(2);

			int randomValue= rand()%2; // 0 or 1

			switch(randomValue){
			case 0:
				cout<<"|****************************************|"<<endl;
				cout<<"|          Team A won The Toss.          |"<<endl;
				cout<<" **************************************** "<<endl<<endl;
				tossChoice(teamA);
				break;
			case 1:
				cout<<"|****************************************|"<<endl;
				cout<<"|          Team B Won the Toss.          |"<<endl;
				cout<<" **************************************** "<<endl<<endl;
				tossChoice(teamB);
				break;
			}
	}
	else{

		cout<<"Invalid Choice. Choose again!"<<endl<<endl;
		cout<<" ________________ "<<endl;
		cout<<"|                |"<<endl;
		cout<<"|   0:Head       |"<<endl;
		cout<<"|________________|"<<endl;
		cout<<"|                |"<<endl;
		cout<<"|   1:Tail       |"<<endl;
		cout<<"|________________|"<<endl<<endl;

		goto choice;
	}

}
void Game::tossChoice (Team tossWinnerTeam){

	cout<<" _____________________________ "<<endl;
	cout<<"|                             |"<<endl;
	cout<<"| *Choose Batting or Bowling* |"<<endl;
	cout<<"|_____________________________|"<<endl;
	cout<<"|                             |"<<endl;
	cout<<"|    Enter 1 For Batting      |"<<endl;
	cout<<"|_____________________________|"<<endl;
	cout<<"|                             |"<<endl;
	cout<<"|    Enter 2 For Bowling      |"<<endl;
	cout<<"|_____________________________|"<<endl<<endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch(tossInput){
		case 1:
			cout<<endl<<tossWinnerTeam.TeamName<<" won the toss and elected"
					" to bat first"<<endl<<endl;
			if(tossWinnerTeam.TeamName.compare("Team-A")==0){//Team A won toss
				battingTeam=&teamA;
				bowlingTeam=&teamB;
			} else{//Team B won Toss
				battingTeam=&teamB;
				bowlingTeam=&teamA;
			}
			break;
		case 2:
			cout<<endl<<tossWinnerTeam.TeamName<<" won the toss and elected "
					"to bowl first"<<endl<<endl;
			if(tossWinnerTeam.TeamName.compare("Team-A")==0){//Team A won toss
							battingTeam=&teamB;
							bowlingTeam=&teamA;
						} else{//Team B won Toss
							battingTeam=&teamA ;
							bowlingTeam=&teamB;
						}
			break;
		default:
            cout<<endl<<"Invalid Input. Please Try Again!"<<endl<<endl;
            tossChoice(tossWinnerTeam);
			break;
		}
}
void Game :: startFirstInnings(){

	cout<<"\t\t|||First Innings Starts|||"<<endl<<endl;

	isFirstInnings=true;

	initializePlayers();
	playInnings();
}
void Game :: initializePlayers(){

	//Choose batsman and Bowler:
	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];

	cout<<battingTeam->TeamName<<"-"<<batsman->name<<" is Batting"<<endl;
	cout<<bowlingTeam->TeamName<<"-"<<bowler->name<<" is Bowling"<<endl;
}
void Game::playInnings() {
	if(isFirstInnings){
		for (int i = 0; i < maxBalls; i++) { // No of balls per over = 6
			cout << "Press Enter to bowl..." << endl;
            getchar();

            cout << "Bowling..." << endl;
            bat();
            if (!validateInningsScore()) {
            	break;
            }
		}
	}else{
		int target = bowlingTeam->totalRunsScored + 1;
		for (int i = 0; i < maxBalls; i++) { // No of balls per over = 6
					cout << "Press Enter to bowl..." << endl;
		            getchar();

		            cout << "Bowling..." << endl;
		            bat();
		            if (!validateInningsScore()) {
		            	break;
		            }
		            if (battingTeam->totalRunsScored >= target) {
		            		            break; // Stop the innings
		            		        }
		}
	}
}
void Game::bat(){

	srand(time(NULL));
	int runsScored=rand()%7;

	//updating batting team and batsman Score
	batsman->runsScored=batsman->runsScored + runsScored;
	battingTeam->totalRunsScored=battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed=batsman->ballsPlayed + 1;

	//updating bowling team and bowler Score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled=bowlingTeam->totalBallsBowled+1;
	bowler->runsGiven=bowler->runsGiven+ runsScored;


	if(runsScored!=0){ //if runsScored=1,2,3,4,5,or 6

		cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<runsScored<<" runs!"<<endl<<endl;
		showGameScoreCard();

	}else{ //else runsScored=0 and the batsman is 'OUT'
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<" It's OUT!"<<endl<<endl;

		battingTeam->wicketsLost= battingTeam->wicketsLost +1;
		bowler->wicketsTaken=bowler->wicketsTaken +1;
		showGameScoreCard();

		int nextPlayerIndex=battingTeam->wicketsLost;
		batsman=&battingTeam->players[nextPlayerIndex];

	}
}
bool Game::validateInningsScore(){

	if(isFirstInnings){

		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){

			cout<<"****************************************************************************************************************"<<endl;
			cout<<"\t\t ||| FIRST INNINGS ENDS |||"<<endl<<endl;

			cout<<battingTeam->TeamName<<" "<<battingTeam->totalRunsScored<<"-"
				<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")"<<endl;

			cout<<bowlingTeam->TeamName<<" needs "<< battingTeam->totalRunsScored + 1
					<<" runs to win the match"<<endl<<endl;
			cout<<"****************************************************************************************************************"<<endl;
			return false;
			}

	}
	else{
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls || battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){

			cout<<"****************************************************************************************************************"<<endl;
			cout<<"\t\t ||| SECOND INNINGS ENDS |||"<<endl<<endl;

			cout<<battingTeam->TeamName<<" "<<battingTeam->totalRunsScored<<"-"
			<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")"<<endl;

			if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored){
				cout<<bowlingTeam->TeamName<<" Won Against "<< battingTeam->TeamName
				<<" by "<<bowlingTeam->totalRunsScored-battingTeam->totalRunsScored<<" runs! "<<endl<<endl;
			}else{
				cout<< battingTeam->TeamName<<" Won Against "<<bowlingTeam->TeamName
				<<" by "<<4 - battingTeam-> wicketsLost<<" wickets! "<<endl<<endl;
			}cout<<"****************************************************************************************************************"<<endl;
		}
	}

	return true;

}
void Game::showGameScoreCard() {
	cout << " ________________________________________________________________________\t" << endl;
	cout << "|                                                                     \t |\t" << endl;
	cout << "| " << battingTeam->TeamName << " <" << battingTeam->totalRunsScored << " -"
	        << battingTeam->wicketsLost << "> (" << bowlingTeam->totalBallsBowled << ") | "
	        << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") | "<<"\t |"
	        << bowler->name << " " << bowler->ballsBowled << "-" << bowler->runsGiven << "-" << bowler->wicketsTaken << "\t | \t" << endl;
	    cout << "|________________________________________________________________________|\t " << endl << endl;
	}
void Game::swap()
{
   Team* temp = battingTeam;
   battingTeam = bowlingTeam;
   bowlingTeam = temp;
   return;
}

void Game::startSecondInnings(){

    cout << "\t\t|||Second Innings Starts|||" << endl << endl;

    isFirstInnings = false;
    swap(); // Swap entire team objects
    initializePlayers();
    playInnings();

}

	void Game::showMatchSummary() {

		cout << "\t\t    ||| MATCH ENDS ||| " << endl << endl;
		cout << "\t\t ||| MATCH SCORECARD ||| " << endl;
		cout << "\t\t *********************** " << endl<<endl;

	    cout << " "<<battingTeam->TeamName << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl<<endl;

	    cout << "|=================================================|" << endl;
	    cout << "| PLAYER \t \t BATTING \t  BOWLING | \t" << endl;

	    for (int j = 0; j < playersPerTeam; j++) {
	    	Player player = battingTeam->players[j];
	    	cout << "|-------------------------------------------------|" << endl;
	    	cout << "| " << "[" << j << "] " << player.name << "  \t "
	        	<< player.runsScored << "(" << player.ballsPlayed << ") \t\t"
				<< player.ballsBowled << "-" << player.runsGiven << "-"
				<< player.wicketsTaken << "\t  | \t" << endl;
	    }
	    cout << "|=================================================|" << endl << endl;

	    cout <<" "<< bowlingTeam->TeamName << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << endl<<endl;

	    cout << "|=================================================|" << endl;
	    cout << "| PLAYER \t \t BATTING \t  BOWLING | \t" << endl;

	    for (int i = 0; i < playersPerTeam; i++) {
	    	Player player = bowlingTeam->players[i];
	        cout << "|-------------------------------------------------|" << endl;
	        cout << "| " << "[" << i << "] " << player.name << "  \t "
	            << player.runsScored << "(" << player.ballsPlayed << ") \t\t"
	            << player.ballsBowled << "-" << player.runsGiven << "-"
				<< player.wicketsTaken << "\t  | \t" << endl;
	    }
	    cout << "|=================================================|" << endl << endl;
	}
