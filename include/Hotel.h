#ifndef HOTEL_H
#define HOTEL_H
#include <vector>
#include <Room.h>
#include <string>
using namespace std;
class Hotel
{
    public:

        string hotelName;
        string getHotelName();
        void setHotelName(string hn);
        void addRoom(Room *room);
        Reservation* recoveryReservationCode(int resCode);
        Room* recoveryRoomCode(int roomCode);
        bool addRoomReservation(Reservation *res,int roomCode);
        int addReservation(Reservation *res);
        void cancelReservation(int resCode );
        double incomeCalc(int roomCode);
        double incomeCalc();
        void resPlan();
        vector<Room> getRoomVector();
        vector<Reservation> getReservationVector();
        vector<Room*> roomVector;
        vector<Reservation*> reservationVector;


};

#endif // HOTEL_H
