#include "Reservation.h"
#include "Room.h"
#include <cstddef> //gia to null
#include <stddef.h>
#include <string>


class Reservation;

class Room;
class Hotel;
Reservation *res;

int Reservation::counter=1;

Reservation::Reservation(string clientName, int arrival,int stay, int person):room(NULL)

{
     //Room *room =NULL;
     counter++;
     Reservation::reservationCode= this->reservationCode;
     Reservation::clientName= this->clientName;
     Reservation::arrival= this->arrival;
     Reservation::stay= this->stay;
     Reservation::person= this->person;
}
void Reservation::setRoom(Room *room)
{Reservation::room= this->room;}

string Reservation::getClientName()
{ return clientName; }

int Reservation::getArrival()
{return arrival;}

int Reservation::getStay()
{return stay;}

int Reservation::getPersons()
{return person;}

int Reservation::getReservationCode()
{return reservationCode;}

Room Reservation::getRoom()
{return *room;}

