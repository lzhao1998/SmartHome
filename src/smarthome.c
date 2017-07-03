#include "smarthome.h"
#include <math.h>
#include "getcoordinate.h"
#include "stdlib.h"

GpsCoordinate House=
{
  200,5345,
};

GpsCoordinate GarageDoor=
{
  220,5300,
};

GpsCoordinate GarageCenter=
{
  215,5300,
};

GpsCoordinate Kitchen=
{
  196,5400,
};

//current = current corrdinate , placeCo = coordinate of the place u want to go
double getCoordinateAndCal(GpsCoordinate current,GpsCoordinate placeCo) 
{
  return sqrt(pow((current.x-placeCo.x),2)+pow((current.y-placeCo.y),2));
}

void doSmartThings()
{
  GpsCoordinate gps = getGpsCoordinate();
  if((getCoordinateAndCal(gps,GarageCenter)) == 0) //in the center of garage, door close
  {
    turn(GARAGE_DOOR,OFF);
  }
  else if((getCoordinateAndCal(gps,GarageDoor)) <= 5) //near garage, door open
  {
    turn(GARAGE_DOOR,ON);
  }
  else if((getCoordinateAndCal(gps,Kitchen)) <= 50) // in the kitchen, light on
  {
    turn(KITCHEN_LIGHT,ON);
  }
	else if((getCoordinateAndCal(gps,House)) <= 2000) //house radius 2km , on aircond and heater
  {
    turn(AIRCOND,ON);
    turn(WATER_HEATER,ON);
  }
  else  // over 2km then close all
  {
    turn(AIRCOND,OFF);
    turn(WATER_HEATER,OFF);
    turn(GARAGE_DOOR,OFF);
    turn(KITCHEN_LIGHT,OFF);
  }
  
}