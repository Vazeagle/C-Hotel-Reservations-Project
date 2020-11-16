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
    int repetition =1;      //επόμενη επανάληψη (1-> θετικό, αρα γίνεται επανάληψη, 0-> αρνητικό. αρα δεν γίνεται επανάληψη)
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
        cout<<"Ημέρα "<<passedDays<<"η"<<'\n';
        if(passedDays==30)
            {cout<<"Τελευταία ημέρα του προγράμματος του ξενοδοχείου"<<'\n';}

        while(repetition==1)//δημιουργία τυχαίας κράτησης
        {

            int arrival=rand() %29+1;
            int days=rand()%(30-arrival)+1;
            int people=rand()%5+1;
            const string People[10]={"Γιώργος", "Μαρία", "Στέφανος", "Δήμητρα", "Αλέξανδρος", "Σοφία", "Ρωξάνη", "Γιάννης", "Αντώνης", "Ελένη"};
            int peopleRandom=rand() %9;
            Reservation *res0=new Reservation(People[peopleRandom],arrival,days,people);
            ZeusHotel->addReservation(res0);
           // int *myPositionPointer;
           // int position;
           // myPositionPointer=&position;
            if(rand() %3 ==0)//25% τυχαια πιθανοτητα να προκυψει ακυρωση κρατησης (διαλεγεται τυχαια ενας αριθμος απο 0 εως 3 και με την βοηθεια της μεθοδου ακυρωσης κρατησης ακυρωνεται η κρατηση τυχαια
            {
              int  position = rand() %(ZeusHotel->getReservationVector().size() - 1);
/*SOSOSOSOS*/ ZeusHotel->cancelReservation(ZeusHotel->reservationVector[position]->getReservationCode());
            }
            repetition=0;
        }


        cout<<"Πληκτρολογήστε για μια απο τις παρακάτω επιλογές 0 έως 7"<<'\n';  //Εδω με την βοηθεια τον εντολων εκτυπωσης δημιουργουμε ενα Menu απο το οποιο ο χρηστης διαλεγει πια επιλογη θελει

        cout<<"     0.Επόμενη Επανάληψη " <<'\n'<< "     1.Προσθήκη Κράτησης"<<'\n'<<"     2.Ακύρωση Κράτησης"<<'\n'<<"     3.Προβολή Κρατήσεων"<<'\n'<<"     4.Προβολή Δωματίων"<<'\n'<<"     5.Προβολή Πλάνου Κρατήσων"<<'\n'<<"     6.Προβολη Εσόδων"<<'\n'<<"     7.Τερματισμός "<<'\n';
            //γραφοντας τον αριθμο της καθε επιλογης που αναγραφεται και ακολουθοντας προσεκτικα τις συμβουλες που ακολουθουν

        //den xriazetai Scanner keyboard=new Scanner(System.in); //δημιουργια αντικειμενου keyboard τυπου Scanner για την εισαγωγη δεδομενων απο το πληκτρολογιο

        cin>>choice;//εδω με αυτη την εντολη εισαγεται απο το πληκτρολογιο το νουμερο που εγραψε ο χρηστης για να εκτελεστει η συγκεκριμενη ενεργεια που θελει
         string x1;
         int x2, x3, x4, x5, x6;



        switch(choice) //με την βοηθεια της switch φτιαχνουμε ολες τις δυνατε επιλογες που θελουμε και αναλογα με το τι απαντησει ο χρηστης  χρησιμοποιειται το καθε αντισοιχο case.
        {
            case 0:  //επόμενη επανάληψη, δημιουργία τυχαίας κράτησης
            {
                cout<<"/***************************************************************************/"<<'\n';
                cout<<"Επιλέξατε να προχωρήσετε στην επόμενη ημέρα του προγράμματος του ξενοδοχείου"<<'\n'<<'\n';
                repetition=1;
                break;
            }

            case 1: //Προσθηκη κρατησης (ο χρηστης δινει προαιρετικα το συγκεκριμενο αριθμο δωματιου
            {
                cout<<"Επιλέξατε να κάνετε μια νέα κράτηση στο ξενοδοχείο μας"<<'\n'<<'\n';

                cout<<"Παρακαλώ συμπληρώστε τα παρακάτω στοιχεία της κράτησης: "<<'\n';
                cout<<"Όνομα: "<<'\n';
                cin>>x1;

                do{
                    cout<<"Ημέρα άφιξης (01-30):"<<'\n';
                    cin>>x2;
                    }while( x2>=passedDays || x2 <=30);

                do{
                    leftDays=30-passedDays;
                    cout<<"Ημέρες διαμονής (πρέπει να είναι λιγότερες από " << leftDays << ") :"<<'\n';
                    cin>>x3;
                    }while(x3 < leftDays);//30-passedDays);

                do{
                    cout<<"Άτομα (1-4):"<<'\n';
                    cin>>x4;
                    }while(x4<1 ||x4>4);


                do{
                    cout<<"Θα προτιμούσατε κάποιο συγκεκριμένο δωμάτιο; "<<'\n'<<"     Αν ναι, πληκρολογήστε '1' "<<'\n'<<"     Αν όχι, πληκρολογήστε '2' "<<'\n';
                    cin>>roomChoice;
                    }while(roomChoice != 1 && roomChoice != 2);

                     Reservation *res1=new Reservation(x1,x2,x3,x4); //Δημιουργια αντικειμενου κρατησης με ορισματα που εισαγονται απο το πληκτρολογιο με συγκεκριμενη σειρα
                    if(roomChoice==1)
                    {
                       // do{
                            cout<<"Πληκτρολογήστε τον αριθμό δωματίου που επιθυμείτε και αν δεν βρίσκεται δεσμευμένο, θα καταχωρηθεί η κράτησή σας:"<<'\n';
                            cin>>userRoomCode;
                         //   }while(reservationVector.get());

                            ZeusHotel->addRoomReservation(res1, userRoomCode);

                    }
                    else if(roomChoice==2)
                    {
                        ZeusHotel->addReservation(res1);
                    }

                    //Reservation *res1=new Reservation(x1,x2,x3,x4); //Δημιουργια αντικειμενου κρατησης με ορισματα που εισαγονται απο το πληκτρολογιο με συγκεκριμενη σειρα
                    ZeusHotel->addReservation(res1);

                    cout<<"Η Κράτηση " << res1->getReservationCode()<< " έγινε από τoν πελάτη " <<res1->getClientName()<< " και αφορά " <<res1->getPersons()<< " άτομα, που φτάνουν στις " << res1->getArrival() << " του μήνα και θα μείνουν για " << res1->getStay() << " ημέρες, δηλαδή από τις " << res1->getArrival()<< " μέχρι τις " <<res1->getArrival()-res1->getStay()-1 << " του μήνα."<<'\n';
                    cout<<"Ευχαριστούμε για την προτίμησή σας!!! "<<'\n';

                    break;

            }
            case 2:
            {
                cout<<"Επιλέξατε να ακυρώσετε μια κράτηση"<<'\n'<<'\n';
                cout<<"Πληκτρολογήστε τον κωδικό κράτησης προς ακύρωση :"<<'\n'; //Ακυρωση κρατησης γραφοντας τον κωδικο της κρατησης
                cin>>x5;
                ZeusHotel->cancelReservation(x5);

                break;
            }


            case 3:   //Εκτυπωση πινακα με ολες τις κρατησεις του ξενοδοχειου
            {

                cout<<"Επιλέξατε να γίνει προβολή των κρατήσεων του ξενοδοχείου"<<'\n'<<'\n';
                //ZeusHotel->addReservation(getReservationVector());
                cout<<"Κωδικός Κράτησης" <<'\t' << "Όνομα Πελάτη"<<'\t'<<"Κώδικος Δωματίου "<<'\t'<<'\n';
                for(int i = 0; i<= ZeusHotel->getReservationVector().size()-1; i++)
                {
                    cout<<ZeusHotel->reservationVector[i]->getReservationCode() << '\t'<<'\t'<< ZeusHotel->reservationVector[i]->getClientName() << '\t'<<ZeusHotel->reservationVector[i]->getRoom().getRoomCode()<< '\t'<<'\n';
                }
                //cout<<(S);

                break;

            }

            case 4:            //Εκτυπωση πινακα με τα δωματια του ξενοδοχειου
            {
                cout<<"Επιλέξατε την προβολή δωματίων του ξενοδοχείου";
                ZeusHotel->getRoomVector();
                cout<<"Κωδικός Δωματίου"<<'\t'<<"Πληρότητα"<<'\t'<<"Έσοδα"<<'\t'<<'\n';
                for(int j = 0; j<= ZeusHotel->getRoomVector().size()-1; j++)
                {
                    cout<<ZeusHotel->roomVector[j]->getRoomCode() <<'\t'<<'\t'<< (ZeusHotel->roomVector[j]->Completness())<<'\t'<<'\t'<<ZeusHotel->roomVector[j]->income()<<'\t'<<'\n';
                }
                //cout<<(S1);
                break;
            }

            case 5:        //Προβολη πλανου κρατησεων με την βοηθεια της μεθοδου resPlan()
            {
                cout<<"Επιλέξατε την προβολή του πλάνου κρατήσεων του ξενοδοχείου";
                ZeusHotel->resPlan();
                break;
            }


            case 6:      //Προβολη εσόδων
            {
                 cout<<"Επιλέξατε την προβολή των εσόδων του ξενοδοχείου";
                cout<<"Θα θέλατε να δώσετε συγκεκριμένο δωμάτιο;"<< '\n'<< "     Αν ναι, πληκρολογήστε τον κωδικό του δωματίου που επιθυμείτε:"<<'n'<<"Αν όχι, για καθε περίπτωση πληκτρολογήστε '0'" ;
                cin>>x6; //Προβολη εσόδων συγκεκριμενου δωματιου με συγκεκριμενο κωδικο δωματιου που δινεται απο το πληκτρολογιο
                if (x6==0)
                    cout<<(ZeusHotel->incomeCalc());
                else
                    cout<<(ZeusHotel->incomeCalc(x6)); //Προβολη συνολικων εσόδων του ξενοδοχειου απο ολα τα δωματια
                break;

            }
            case 7:
            {
                cout<<"Επιλεξατε τερματισμό του προγράμματος. Το πρόγραμμα θα τερματιστεί";
                break; //Τερματισμος προγραμματος
            }
            default:
            {
                cout<<"Η επιλογή που είσάγατε δεν είναι διαθέσιμη. Παρακαλώ πληκτρολογήστε μια από τις διαθέσημες επιολές ( 0, 1, 2, 3, 4, 5, 6, 7 )";
                    break;
            }
        }
    }


return 0;
};
