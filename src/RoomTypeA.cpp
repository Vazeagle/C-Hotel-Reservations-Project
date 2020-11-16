#include "RoomTypeA.h"
#include "Room.h"

RoomTypeA::RoomTypeA(int _capacity, double _pricePerDay):super(_capacity, 0)
{

   capacity=_capacity;
   pricePerDay=_pricePerDay;

}

double RoomTypeA::getPricePerDay()
{
    return pricePerDay;
}
void RoomTypeA::setPricePerDay(double a)
{
    pricePerDay=a;
}

double RoomTypeA::income(double sale)  //πιθανότατα θέλει και εκαιρεση
{
    for (int i=0; i<30; i++)
    {
        if(listAvailable[i]!=nullptr)
        {
        totalPrice += pricePerDay;
        }
    }

    return totalPrice;
}
/*
RoomTypeA::~RoomTypeA()
{
    //dtor
}
*/
