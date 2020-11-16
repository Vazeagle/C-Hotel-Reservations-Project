#ifndef ROOMTYPEC_H
#define ROOMTYPEC_H


class RoomTypeC: public Room
{
    public:
        typedef Room super;
        RoomTypeC(int maxCapacity, int minPerson, int minDays);
        bool getReservation(Reservation res);


    private:
        int minPerson;
        int minDays;
};

#endif // ROOMTYPEC_H

