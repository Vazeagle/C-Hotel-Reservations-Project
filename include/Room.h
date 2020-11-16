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
        bool addReservation(Reservation *res);   //������� ��������� ��������
        double income(/*double sale*/);             //������� ����������� e orisma
        bool cancel(int rc);                    // ������� ��������
        int Completness();                      //������� ����������
        bool check(int i);

        //virtual ~Room();


    protected:
        static int staticRoomCode;     //������� �������� static                    //������� ��������
               int roomCode;           //������ ��������
               double totalPrice;      //�������� ������
                int capacity;                  //������������           //���������
                double pricePerPerson;          //������ ��� �����
    private:


        bool kataxwrhsh;               //����������� ����������� ���������
        int i;                         //��������
        double price;                  //����
        int completness;
};
#endif // ROOM_H
