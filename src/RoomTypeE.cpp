#include "RoomTypeE.h"
#include "Room.h"

int RoomTypeE::freeDay=0;
RoomTypeE::RoomTypeE(int _capacity, double _pricePerDay):super(maxCapacity, 0)
{
    capacity=_capacity;
    pricePerDay=_pricePerDay;

}


bool RoomTypeE:: getReservation(Reservation res)
{
 bool can=false;
   for (int i=res->getArrival()-1; i<res->getArrival()+res->getStay()-1; i++) //εδω με αυτη την επαναληψει διαβαζεται και ελεγχεται ο πινακας διαθεσημοτητας και η επομενη ημερα μια κρατησης ενως δωματιου.
      if(listAvailable[i]!=null)
       return false;
       if(res->getPerson()>maxCapacity)
       return false;
       if(listAvailable[res->getArrival()+res->getStay()]==null){
       can=true;
       freeDay++;}
     for (int i=res->getArrival()-1; i<res->getArrival()+res->getStay()-((can==false)?1:0); i++)  //Εδω ελεγχεται αν η επομενη ημερα ανηκει σε αλλη κρατηση αν οχι τοτέ επιστρεφει true
                                                                                               //και καταχωρειτε αυτη η extra μερα σε αυτη την συγκεκριμενη κρατηση του δωματιου.
     listAvailable[i]=res;
     res->setRoom(this);
     return true;
}

double RoomTypeE:: income()//Αυτη η μεθοδος φροντιζει στο να μην υπολογιστει στο συνολικο κοστος το κοστος της δωρεαν ημερας
                    //συνολικα για ολες τις δωρεαν μερες των κρατησεων ενος δωματιου που μπορει να υπαρχουν.
{
     double sum=super::income();
     sum-=pricePerDay*freeDay;
     return sum;
}
