#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include "Player.h" // include header file
using namespace std;

/**
   A team class that holds players names and associated scores in a vector of players,
 */

class Team
{
public:
   Team(); // default constructor
   Team(string name); // parameterized constructor
   void setTeamName(string name);
   void readRoster(string filename);
   string getPlayerName(int i);
   double getPlayerPoints(int i);
   int getNumPlayers();
   string getTeamName();
   
private:
   string teamName;
   vector<Player> players;
};

#endif
