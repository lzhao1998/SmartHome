#ifndef _GETCOORDINATE_H
#define _GETCOORDINATE_H

typedef struct GpsCoordinate GpsCoordinate;

struct GpsCoordinate {
  float x;
  float y;   
};

typedef enum {
  GARAGE_DOOR,
  KITCHEN_LIGHT,
  AIRCOND,
  WATER_HEATER,
} Device;

typedef enum {
  OFF,
  ON
} State;

void turn(Device device, State state);  
GpsCoordinate getGpsCoordinate();

#endif // _GETCOORDINATE_H
