#ifndef ROOMTYPED_H
#define ROOMTYPED_H
#include "Room.h"
class RoomTypeD : public Room
{
 private:
     double pricePerDay;
 public:
     typedef Room super;
    RoomTypeD( int maxCapacity, double pricePerDay);
    double income();
};
#endif // ROOMTYPED_H
