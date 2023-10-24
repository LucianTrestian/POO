#include <iostream>

using namespace std;

class oras {
    public:
    string nume;
    int populatie;
    float suprafata;
    const int id;
    static string planeta;
    int* varsteLocuitori;
    //constrcutor default
    oras():id(1) {
        this->nume = "NoName";
        this->populatie = 0;
        this->suprafata = 0;
        this->varsteLocuitori = NULL;
    }
    //destructor
    ~oras(){
        if(this->varsteLocuitori != NULL){
            delete[] this->varsteLocuitori;
        }
    }
    void afisare(){
        cout << "Numele orasului este " << this->nume << " se afla pe planeta "<< oras::planeta << " si are " << this->populatie << " locuitori"
        "Suprafata orasului este " << this->suprafata << " km patrati" << " varsta locuitorilor este ";
        if (populatie == 0)
            cout << "-";
        else{
            for(int i = 0; i < this->populatie; i++){
                cout << this->varsteLocuitori[i] << " ";
        }}
        cout << endl;
    }
    oras(string nume,float suprafata):id(4){
        this->nume = nume;
        this->suprafata = suprafata;
        this->populatie = 0;
        this->varsteLocuitori = NULL;
    }
    //constructor cu parametri
    oras(string nume, int populatie, float suprafata, int* varsteLocuitori, int id):id(id){
        this->nume = nume;
        this->populatie = populatie;
        this->suprafata = suprafata;
        this->varsteLocuitori = new int[populatie];
        for(int i = 0; i < populatie; i++){
            this->varsteLocuitori[i] = varsteLocuitori[i];
        }
    }
    float getmedieVarste(){
        int suma = 0;
        if (this->populatie == 0)
            return 0;
        for(int i = 0; i < this->populatie; i++){
            suma += this->varsteLocuitori[i];
        }
        return suma/(float) this->populatie;
    }
    //se muta un nou locuitor in oras
    void adaugalocuitorNou(int varsta){
        int* varsteNoi = new int[this->populatie + 1];
        for(int i = 0; i < this->populatie; i++){
            varsteNoi[i] = this->varsteLocuitori[i];
        }
        varsteNoi[this->populatie] = varsta;
        this->populatie++;
        delete[] this->varsteLocuitori;
        this->varsteLocuitori = varsteNoi;
    }
    //nou nascut
    void nouNascut(){
        this->adaugalocuitorNou(0);
    }
    //modificam planeta
    static void setPlaneta(string planeta){
        oras::planeta = planeta; 
    }
};
string oras::planeta = "Pamant";


void main(){
    oras oras1;
    oras1.afisare();
    int* varste = new int[2]{31,2};
    oras* oras2 = new oras("Bucuresti", 2, 200, varste, 2);
    oras oras3("Iasi", 3, 100, varste, 3);
    oras::setPlaneta("Marte");
    oras2->afisare();
    oras3.afisare();
    oras oras4("Cluj", 4.1);
    oras4.afisare();
    cout<<"medie varsta: "<<oras2->getmedieVarste()<<endl;
    oras2->adaugalocuitorNou(0);
    cout<<"medie varsta: "<<oras2->getmedieVarste()<<endl;
    delete[]oras2;
}