#include RoomTypeC.h

class RoomTypeC : public Room;
{
    RoomTypeC::RoomTypeC(int maxCapacity, int minPerson, int minDays):super(maxCapacity,0)
    {
    ReservationreservationCode= this->reservationCode;
    minPerson =this-minPerson;
    minDays=this-minDays;
    }

    bool RoomTypeC::getReservation(Reservation res)
    {
      for (int i=res->getArrival()-1; i<res->getArrival()+res->getStay()-1; i++)
    {
    if(listAvailable[i]!=null)
    return false;
    if(res.getPerson()maxCapacity)
    return false;
    if(res.getPerson()=minPerson && res->getStay()=minDays)
    return true;
    }

    for (int i=res.getArrival()-1; ires->getArrival()+res->getStay()-1; i++)
    listAvailable[i]=res;
    res->setRoom(this);
    return true;


    }


}
