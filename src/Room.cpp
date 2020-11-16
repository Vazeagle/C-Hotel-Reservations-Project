#include <Room.h>
#include <Reservation.h>
//Reservation *listAvailable[30];            // πίνακας διαθεσιμότητας 30 θέσεων
class Reservation;
class Hotel;
Reservation *res;

int Room::getRoomCode(){
    return roomCode;
}

void Room::setRoomCode(int rc){
    roomCode = rc;
    staticRoomCode= roomCode;
}
/*
static int Room::getStaticRoomCode(){
    return staticRoomCode;
}
*/
int Room::getCapacity(){
    return capacity;
}

void Room::setCapacity(int max){
    capacity=max;
}

double Room::getPricePerPerson(){
    return pricePerPerson;
}

void Room::setPricePerPerson(int cpp){
    pricePerPerson=cpp;
}

bool Room::getKataxwrhsh(){
    return kataxwrhsh;
}

void Room::setKataxwrhsh(bool k){
    kataxwrhsh=k;
}






bool Room::addReservation(Reservation *res)        //μέθοδος προσθήκης κράτησης
{
    for(i=res->getArrival()-1; i< res->getArrival()+res->getStay()-1; i++){
        if(listAvailable[i] != nullptr){
                kataxwrhsh = false;
        }
        else{
            kataxwrhsh = true;
        }
    }
    if(res->getPersons() <= getCapacity() && kataxwrhsh){
        for(i=res->getArrival()-1; i<res->getArrival()+res->getStay()-1 ;i++){
            listAvailable[i]=res;
        }
        res->setRoom(this);
        return true;
    }
    else{
        return false;
    }
}






double Room::income(/*double sale*/) //μέθοδος τιμολόγησης
{
    totalPrice=0;

    for (int i=0; i<30; i++)
    {
      if(listAvailable[i]!=nullptr)
      {
       totalPrice+=listAvailable[i]->getPersons()*pricePerPerson;

      }
    }
    return totalPrice;
}




bool Room::cancel(int rc){// μεθοδος ακύρωσης
//ισως χρειάστεί εξαίρεση
    for(i=0; i<sizeof(listAvailable);i++){ //ισως χρειαστεί και άλλη εξαίρεση
        if(rc==listAvailable[i]->getReservationCode()){
            listAvailable[i]=nullptr;
        }
    }
    return true;
}





int Room::Completness(){//μέθοδος πληρότητας
    for(i=0; i<=sizeof(listAvailable);i++){
        if(listAvailable[i]!=nullptr){
            completness+= 1 ;
        }
    }
    return 100*completness/30;
}





Room::Room(int _capacity, double _pricePerPerson){
    //giati den kaneis static to room code kai na baleis ston constractor mesa roomCode++ gia ka8e fora pou kaleitai?
   // staticRoomCode =roomCode;
    capacity=_capacity;
    pricePerPerson=_pricePerPerson;

    //int static staticRoomCode=0;                //static κωδικός δωματίου
    int roomCode=0;                               //κωδικός δωματίου
    int capacity=0;                               //χωρητικότητα
    double pricePerPerson=0.0;                    //κόστοις ανά άτομο
    bool kataxwrhsh;                              //επιβεβαίωση καταχώρησης κτράτησης
    int i=0;                                      //μετρητής
    double totalPrice=0.0;                        //συνολοκό κόστος
    //double price=0.0;
    int completness=0;                            //πληρότητα
}


bool Room::check(int i)
{
    return ((listAvailable[i] == 0)?false:true);
}



