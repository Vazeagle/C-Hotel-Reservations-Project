#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include <Room.h>

class Room;
using namespace std;


class Reservation
{
private:
    Room *room;
    int reservationCode, arrival, stay, person;
    string clientName;
    static int counter;
public:
    Reservation(string clientName, int arrival,int stay, int person);
    void setRoom(Room *room);
     string getClientName();
     int getReservationCode();
     int getPersons();
     int getArrival();
     int getStay();
    Room  getRoom();

};
#endif // RESERVATION_H
