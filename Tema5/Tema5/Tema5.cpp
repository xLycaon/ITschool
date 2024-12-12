#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

//Helper Functions
void populateTemp(std::vector<float>&temp) {
    for (int i = 0; i < 7; i++) {
        temp.push_back(static_cast<float>(rand() % 3000 + 1000) / 100.0f);
    }
    temp.push_back(0);
}

float findMaxTemp(std::vector<float>temp,float max) {
    for (const auto& x : temp) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}


//Ex1 struct
struct statie_meteo {
    std::vector<float>temperaturi;
    float max_Temp = 0;

}statie;


//Ex1 class
class Statie_Meteo {
private:
    std::vector<float>temperaturi;
    float max_Temp = 0;

public:
    void afisare() {
        max_Temp = findMaxTemp(temperaturi, max_Temp);
        for (int i = 0; i < 8; i++) {
            switch (i) {
            case 0:std::cout << "Luni: " << temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
            case 1:std::cout << "Marti: " << temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
            case 2:std::cout << "Miercuri: " << temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
            case 3:std::cout << "Joi: " << temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
            case 4:std::cout << "Vineri: " << temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
            case 5:std::cout << "Sambata: " << temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
            case 6:std::cout << "Duminica: " << temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
            default:std::cout << "Maxima: " << max_Temp << " " << char(248) << "C" << std::endl; break;
            }
        }
    }

    std::vector<float>& getVector() {
        return temperaturi;
    }
};


//Ex2 
class Angajat {
private:
    std::string nume;
    float salariu;
    
    std::vector<int> ore_Saptamana;

    std::string getRandomName() {
        std::vector<std::string> names = { "Alex", "Maria", "Andrei", "Ioana", "Mihai", "Elena", "George", "Alina", "Cristian", "Diana" };
        int randomIndex = rand() % names.size();
        return names[randomIndex];
    }

    void adaugaOre(std::vector<int> &ore){
        for (int i = 0; i < 7; i++) {
            ore.push_back(rand() % 8 + 1);
        }
    }

public:
    Angajat(const std::string& nume_angajat, float salariu) : nume(nume_angajat), salariu(salariu) {
        adaugaOre(this->ore_Saptamana);
        
    }
    Angajat() : nume(getRandomName()) {
        adaugaOre(ore_Saptamana);
        this->salariu = calculateHours(ore_Saptamana);
    }

    void display() const{
        std::cout << "Nume: " << nume << std::endl;
        std::cout << "Salariu: " << salariu << std::endl;
    }

    float calculateHours(const std::vector<int> &ore) {
        int total = 0;
        for (auto& x : ore) {
            total += x;
        }
        return float(0.8 * total * 100);
    }

    const std::string& getNume() const{
        return nume;
    }

    float getSalariu() const{
        return salariu;
    }

    void setSalariu(float x) {
        this->salariu = x;
    }

};


int main()
{
    srand(time(0));
    populateTemp(statie.temperaturi);
    statie.max_Temp = findMaxTemp(statie.temperaturi, statie.max_Temp);
    std::cout << "Temperaturile saptamanii sunt: " << std::endl;
    for (int i = 0; i < 8; i++) {
        switch (i) {
        case 0:std::cout << "Luni: " << statie.temperaturi.at(i) << " " <<char(248)<<"C" << std::endl; break;
        case 1:std::cout << "Marti: " << statie.temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
        case 2:std::cout << "Miercuri: " << statie.temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
        case 3:std::cout << "Joi: " << statie.temperaturi.at(i) <<" "<< char(248) << "C" << std::endl; break;
        case 4:std::cout << "Vineri: " << statie.temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
        case 5:std::cout << "Sambata: " << statie.temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
        case 6:std::cout << "Duminica: " << statie.temperaturi.at(i) << " " << char(248) << "C" << std::endl; break;
        default:std::cout << "Maxima: " << statie.max_Temp << " " << char(248) << "C" << std::endl; break;
        }
    }
    std::cout << "=========================================" << std::endl;

    Statie_Meteo meteo;
    populateTemp(meteo.getVector());
    meteo.afisare();

    std::cout << "=========================================" << std::endl;
    
    Angajat angajat1;
    Angajat angajat2("Radu", 2450);
    std::cout << "Constructor cu parametrii: " << std::endl;
    angajat2.display();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Constructor fara parametrii: " << std::endl;
    angajat1.display();
    


}
