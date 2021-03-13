// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 8 - Problem 3

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Player.h" // include header file
#include "Team.h" // include header file

using namespace std;

//////////////////////////////////// SPLIT FUNCTION ///////////////////////////////////////////////////////////

int split(string sentence, char delim, vector<string>& mySplits) // Write function below
{ 
    string word = ""; // temp string to hold word
    sentence = sentence + delim; // adds delim to end of string in order to pick up last word in sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == delim) // if character at index i = delim
        {
            if (word.length() > 0) // check if word length is greater than 0
            {
                mySplits.push_back(word); // if true, pass word to vector
            }
            word = "";
        }
        else
        {
        word = word + sentence[i]; // if character is not = to delim, word = previous characters + character at index #
        }
    }
}

//////////////////////////////////// IMPLEMENTATION FUNCTIONS ////////////////////////////////////////////////////////////

Team::Team() // default constructor
{
    teamName = ""; // name blank
    vector<Player> players; // empty vector of players
}

Team::Team(string name) // parameterized constructor
{
    teamName = name; // name equals input name
    vector<Player> players; // empty vector of players
}

/* Algorithm: 
   sets teamName equal to parameter input
*/

void Team::setTeamName(string name)
{
    teamName = name; // teamName equals input name
}

/* Algorithm: 
   - Member function that reads a file with the format "player name, player points" and stores into a temp vector
   - Passes the values in the temp vector to a Player variable
   - Passes Player variable into the vector "players" (private variable in "Team" class)
   - Repeats process until all lines in the file have been read
*/

void Team::readRoster(string filename) 
{
    string line = ""; // temp string for reading file
    vector<string> temp_vector; // temp vector to hold splits
    Player temp_player; // temp player variable to pass values from split
    ifstream myfile; // initialize variable of stream type
    myfile.open(filename); // open file specified in function parameter
    if (myfile.is_open()) // check if file opens sucessfully
    {
        while(getline(myfile, line)) // while there are lines to read, do stuff below
        {
            if (line != "") // if line is not empty
            {
                split (line, ',', temp_vector); // split the string with ',' as deliminator
                temp_player.setName(temp_vector[0]); // member function to set player name
                temp_player.setPoints(stod(temp_vector[1])); // member function to set player score
                players.push_back(temp_player); // pass temp_player to players vector
                temp_vector.pop_back(); // get temp_vector back to empty
                temp_vector.pop_back(); // get temp_vector back to empty
            }
        }
    }
}

/* Algorithm: 
   - Returns player name as long as index parameter is within bounds of vector
*/

string Team::getPlayerName(int i)
{
    if (i < players.size())
    {
        return players[i].getName();
    }
    else
    {
        return "ERROR";
    }
}

/* Algorithm: 
   - Returns player score as long as index parameter is within bounds of vector
*/

double Team::getPlayerPoints(int i)
{
    if (i < players.size())
    {
        return players[i].getPoints();
    }
    else
    {
        return -1;
    }
}

/* Algorithm: 
   - Returns size of players vector
*/

int Team::getNumPlayers()
{
    return players.size();
}

/* Algorithm: 
   - Returns teamName
*/

string Team::getTeamName()
{
    return teamName;
}
