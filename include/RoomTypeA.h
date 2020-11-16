#ifndef ROOMTYPEA_H
#define ROOMTYPEA_H
#include "RoomTypeA.h"
#include "Room.h"

class RoomTypeA : public Room
{
     public:
         typedef Room super;
        RoomTypeA(int _capacity, double _pricePerDay);
        double getPricePerDay();
        void setPricePerDay(double a);
        double income(double sale);


    protected:
         double totalPrice;
        double pricePerDay;


};
#endif // ROOMTYPEA_H
