#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

/**
   A player class that tracks player name and points
 */

class Player
{
public:
   Player(); // default constructor
   Player(string playerName, double playerPoints); // parameterized constructor
   string getName();
   double getPoints();
   void setName(string playerName);
   void setPoints(double playerPoints);
   
private:
   string name;
   double points;
};

#endif
