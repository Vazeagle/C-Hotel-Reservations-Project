#include "RoomTypeD.h"
#include "Room.h"
RoomTypeD::RoomTypeD(int maxCapacity, double pricePerDay):super(maxCapacity,0)

{
     RoomTypeD::pricePerDay=this ->pricePerDay;
}

double RoomTypeD::income()//η Room για overloading;
{
    double fulllCost = super::income();
    if(fullCost>=500)
    totalCost=totalCost-((fullCost*10)/10);
    return fulllCost;
}
