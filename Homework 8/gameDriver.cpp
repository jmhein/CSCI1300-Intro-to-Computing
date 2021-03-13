// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 8 - Problem 4

/* Algorithm: 
   1) Set variables to hold team 1 and team 2 totals, and a string for the winner
   2) Check that both teams have 4 or more players - winner = "forfeit" if false
   3) Sum the points of the first four players from each team using for loop and "getPlayerPoints" member function
   4) If team1 total > team2 total - winner equals team1 (use "getTeamName" member function)
   5) Else if team2 toatl > team1 total - winner equals team2 (use "getTeamName" mamber function)
   6) Else winner equals "draw"
   7) return winner
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>
#include "Player.h"
#include "Team.h"
using namespace std;

string game(Team team1, Team team2);

int main()
{
   // test1
   // expected output:
   // The winner is: Wisconsinites
   Team team1("Wisconsinites");
   team1.readRoster("roster1.txt");
   Team team2("San Diegons");
   team2.readRoster("roster2.txt");
   string winner = game(team1, team2);
   cout << "The winner is: " << winner << endl;
   
   // test1
   // expected output:
   // The winner is: forefit
   Team team3("Frankensteins");
   team3.readRoster("roster3.txt");
   Team team4("Gibronis");
   team4.readRoster("roster1.txt");
   string winner2 = game(team3, team4);
   cout << "The winner is: " << winner2 << endl;
}

string game(Team team1, Team team2)
{
   double team1Total = 0.0; // variable for team1 total
   double team2Total = 0.0; // varialbe for team2 total
   string winner = ""; // string to hold winner
   if (team1.getNumPlayers() >= 4 && team2.getNumPlayers() >= 4) // check that both players have 4 or more players
   {
      for (int i = 0; i < 4; i++) // if so, sum player score from first 4 players
      {
         team1Total = team1Total + team1.getPlayerPoints(i);
         team2Total = team2Total + team2.getPlayerPoints(i);
      }
      if (team1Total > team2Total) // if team 1 has highest score - winner is team1
      {
         winner = team1.getTeamName(); // team member function getTeamName
      }
      else if (team2Total > team1Total) // if team 2 has highest score - winner is team2
      {
         winner = team2.getTeamName(); // team member function getTeamName
      }
      else // otherwise it is a draw
      {
         winner = "draw";
      }
   }
   else
   {
      winner = "forfeit";
   }
   return winner; // return the winner
}