//AAAA

#include <iostream>
using namespace std;

//clas avion
class avion{
public:
    int tip;

    avion(int tip = 0){
        this->tip = tip;
    }
};

//class corabie
class corabie{
public:
    int tip;

    corabie(int tip = 0){
        this->tip = tip;
    }
};

class elicopter_apa: public avion, public corabie{
private:
    string nume;
    int locuri;
    int masa;
    int putere;
public:

    elicopter_apa(): nume(""), locuri(0), masa(0), putere(0){}

    elicopter_apa(elicopter_apa &other){
        avion::tip = other.avion::tip;
        corabie::tip = other.corabie::tip;
        nume = other.nume;
        locuri = other.locuri;
        masa = other.locuri;
        putere = other.putere;
    }

    void creare();
    void afisare();
};

//functia de crearea
void elicopter_apa::creare(){
    int op;
    cout << "Introdu denumirea transportului -> ";
    cin >> nume;

    r1:
    cout << "Alege tipul de transport\n1. Aerian\n2. Marin\n->";
    cin >> op;

    if(op == 1){
        avion::tip = 1;
    }else if(op == 2){
        corabie::tip = 1;
    }else{
        cout << "Optiune gresita\n";
        goto r1;
    }

    cout << "Introdu numarul de locuri -> ";
    cin >> locuri;

    cout << "Introdu masa -> ";
    cin >> masa;

    cout << "Introdu puterea -> ";
    cin >> putere;
}

//functia de afisare
void elicopter_apa::afisare(){
    cout << "Denumirea: " << nume << endl;
    cout << "Tip de transport: ";
    if(avion::tip == 1)
        cout << "aerian\n";
    else if (corabie::tip == 1)
        cout << "marin\n";
    cout << "Numarul de locuri: " << locuri << endl;
    cout << "Masa: " << masa << " kg\n";
    cout << "Putere: " << putere << " CP\n\n";
}

int main(){
    int op, size = 10, n = 0;
    elicopter_apa cls[size];

    while(1){
        cout<<" ----------------------"<<endl;
        cout<<" |1. Creare           |"<<endl;
        cout<<" |2. Afisare          |"<<endl;
        cout<<" |3. Stergere         |"<<endl;
        cout<<" |0. Iesire           |"<<endl;
        cout<<" ----------------------"<<endl;
        cout<<"-> ";
        cin>>op;

        switch(op){
            case 0:{
                cout << "Sfarsit de program\n\n";
                exit (0);
            }
                break;
            case 1:{
                if(n == size){
                    cout << "Este plin\n";
                    break;
                }
                cls[n].creare();
                n++;
            }
                break;
            case 2:{
                if(n == 0){
                    cout << "Este pustiu\n";
                    break;
                }
                for(int i = 0;i < n;i++){
                    cout << "TRANSPORT NR." << i+1 << endl;
                    cls[i].afisare();
                }
            }
                break;
            case 3:{
                if(n == 0){
                    cout << "Este pustiu\n";
                    break;
                }

                int nr;

                for(int i = 0;i < n;i++){
                    cout << "TRANSPORT NR." << i+1 << endl;
                    cls[i].afisare();
                }

                cout << "Introdu numarul - ";
                cin >> nr;

                nr--;
                for(int i = nr;i < n;i++){
                    cls[i] = cls[i+1];
                }
                elicopter_apa temp;
                cls[n-1] = temp;
                n--;
            }
                break;
            default:{
                cout << "Optiune gresita\n\n";
            }
                break;
        }
    }
    return 0;
}













////BBBB
//#include <iostream>
//using namespace std;
//
////      A
////     / \
////    B   C
////     \ /
////      D
//
//class transport{  //A
//protected:
//    string nume;
//    int locuri;
//    int masa;
//    int putere;
//public:
//
//};
//
//class avion:virtual public transport{  //B
//public:
//    int tip;
//
//    avion(int tip = 0){
//        this->tip = tip;
//    }
//};
//
//class corabie:virtual public transport{  //C
//public:
//    int tip;
//
//    corabie(int tip = 0){
//        this->tip = tip;
//    }
//};
//
//class elicopter_apa: public avion, public corabie{  //D
//
//public:
//
//    elicopter_apa(){
//        nume = "";
//        locuri = 0;
//        masa = 0;
//        putere = 0;
//    }
//
//    elicopter_apa(elicopter_apa &other){
//        avion::tip = other.avion::tip;
//        corabie::tip = other.corabie::tip;
//        nume = other.nume;
//        locuri = other.locuri;
//        masa = other.locuri;
//        putere = other.putere;
//    }
//
//    void creare();
//    void afisare();
//};
//
////functia de crearea
//void elicopter_apa::creare(){
//    int op;
//    cout << "Introdu denumirea transportului -> ";
//    cin >> nume;
//
//    r1:
//    cout << "Alege tipul de transport\n1. Aerian\n2. Marin\n->";
//    cin >> op;
//
//    if(op == 1){
//        avion::tip = 1;
//    }else if(op == 2){
//        corabie::tip = 1;
//    }else{
//        cout << "Optiune gresita\n";
//        goto r1;
//    }
//
//    cout << "Introdu numarul de locuri -> ";
//    cin >> locuri;
//
//    cout << "Introdu masa -> ";
//    cin >> masa;
//
//    cout << "Introdu puterea -> ";
//    cin >> putere;
//}
//
////functia de afisare
//void elicopter_apa::afisare(){
//    cout << "Denumirea: " << nume << endl;
//    cout << "Tip de transport: ";
//    if(avion::tip == 1)
//        cout << "aerian\n";
//    else if (corabie::tip == 1)
//        cout << "marin\n";
//    cout << "Numarul de locuri: " << locuri << endl;
//    cout << "Masa: " << masa << " kg\n";
//    cout << "Putere: " << putere << " CP\n\n";
//}
//
//int main(){
//    int op, size = 10, n = 0;
//    elicopter_apa cls[size];
//
//    while(1){
//        cout<<" ----------------------"<<endl;
//        cout<<" |1. Creare           |"<<endl;
//        cout<<" |2. Afisare          |"<<endl;
//        cout<<" |3. Stergere         |"<<endl;
//        cout<<" |0. Iesire           |"<<endl;
//        cout<<" ----------------------"<<endl;
//        cout<<"-> ";
//        cin>>op;
//
//        switch(op){
//            case 0:{
//                cout << "Sfarsit de program\n\n";
//                exit (0);
//            }
//                break;
//            case 1:{
//                if(n == size){
//                    cout << "Este plin\n";
//                    break;
//                }
//                cls[n].creare();
//                n++;
//            }
//                break;
//            case 2:{
//                if(n == 0){
//                    cout << "Este pustiu\n";
//                    break;
//                }
//                for(int i = 0;i < n;i++){
//                    cout << "TRANSPORT NR." << i+1 << endl;
//                    cls[i].afisare();
//                }
//            }
//                break;
//            case 3:{
//                if(n == 0){
//                    cout << "Este pustiu\n";
//                    break;
//                }
//
//                int nr;
//
//                for(int i = 0;i < n;i++){
//                    cout << "TRANSPORT NR." << i+1 << endl;
//                    cls[i].afisare();
//                }
//
//                cout << "Introdu numarul - ";
//                cin >> nr;
//
//                nr--;
//                for(int i = nr;i < n;i++){
//                    cls[i] = cls[i+1];
//                }
//                elicopter_apa temp;
//                cls[n-1] = temp;
//                n--;
//            }
//                break;
//            default:{
//                cout << "Optiune gresita\n\n";
//            }
//                break;
//        }
//    }
//    return 0;
//}
