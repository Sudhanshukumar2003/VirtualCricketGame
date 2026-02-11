# Virtual Cricket Game (CRIC-IN)

A console-based virtual cricket game simulation developed in C++. This interactive game allows users to create two teams, play a cricket match, and view detailed match statistics.

## Main Function

The main function orchestrates the entire cricket game flow:
1. Displays a welcome message and game instructions
2. Shows the pool of available players
3. Allows users to select players for both teams
4. Conducts a virtual toss to determine batting/bowling order
5. Plays the first innings
6. Plays the second innings
7. Displays a comprehensive match summary

## Features

### 1. **Team Creation**
- Create two teams (Team-A and Team-B)
- Select 4 players for each team from a pool of 11 international cricket players
- Validation to ensure no player is selected twice

### 2. **Player Pool**
The game includes a roster of famous Indian cricket players:
- Rohit Sharma
- Shubhman Gill
- Virat Kohli
- Shreyas Iyer
- K. Lokesh Rahul
- Hardik Pandya
- Ravindra Jadeja
- Mohammed Shami
- Mohammed Siraj
- Jasprit Bumrah
- Kuldeep Yadav

### 3. **Toss System**
- Random toss simulation
- Winner chooses to bat or bowl first
- Interactive user experience

### 4. **Match Gameplay**
- Each innings consists of 6 balls
- Random run generation (0-6 runs per ball)
- Automatic wicket management
- Real-time score updates after each ball
- Target-based second innings

### 5. **Batting Statistics**
For each player:
- Runs scored
- Balls played
- Strike rate tracking

### 6. **Bowling Statistics**
For each player:
- Balls bowled
- Runs given
- Wickets taken

### 7. **Live Scorecard**
- Real-time display of current score
- Current batsman and bowler statistics
- Team totals and wickets lost

### 8. **Match Summary**
Comprehensive end-of-match statistics including:
- Final scores for both teams
- Individual player performance (batting and bowling)
- Match result with winning margin

### 9. **Interactive Gameplay**
- Press Enter to continue between game phases
- Press Enter to bowl each ball
- User-controlled game pace

## How to Compile and Run

### Prerequisites
- C++ compiler (g++ or equivalent)
- Unix-like environment (for `sleep` and `unistd.h` functions)

### Compilation
```bash
g++ -o virtual-cricket-game virtual-cricket-game.cpp game.cpp player.cpp team.cpp
```

### Running the Game
```bash
./virtual-cricket-game
```

## Game Rules

1. **Team Size**: Each team consists of 4 players
2. **Innings Length**: Each innings is 6 balls long
3. **Scoring**: Each ball can result in 0-6 runs
4. **Wickets**: If 0 runs are scored on a ball, the batsman is out
5. **Winning Conditions**:
   - Team batting second must score more runs than the first team
   - Team batting second has limited wickets (4 players)
   - Match ends when all wickets are lost or target is achieved

## Project Structure

- `virtual-cricket-game.cpp` - Main entry point of the application
- `game.h` / `game.cpp` - Game logic and flow management
- `player.h` / `player.cpp` - Player class definition
- `team.h` / `team.cpp` - Team class definition

## Author

**Sudhanshu Kumar**

## License

Copyright notice as per source code headers.

---

**Enjoy the Virtual Cricket Game!** 🏏
