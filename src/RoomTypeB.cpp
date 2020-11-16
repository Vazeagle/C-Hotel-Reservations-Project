#include "RoomTypeB.h"
#include <iostream>
#include "RoomTypeA.h"
using namespace std;



RoomTypeB::RoomTypeB(int _capacity, double _pricePerDay, double _salePerDay):super(capacity, 0)
{
    capacity=_capacity;
    pricePerDay=_pricePerDay;

    salePerDay=_salePerDay;

}
double RoomTypeB::getSalePerDay(){
    return salePerDay;
}
void RoomTypeB::setSalePerDay(int spd){
    salePerDay=spd;
}

double  RoomTypeB::getSalePrice(){
    return salePrice;
}
















/*double RoomTypeA::income()//Αυτη η μεθοδος υπερκαλυπτει την μεθοδο τιμολογησης(income())της RoomTypeA αλλα για καθε επιπλεον μερα διαμονης
{                    // μιας κρατησης η τιμη της μερας μειωνεται διαδοχικα με ενα ποσο salePerDay το οπιο καθοριζεται απο τον χρηστη
double sum = 0;
int currentCode = 0;
int k=0;
for (int i=0; i<30; i++)
    if(listAvailable[i]!=nullptr){
    if(currentCode != listAvailable[i]->getreservationCode()){currentCode = listAvailable[i]->getreservationCode();k=0;}
    k++;
    if(pricePerDay-salePerDay*k > pricePerDay/2){sum+=pricePerDay-salePerDay*k;}else{sum+=pricePerDay/2;}
    }
    return sum;
     }*/
double RoomTypeA::income(double sale)
{
    roomResCod1=0;
    roomResCod2=0;
    counter=-1;
    cost = this-> getPricePerDay();
    for(int p=0; p<30; p++){
        if(listAvailable[p]!=nullptr){
            if(roomResCod1==listAvailable[p]->getReservationCode()){
                counter +=1;    //ypologismos
            }
            else{
                counter=-1;
                roomResCod1=listAvailable[p]->getReservationCode();
            }
            pricePerDay = cost - counter*10;
            if (pricePerDay<cost/2){
                pricePerDay= cost/2;
            }
            totalPrice+= pricePerDay;
        }
    }
    return totalPrice;
}



 bool RoomTypeB::cancel(int rd){//μέθοδος ακύρωσης
  cout<<"Η κράτηση για αυτό το δωμάτιο δεν μπορεί να ακυρωθεί";
    return false;
}




