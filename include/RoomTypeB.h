#ifndef ROOMTYPEB_H
#define ROOMTYPEB_H
#include <RoomTypeA.h>


class RoomTypeB : public RoomTypeA
{
    private:
        double salePerDay;
        double salePrice;
        double cost;
        int j;
        int roomResCod1;
        int roomResCod2;
        double dayPrice;
        int counter;

    public:
        typedef RoomTypeA super;
        RoomTypeB(int _capacity, double _pricePerDay, double _salePerDay);
        double getSalePerDay();
        void setSalePerDay(int spd);
        double  getSalePrice();
        bool cancel(int rs);
};

#endif // ROOMTYPEB_H
