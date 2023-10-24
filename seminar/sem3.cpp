#include <iostream>

using namespace std;

class FormaGeometrica{
    public:
        string name;
        char* culoare;
        float arie;
        int nrLaturi;

    FormaGeometrica(){                                              //constructor fara parametrii
        (*this).name = "Patrat";
        this->culoare = new char[strlen("rosu") + 1];
        strcpy_s(culoare, strlen("rosu") + 1, "rosu");              //this-pointer. this->deferentiere si indexare
        arie = 4.5;
        nrLaturi = 4;
    }
    ~FormaGeometrica(){                                            //destructor
        if (this->culoare != NULL){
            delete[] this->culoare;
        }
    }
    void modificareArie(float arie){
        this->arie = arie;
    }
    void afisare(){
        cout << "Forma geometrica este " << name << " are aria de " << arie << " are un numar de laturi de " << nrLaturi << " si culoarea " 
        << culoare << endl;
    }
};

FormaGeometrica initFormaGeometrica(){
    FormaGeometrica forma;
    forma.name = "Drptunghi";
    forma.culoare = new char[strlen("galben") + 1];
    strcpy_s(forma.culoare, strlen("galben") + 1, "galben");
    forma.arie = 9.1;
    forma.nrLaturi = 4;
    return forma;
}
void main(){
    FormaGeometrica forma;
    forma.afisare();
    {
        FormaGeometrica forma2;
        forma2.afisare();
    }
    forma.modificareArie(200);
    forma.afisare();
    FormaGeometrica* forme= new FormaGeometrica[3];

    delete[]forma;
}