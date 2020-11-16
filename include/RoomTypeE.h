#ifndef ROOMTYPEE_H
#define ROOMTYPEE_H
#include "RoomTypeA.h"
class RoomTypeE :public RoomTypeA
{
    private:
        static int freeDay;
    public:
        typedef RoomTypeA super;
        RoomTypeE(int maxCapacity, double pricePerDay);
         bool getReservation(Reservation res);
         double income();
};
#endif
