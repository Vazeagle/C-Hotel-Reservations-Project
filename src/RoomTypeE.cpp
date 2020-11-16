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
   for (int i=res->getArrival()-1; i<res->getArrival()+res->getStay()-1; i++) //��� �� ���� ��� ���������� ���������� ��� ��������� � ������� �������������� ��� � ������� ����� ��� �������� ���� ��������.
      if(listAvailable[i]!=null)
       return false;
       if(res->getPerson()>maxCapacity)
       return false;
       if(listAvailable[res->getArrival()+res->getStay()]==null){
       can=true;
       freeDay++;}
     for (int i=res->getArrival()-1; i<res->getArrival()+res->getStay()-((can==false)?1:0); i++)  //��� ��������� �� � ������� ����� ������ �� ���� ������� �� ��� ���� ���������� true
                                                                                               //��� ����������� ���� � extra ���� �� ���� ��� ������������ ������� ��� ��������.
     listAvailable[i]=res;
     res->setRoom(this);
     return true;
}

double RoomTypeE:: income()//���� � ������� ��������� ��� �� ��� ����������� ��� �������� ������ �� ������ ��� ������ ������
                    //�������� ��� ���� ��� ������ ����� ��� ��������� ���� �������� ��� ������ �� ��������.
{
     double sum=super::income();
     sum-=pricePerDay*freeDay;
     return sum;
}
