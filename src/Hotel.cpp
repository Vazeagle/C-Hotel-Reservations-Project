#include <iostream>
#include "Hotel.h"
#include <vector>
#include <math.h>
#include "Room.h"
#include "Reservation.h"
#include <string>

class Room;
class Reservation;
class Hotel;

using namespace std;

bool done;
int k;
vector <Room*>roomVector;


vector<Reservation*> reservationVector;


vector<Room*> getRoomVector()
{
    return  roomVector;
}
vector<Reservation*> getReservationVector()
{
    return reservationVector;
}

string Hotel::getHotelName()
{
    return hotelName;
}
void Hotel::setHotelName(string hn)
{
    hotelName = hn;
}

void Hotel::addRoom(Room *_room)
{
    //roomVector.insert(room);
    roomVector.push_back(_room);
}

Reservation* Hotel::recoveryReservationCode(int resCode)
{
    for(int i = 0; i<(int)reservationVector.size(); i++)
    {
        if(reservationVector.at(i)->getReservationCode()==resCode)
        {
            return reservationVector.at(i);
        }
        else
        {

            return 0;
        }
    }
}

Room* Hotel::recoveryRoomCode(int roomCode)
{
   for(int i = 0; i<roomVector.size(); i++)
   {
        if(roomVector.at(i)->getRoomCode()==roomCode)
        {
            return roomVector.at(i);
        }
        else
        {
            return 0;
        }
   }
}

bool Hotel::addRoomReservation(Reservation *res,int roomCode)//Αυτη η μεθοδος παιρνει ορισμα ενα αντικειμενο Reservation π.χ.(res) και τον κωδικο δωματιου π.χ. (roomCode)
{                                                             //και επιστρεφει μια τιμη boolean(true ή false)  που δειχνει αν εγινε η κρατηση με επιτυχια ή οχι
    done = recoveryRoomCode(roomCode)->addReservation(res); //η μεταβλητη done που ειναι boolean,εδω καλουμε και αλλες μεθοδους να εκτελεστουν με αντικειμενα roomCode και res αντιστοιχα για να εκχωρηθει στο τελος στην done true ή false αναλογα με το αποτελεσμα των πραξεων.
    if(done)for(int i = 0; i<roomVector.size(); i++)
    {
        Hotel::reservationVector.at(done);
        cout<< "Reservation was registered with success  "<<'\n';
        return true;
    } //εκτυπωση Reservation was registered with success και επιστροφη true αν η προσθηκη εγινε με επιτυχια
    else
    {
        cout<<"Reservation was failed to register "<<'\n';
        return false;  //εκτυπωση Reservation was failed to register και επιστροφη false αν η προσθηκη απετυχε
    }
}

int Hotel::addReservation(Reservation *res) //Αυτη η μεθοδος παιρνει ορισμα ενα αντικειμενο Reservation π.χ.(res) και το προσθετει σε οποιοδηποτε δωματιο μπορει με την βοηθεια της προηγουμενης μεθόδου.
{
    for(int i = 0; i<roomVector.size(); i++)
    { //Εδω διαβαζεται το μεγεθος της λιστα δωματιων(δηλαδη ποσα δωματια υπαρχουν)
        if(addRoomReservation(res,roomVector.at(i)->getRoomCode()))
        {
            cout<<"in Room "<<roomVector.at(i)->getRoomCode();//εκτυπωση αν η κρατηση εγινε με επιτυχια ή οχι και σε πιο δωματιο
            return roomVector.at(i)->getRoomCode();
        }
    }
    return 0;
}

void Hotel::cancelReservation(int resCode )//Αυτη η μεθοδος παιρνει ορισμα τον κωδικο μιας κρατησης και ακυρωνει την κρατηση με την βοηθεια των εξης μεθοδωνrecoveryReservationCode() και την cancel() της κλασης Room
{
    for(k = 0; k<roomVector.size(); k++)
    {
         done = recoveryReservationCode(resCode)->getRoom().cancel(resCode);
    }
        if(done)
        {
            reservationVector.erase(reservationVector.begin()+k);/* θεση ακυρωσης*/

            cout<<"Cancelation was made with success"<< '\n';
        }//αν η ακυρωση εγινε με επιτυχια εκτυπωνει Cancelation was made with success
        else
            cout<<"Cancelation has failed" ;//αν η ακυρωση απετυχε εκτυπωνει Cancelation has failed
}

double Hotel::incomeCalc(int roomCode)//Αυτη η μεθοδος υπολογιζει και επιστρεφει τα συνολικα εσοδα ενος δωματιου βαζοντας τον κωδικο του δωματιου.
{
    return recoveryRoomCode(roomCode)->income();
}

double Hotel::incomeCalc()//Αυτη η μεθοδος υπολογιζει και επιστρεφει τα συνολικα εσοδα  ολων των δωματιων,διαβαζοντας ολα τα δωματια της λιστας δωματιων.
{
    double sum = 0;
    for(int i = 0; i<roomVector.size(); i++)
    {
        sum+=roomVector.at(i)->income();
    }
    return sum;
}
void Hotel::resPlan()   //Αυτη η μεθοδος διαβαζει δωματια της λιστας δωματιων και εκτυπωνει για το καθε ενα τον πινακα διαθεσιμοτητας του
{                       //τις ημερες που ειναι αδειο εχει - ενω οταν ειναι γεματο * .
    cout<<"Δωματιο";
            for(int i = 0;i<29;i++){
    cout<<(i+1<10)?("\t0"+(i+1)):("\t"+(i+1));
        }
        cout<<"\t30";
         for(int i = 0;i <= this->roomVector.size() - 1;i++){
            cout<<" ";
            cout<<this->roomVector.at(i)->getRoomCode();
            for(int j = 0;j<30;j++)
                //cout <<'\t'<<((this->roomVector.at(i).listAvailable[j] == true)?"*":"_");
                cout <<'\t'<<((this->roomVector.at(i)->check(j) == true)?"*":"_");
        }
       cout<<" ";
}






