#include<iostream>
#include<string>
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include <Hotel.h>
#include <Reservation.h>
#include <Room.h>
#include <RoomTypeA.h>
#include <RoomTypeB.h>
#include <RoomTypeC.h>
#include <RoomTypeD.h>
#include <RoomTypeE.h>
using namespace std;


int main()
{
    srand(time(0));
    //int random = rand() ;
    int getChoice();
    int setCoice(int chc);
    int roomChoice;
    int choice;
    int userRoomCode;
    //int roomNum[10]={101,102,201,202,301,302,401,402,501,502};
    int passedDays;         //metrhths
    int leftDays;
    int repetition =1;      //������� ��������� (1-> ������, ��� ������� ���������, 0-> ��������. ��� ��� ������� ���������)
    //string S ;
    //string S1;


    Hotel *ZeusHotel = new Hotel();

    RoomTypeA *room101 = new RoomTypeA( 2, 60);
    room101->setRoomCode(101);
    room101->setPricePerPerson(40);
    ZeusHotel->addRoom(room101);

    RoomTypeA *room102 = new RoomTypeA( 3, 85);
    room102->setRoomCode(102);
    room102->setPricePerPerson(35);
    ZeusHotel->addRoom(room102);



    RoomTypeB *room201 = new RoomTypeB(2, 65, 10);
    room201->setRoomCode(201);
    ZeusHotel->addRoom(room201);

    RoomTypeB *room202 = new RoomTypeB(4, 55, 10);
    room202->setRoomCode(202);
    ZeusHotel->addRoom(room202);


    RoomTypeC *room301 = new RoomTypeC(3, 2, 4);
    room301->setRoomCode(301);
    room301->setPricePerPerson(25);
    ZeusHotel->addRoom(room301);

    RoomTypeC *room302 = new RoomTypeC(4, 2, 3);
    room301->setRoomCode(302);
    room301->setPricePerPerson(22);
    ZeusHotel->addRoom(room302);



    RoomTypeD *room401 = new RoomTypeD(3, 65);
    room401->setRoomCode(401);
    room401->setPricePerPerson(30);
    ZeusHotel->addRoom(room401);

    RoomTypeD *room402 = new RoomTypeD(4, 80);
    room402->setRoomCode(402);
    room402->setPricePerPerson(27);
    ZeusHotel->addRoom(room402);



    RoomTypeE *room501 = new RoomTypeE(3, 70);
    room501->setRoomCode(501);
    room501->setPricePerPerson(25);
    ZeusHotel->addRoom(room501);

    RoomTypeE *room502 = new RoomTypeE(4, 90);
    room502->setRoomCode(502);
    room502->setPricePerPerson(20);
    ZeusHotel->addRoom(room502);


      choice = 0;
      repetition=1;

    for( passedDays =1; passedDays<=30; passedDays++)
    {

        cout<<'\n';
        cout<<"����� "<<passedDays<<"�"<<'\n';
        if(passedDays==30)
            {cout<<"��������� ����� ��� ������������ ��� �����������"<<'\n';}

        while(repetition==1)//���������� ������� ��������
        {

            int arrival=rand() %29+1;
            int days=rand()%(30-arrival)+1;
            int people=rand()%5+1;
            const string People[10]={"�������", "�����", "��������", "�������", "����������", "�����", "������", "�������", "�������", "�����"};
            int peopleRandom=rand() %9;
            Reservation *res0=new Reservation(People[peopleRandom],arrival,days,people);
            ZeusHotel->addReservation(res0);
           // int *myPositionPointer;
           // int position;
           // myPositionPointer=&position;
            if(rand() %3 ==0)//25% ������ ���������� �� �������� ������� �������� (���������� ������ ���� ������� ��� 0 ��� 3 ��� �� ��� ������� ��� ������� �������� �������� ���������� � ������� ������
            {
              int  position = rand() %(ZeusHotel->getReservationVector().size() - 1);
/*SOSOSOSOS*/ ZeusHotel->cancelReservation(ZeusHotel->reservationVector[position]->getReservationCode());
            }
            repetition=0;
        }


        cout<<"�������������� ��� ��� ��� ��� �������� �������� 0 ��� 7"<<'\n';  //��� �� ��� ������� ��� ������� ��������� ������������ ��� Menu ��� �� ����� � ������� �������� ��� ������� �����

        cout<<"     0.������� ��������� " <<'\n'<< "     1.�������� ��������"<<'\n'<<"     2.������� ��������"<<'\n'<<"     3.������� ���������"<<'\n'<<"     4.������� ��������"<<'\n'<<"     5.������� ������ ��������"<<'\n'<<"     6.������� ������"<<'\n'<<"     7.����������� "<<'\n';
            //��������� ��� ������ ��� ���� �������� ��� ����������� ��� ������������ ���������� ��� ��������� ��� ����������

        //den xriazetai Scanner keyboard=new Scanner(System.in); //���������� ������������ keyboard ����� Scanner ��� ��� �������� ��������� ��� �� ������������

        cin>>choice;//��� �� ���� ��� ������ ��������� ��� �� ������������ �� ������� ��� ������ � ������� ��� �� ���������� � ������������ �������� ��� �����
         string x1;
         int x2, x3, x4, x5, x6;



        switch(choice) //�� ��� ������� ��� switch ���������� ���� ��� ������ �������� ��� ������� ��� ������� �� �� �� ��������� � �������  ��������������� �� ���� ��������� case.
        {
            case 0:  //������� ���������, ���������� ������� ��������
            {
                cout<<"/***************************************************************************/"<<'\n';
                cout<<"��������� �� ����������� ���� ������� ����� ��� ������������ ��� �����������"<<'\n'<<'\n';
                repetition=1;
                break;
            }

            case 1: //�������� �������� (� ������� ����� ����������� �� ������������ ������ ��������
            {
                cout<<"��������� �� ������ ��� ��� ������� ��� ���������� ���"<<'\n'<<'\n';

                cout<<"�������� ����������� �� �������� �������� ��� ��������: "<<'\n';
                cout<<"�����: "<<'\n';
                cin>>x1;

                do{
                    cout<<"����� ������ (01-30):"<<'\n';
                    cin>>x2;
                    }while( x2>=passedDays || x2 <=30);

                do{
                    leftDays=30-passedDays;
                    cout<<"������ �������� (������ �� ����� ��������� ��� " << leftDays << ") :"<<'\n';
                    cin>>x3;
                    }while(x3 < leftDays);//30-passedDays);

                do{
                    cout<<"����� (1-4):"<<'\n';
                    cin>>x4;
                    }while(x4<1 ||x4>4);


                do{
                    cout<<"�� ������������ ������ ������������ �������; "<<'\n'<<"     �� ���, ������������� '1' "<<'\n'<<"     �� ���, ������������� '2' "<<'\n';
                    cin>>roomChoice;
                    }while(roomChoice != 1 && roomChoice != 2);

                     Reservation *res1=new Reservation(x1,x2,x3,x4); //���������� ������������ �������� �� �������� ��� ���������� ��� �� ������������ �� ������������ �����
                    if(roomChoice==1)
                    {
                       // do{
                            cout<<"�������������� ��� ������ �������� ��� ���������� ��� �� ��� ��������� ����������, �� ����������� � ������� ���:"<<'\n';
                            cin>>userRoomCode;
                         //   }while(reservationVector.get());

                            ZeusHotel->addRoomReservation(res1, userRoomCode);

                    }
                    else if(roomChoice==2)
                    {
                        ZeusHotel->addReservation(res1);
                    }

                    //Reservation *res1=new Reservation(x1,x2,x3,x4); //���������� ������������ �������� �� �������� ��� ���������� ��� �� ������������ �� ������������ �����
                    ZeusHotel->addReservation(res1);

                    cout<<"� ������� " << res1->getReservationCode()<< " ����� ��� �o� ������ " <<res1->getClientName()<< " ��� ����� " <<res1->getPersons()<< " �����, ��� ������� ���� " << res1->getArrival() << " ��� ���� ��� �� ������� ��� " << res1->getStay() << " ������, ������ ��� ��� " << res1->getArrival()<< " ����� ��� " <<res1->getArrival()-res1->getStay()-1 << " ��� ����."<<'\n';
                    cout<<"������������ ��� ��� ��������� ���!!! "<<'\n';

                    break;

            }
            case 2:
            {
                cout<<"��������� �� ��������� ��� �������"<<'\n'<<'\n';
                cout<<"�������������� ��� ������ �������� ���� ������� :"<<'\n'; //������� �������� ��������� ��� ������ ��� ��������
                cin>>x5;
                ZeusHotel->cancelReservation(x5);

                break;
            }


            case 3:   //�������� ������ �� ���� ��� ��������� ��� �����������
            {

                cout<<"��������� �� ����� ������� ��� ��������� ��� �����������"<<'\n'<<'\n';
                //ZeusHotel->addReservation(getReservationVector());
                cout<<"������� ��������" <<'\t' << "����� ������"<<'\t'<<"������� �������� "<<'\t'<<'\n';
                for(int i = 0; i<= ZeusHotel->getReservationVector().size()-1; i++)
                {
                    cout<<ZeusHotel->reservationVector[i]->getReservationCode() << '\t'<<'\t'<< ZeusHotel->reservationVector[i]->getClientName() << '\t'<<ZeusHotel->reservationVector[i]->getRoom().getRoomCode()<< '\t'<<'\n';
                }
                //cout<<(S);

                break;

            }

            case 4:            //�������� ������ �� �� ������� ��� �����������
            {
                cout<<"��������� ��� ������� �������� ��� �����������";
                ZeusHotel->getRoomVector();
                cout<<"������� ��������"<<'\t'<<"���������"<<'\t'<<"�����"<<'\t'<<'\n';
                for(int j = 0; j<= ZeusHotel->getRoomVector().size()-1; j++)
                {
                    cout<<ZeusHotel->roomVector[j]->getRoomCode() <<'\t'<<'\t'<< (ZeusHotel->roomVector[j]->Completness())<<'\t'<<'\t'<<ZeusHotel->roomVector[j]->income()<<'\t'<<'\n';
                }
                //cout<<(S1);
                break;
            }

            case 5:        //������� ������ ��������� �� ��� ������� ��� ������� resPlan()
            {
                cout<<"��������� ��� ������� ��� ������ ��������� ��� �����������";
                ZeusHotel->resPlan();
                break;
            }


            case 6:      //������� ������
            {
                 cout<<"��������� ��� ������� ��� ������ ��� �����������";
                cout<<"�� ������ �� ������ ������������ �������;"<< '\n'<< "     �� ���, ������������� ��� ������ ��� �������� ��� ����������:"<<'n'<<"�� ���, ��� ���� ��������� �������������� '0'" ;
                cin>>x6; //������� ������ ������������� �������� �� ������������ ������ �������� ��� ������� ��� �� ������������
                if (x6==0)
                    cout<<(ZeusHotel->incomeCalc());
                else
                    cout<<(ZeusHotel->incomeCalc(x6)); //������� ��������� ������ ��� ����������� ��� ��� �� �������
                break;

            }
            case 7:
            {
                cout<<"��������� ���������� ��� ������������. �� ��������� �� �����������";
                break; //����������� ������������
            }
            default:
            {
                cout<<"� ������� ��� �������� ��� ����� ���������. �������� �������������� ��� ��� ��� ���������� ������� ( 0, 1, 2, 3, 4, 5, 6, 7 )";
                    break;
            }
        }
    }


return 0;
};
