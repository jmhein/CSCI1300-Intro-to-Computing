// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 8 - Problem 2

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>
#include "Player.h" // include header file
using namespace std;

// Implementation file
Player::Player() // default constructor
{
    name = ""; // name blank
    points = 0; // points = 0
}

Player::Player(string playerName, double playerPoints) // parameterized constructor
{
    name = playerName; // name equals input name
    points = playerPoints; // points equals input points
}

string Player::getName()
{
    return name; // return name
}

double Player::getPoints() 
{
    return points; // return points
}

void Player::setName(string playerName)
{
    name = playerName; // name equals input name
}

void Player::setPoints(double playerPoints)
{
    points = playerPoints; // points equals input points
}
