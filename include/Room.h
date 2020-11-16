#ifndef ROOM_H
#define ROOM_H
#include <Reservation.h>
class Reservation;
class Room
{
    public:
        Room( int _capacity, double _pricePerPerson);
        Reservation  *listAvailable[30];
        int getRoomCode();
        void setRoomCode(int rc);
       // static int getStaticRoomCode();
        int getCapacity();
        void setCapacity(int max);
        double getPricePerPerson();
        void setPricePerPerson(int cpp);
        bool getKataxwrhsh();
        void setKataxwrhsh(bool k);
        bool addReservation(Reservation *res);   //μέθοδος προσθήκης κράτησης
        double income(/*double sale*/);             //μέθοδος τιμολόγησης e orisma
        bool cancel(int rc);                    // μεθοδος ακύρωσης
        int Completness();                      //μέθοδος πληρότητας
        bool check(int i);

        //virtual ~Room();


    protected:
        static int staticRoomCode;     //κωδικός δωματίου static                    //κωδικός δωματίου
               int roomCode;           //ωδικός δωματίου
               double totalPrice;      //συνολοκό κόστος
                int capacity;                  //χωρητικότητα           //πληρότητα
                double pricePerPerson;          //κόστος ανά άτομο
    private:


        bool kataxwrhsh;               //επιβεβαίωση καταχώρησης κτράτησης
        int i;                         //μετρητής
        double price;                  //τιμή
        int completness;
};
#endif // ROOM_H
