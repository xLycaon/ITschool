#include <iostream>


class Cutie {
private:
    double lungime, latime, inaltime;

public:
  
    Cutie(double l, double L, double h) : lungime(l), latime(L), inaltime(h) {}
    
    void afiseazaDimensiuni() const {
        std::cout << "Dimensiuni cutie: " << lungime << " x " << latime << " x " << inaltime << std::endl;
    }

    
    friend class CalcCutie;
};

class CalcCutie {
public:
    static void calculeazaVolum(const Cutie& c) {
        double volum = c.lungime * c.latime * c.inaltime;
        std::cout << "Volumul cutiei este: " << volum << std::endl;
    }

    static void modificaDimensiuni(Cutie& c, double l, double la, double h) {
        c.lungime = l;
        c.latime = la;
        c.inaltime = h;
    }
};


class Persoana {

private:
    std::string nume;
    int varsta;

public:
    Persoana(std::string n,int v) : nume(n),varsta(v) {};

    void afisareInfo() const{
        std::cout << "Nume: " << nume << ", Varsta: " << varsta << " ani" << std::endl;
    }
};

class Angajat : public Persoana {

private:
    std::string job;

public:
    Angajat(std::string n, int v, std::string j) : Persoana(n, v), job(j) {}
    void afisareJob() const {
        std::cout << "Functie ocupata: " << job << std::endl;
    }
};


int main()
{
    Cutie x(3.0, 2.0, 1.5);
    x.afiseazaDimensiuni();
    CalcCutie::calculeazaVolum(x);

    CalcCutie::modificaDimensiuni(x, 5.0, 4.0, 2.5);
    x.afiseazaDimensiuni();
    CalcCutie::calculeazaVolum(x);

    Angajat angajat1("Ion Popescu", 30, "Programator");

    std::cout << "Detalii angajat:" << std::endl;
    angajat1.afisareInfo();
    angajat1.afisareJob();
    return 0;
}
