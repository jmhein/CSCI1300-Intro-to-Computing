#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

/**
   A planet class that tracks the name and radius of a planet, and calculates the volume of planets based on its radius
 */
class Planet
{
public:
   Planet(); // default constructor
   Planet(string name, double radius); // parameterized constructor
   void setName(string name);
   void setRadius(double radius);
   string getName();
   double getRadius();
   double getVolume();
   
private:
   string planetName;
   double planetRadius;
};

#endif
