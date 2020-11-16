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

bool Hotel::addRoomReservation(Reservation *res,int roomCode)//���� � ������� ������� ������ ��� ����������� Reservation �.�.(res) ��� ��� ������ �������� �.�. (roomCode)
{                                                             //��� ���������� ��� ���� boolean(true � false)  ��� ������� �� ����� � ������� �� �������� � ���
    done = recoveryRoomCode(roomCode)->addReservation(res); //� ��������� done ��� ����� boolean,��� ������� ��� ����� �������� �� ����������� �� ����������� roomCode ��� res ���������� ��� �� ��������� ��� ����� ���� done true � false ������� �� �� ���������� ��� �������.
    if(done)for(int i = 0; i<roomVector.size(); i++)
    {
        Hotel::reservationVector.at(done);
        cout<< "Reservation was registered with success  "<<'\n';
        return true;
    } //�������� Reservation was registered with success ��� ��������� true �� � �������� ����� �� ��������
    else
    {
        cout<<"Reservation was failed to register "<<'\n';
        return false;  //�������� Reservation was failed to register ��� ��������� false �� � �������� �������
    }
}

int Hotel::addReservation(Reservation *res) //���� � ������� ������� ������ ��� ����������� Reservation �.�.(res) ��� �� ��������� �� ����������� ������� ������ �� ��� ������� ��� ������������ �������.
{
    for(int i = 0; i<roomVector.size(); i++)
    { //��� ���������� �� ������� ��� ����� ��������(������ ���� ������� ��������)
        if(addRoomReservation(res,roomVector.at(i)->getRoomCode()))
        {
            cout<<"in Room "<<roomVector.at(i)->getRoomCode();//�������� �� � ������� ����� �� �������� � ��� ��� �� ��� �������
            return roomVector.at(i)->getRoomCode();
        }
    }
    return 0;
}

void Hotel::cancelReservation(int resCode )//���� � ������� ������� ������ ��� ������ ���� �������� ��� �������� ��� ������� �� ��� ������� ��� ���� �������recoveryReservationCode() ��� ��� cancel() ��� ������ Room
{
    for(k = 0; k<roomVector.size(); k++)
    {
         done = recoveryReservationCode(resCode)->getRoom().cancel(resCode);
    }
        if(done)
        {
            reservationVector.erase(reservationVector.begin()+k);/* ���� ��������*/

            cout<<"Cancelation was made with success"<< '\n';
        }//�� � ������� ����� �� �������� ��������� Cancelation was made with success
        else
            cout<<"Cancelation has failed" ;//�� � ������� ������� ��������� Cancelation has failed
}

double Hotel::incomeCalc(int roomCode)//���� � ������� ���������� ��� ���������� �� �������� ����� ���� �������� �������� ��� ������ ��� ��������.
{
    return recoveryRoomCode(roomCode)->income();
}

double Hotel::incomeCalc()//���� � ������� ���������� ��� ���������� �� �������� �����  ���� ��� ��������,����������� ��� �� ������� ��� ������ ��������.
{
    double sum = 0;
    for(int i = 0; i<roomVector.size(); i++)
    {
        sum+=roomVector.at(i)->income();
    }
    return sum;
}
void Hotel::resPlan()   //���� � ������� �������� ������� ��� ������ �������� ��� ��������� ��� �� ���� ��� ��� ������ �������������� ���
{                       //��� ������ ��� ����� ����� ���� - ��� ���� ����� ������ * .
    cout<<"�������";
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






