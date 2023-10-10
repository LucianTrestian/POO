#include <iostream>

using namespace std;

struct blocuri{
    int numarBloc;
    string numeStrada;
    int numarScara;
    int numarApartamente;
    float inaltimeBloc;
    bool lift;
    char tipBloc;
};

void afisareDate(blocuri bl){
        cout<<"Numar bloc:"<<bl.numarBloc<<"Nume strada:"<<bl.numeStrada<<"Numar scara:"<<bl.numarScara<<"Numar apartamente:"<<bl.numarApartamente<<endl;
        cout<<"Inaltime bloc:"<<bl.inaltimeBloc<<"Are lift?"<<(bl.lift ? "Da" : "Nu")<<"Tip bloc:"<<bl.tipBloc<<endl;
        cout<<endl;}
void coletareDate(int n, blocuri* bl){
    for (int i = 0; i < n; i++) {
        cout << "Introduceti datele pentru blocul " << i+1 << endl;
        bl[i].numarBloc;
        cout << "Nume strada: "; cin >> bl[i].numeStrada;
        cout << "Numar scara: "; cin >> bl[i].numarScara;
        cout << "Numar apartamente: "; cin >> bl[i].numarApartamente;
        cout << "Inaltime bloc: "; cin >> bl[i].inaltimeBloc;
        cout << "Are lift? (1 - Da, 0 - Nu): "; cin >> bl[i].lift;
        cout << "Tip bloc: "; cin >> bl[i].tipBloc;
        bl[i].numarBloc = i+1;}
}

int main() {
    int n; // numarul de blocuri
    cout << "Cate blocuri sunt in total? (nu mai mult de 10):"; cin >> n;
    blocuri* bl = new blocuri[n]; // vector de blocuri
    coletareDate(n, bl);
    int numarCautat;
    while(true){
        cout << "Introduceti numarul blocului cautat sau -1 pentru a opri: "; cin >> numarCautat;
        for (int i = 0; i < n; i++) {
            if (bl[i].numarBloc == numarCautat) {
                afisareDate(bl[i]);
                break;
            }
        }
        if (numarCautat == -1){
            cout << "Programul s-a oprit.";
            break;
        }
        else if (numarCautat > n){
            cout << "Nu exista blocul cu numarul " << numarCautat << endl;}
    }
    return 0;
}
