#include <iostream>

using namespace std;

class scara {
    public:
        static float gravitatie;
        float inaltime;
        float greutate;
        bool rulanta;
        int nrTrepte;
        void afiseazaactiunea(){
            if(rulanta == true)
                cout << "Este rulanta" << endl;
            else
                cout << "Nu este rulanta. MARS LA PAS!" << endl;
        }
};
float scara::gravitatie = 9.81;

int main(){
    scara s;

    s.nrTrepte = 10;
    s.greutate = 100.98;
    s.inaltime = 10;
    s.rulanta = true;
    s.afiseazaactiunea();
}