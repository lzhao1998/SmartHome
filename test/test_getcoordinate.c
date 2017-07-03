#include "unity.h"
#include "smarthome.h"
#include "mock_getcoordinate.h"

void setUp(void)
{
}

void tearDown(void)
{
}

GpsCoordinate over2kmFromHouse=
{
  2220,8000,
};
GpsCoordinate below2kmFromHouse=
{
  1220,6300,
};
GpsCoordinate outsideGarage=
{
  223,5301,
};
GpsCoordinate parkingCar=
{
  215,5300,
};
GpsCoordinate inKitchen=
{
  200,5424,
};

void test_over_2km_range_expect_all_device_off(void)
{
  getGpsCoordinate_ExpectAndReturn(over2kmFromHouse);
  turn_Expect(AIRCOND,OFF);
  turn_Expect(WATER_HEATER,OFF);
  turn_Expect(GARAGE_DOOR,OFF);
  turn_Expect(KITCHEN_LIGHT,OFF);
  
  doSmartThings();
}

void test_below_2km_range_expect_aircond_heater_ON(void)
{
  getGpsCoordinate_ExpectAndReturn(below2kmFromHouse);
  turn_Expect(AIRCOND,ON);
  turn_Expect(WATER_HEATER,ON);
  
  doSmartThings();
}

void test_garage_door_open(void)
{
  getGpsCoordinate_ExpectAndReturn(outsideGarage);
  turn_Expect(GARAGE_DOOR,ON);
  
  doSmartThings();
}

void test_garage_door_close(void)
{
  getGpsCoordinate_ExpectAndReturn(parkingCar);
  turn_Expect(GARAGE_DOOR,OFF);
  
  doSmartThings();
}

void test_kitchen_light_on(void)
{
  getGpsCoordinate_ExpectAndReturn(inKitchen);
  turn_Expect(KITCHEN_LIGHT,ON);
  
  doSmartThings();
}