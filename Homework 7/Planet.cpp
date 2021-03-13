// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 1

/* Algorithm: 
    1) Implementation file - default constructor sets plantName to "" and planetRadius to 0
    2) Parameterized constructor - input string name and double radius, set each equal to planetName and planetRaius, respectively
    3) setName function - sets input string equal to planetName
    4) setRadius function - sets input double equal to planetRadius
    5) getName function - returns planetName
    6) getRadius function - returns planetRadius
    7) getVolume function - returns volum of a planet using planetRadius and formual for volume of a sphere (4/3 * pi * r^3)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Planet.h"
using namespace std;

// Implementation file
Planet::Planet() // default constructor
{
    planetName = ""; // planet name blank
    planetRadius = 0.0; // planet radius 0
}

Planet::Planet(string name, double radius)
{
    planetName = name; // planet name = input string name
    planetRadius = radius; // planet radius = input double radius
}

void Planet::setName(string name)
{
    planetName = name; // planet name = input string name
}

void Planet::setRadius(double radius)
{
    planetRadius = radius; // planet radius = input double radius
}

string Planet::getName()
{
    return planetName; // return planet name
}

double Planet::getRadius()
{
    return planetRadius; // return planet radius
}

double Planet::getVolume()
{
    double volume = (4 * M_PI * pow(planetRadius, 3))/3; // calculates volume of a sphere
    return volume; // return volume
}