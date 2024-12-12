#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <algorithm>

//Ex 1 
int generateRandomVotes() {
    return rand() % 500 + 1; //intre 1 si 500
}

void assignVotes() {
    srand(static_cast<unsigned int>(time(0)));
    int votes = generateRandomVotes();
    std::vector<int> candidati = {0,0,0,0,0}; //o sa fie vector de frecventa (poti si cu static dar ar insemna 5 variabile diferite)
    /*static int x1 = 0
      static int x2 = 0
      static int x3 = 0
      static int x4 = 0
      static int x5 = 0
      */
    
    for (int i = 0; i < votes; i++) {
        int temp = rand() % 5 + 1 ; //intre 1 si 5
        switch (temp) {
        case 1:candidati[0]++; break;
        case 2:candidati[1]++; break;
        case 3:candidati[2]++; break;
        case 4:candidati[3]++; break;
        case 5:candidati[4]++; break;
        default: throw std::exception("INVALID"); return;
        }
    }
    std::cout << "Procentajele sunt urmatoarele:" << std::endl;
    std::cout << "Elena Lasconi\tGeorge Simion\tMarcel Ciolacu\tNicolae Ciuca\tMircea Geoana" << std::endl;
    for (int i = 0; i < candidati.size(); i++) {
        double procentaj = (static_cast<double>(static_cast<double>(candidati[i]) / static_cast<double>(votes))) * 100;
        std::cout <<std::setprecision(4)<<procentaj << "%\t\t";
    }
}

//Ex 2
class Book {
private:
    std::string titlu;
    std::string autor;
public:
    Book(std::string titlu, std::string autor) {
        this->titlu = titlu;
        this->autor = autor;
    }

    //Getter and Setter
    std::string getTitlu() const {
        return titlu;
    }

    std::string getAutor() const {
        return autor;
    }
};

class Library {
private:
    std::vector<std::vector<Book>> carti; 
    std::vector<std::vector<bool>> rezervat; 
    std::vector<std::string> categorii;
public:
    
    //aici o sa generam cartile si le punem pe rafturi
    void populateLibrary() {
        categorii = {
            "Fictiune", "Poezie", "Stiinta", "Istorie", "Literatura clasica"
        };
        carti.push_back({
            Book("Marele Gatsby", "F. Scott Fitzgerald"),
            Book("1984", "George Orwell"),
            Book("Mandrie si prejudecata", "Jane Austen"),
            Book("Crima si pedeapsa", "Fyodor Dostoevsky"),
            Book("To Kill a Mockingbird", "Harper Lee")
            });

        carti.push_back({
            Book("Divina Comedie", "Dante Alighieri"),
            Book("Rasaritul si apusul", "Eminescu"),
            Book("Poeme", "Pablo Neruda"),
            Book("Elegii", "Thomas Hardy"),
            Book("Lirica greaca", "Sappho")
            });

        carti.push_back({
            Book("Mecanica cuantica", "Albert Einstein"),
            Book("Teoria relativitatii", "Albert Einstein"),
            Book("Originea speciilor", "Charles Darwin"),
            Book("O scurta istorie a timpului", "Stephen Hawking"),
            Book("Genealogia moralei", "Friedrich Nietzsche")
            });

        carti.push_back({
            Book("Istoria lumii", "H.G. Wells"),
            Book("Istoria Romaniei", "Nicolae Iorga"),
            Book("De la Razboiul Rece la Europa Unita", "Klaus Schwab"),
            Book("Gauri negre", "John Archibald Wheeler"),
            Book("Razboiul celor două lumi", "H. G. Wells")
            });

        carti.push_back({
            Book("Anna Karenina", "Lev Tolstoi"),
            Book("Mandrie si prejudecata", "Jane Austen"),
            Book("Ion", "Liviu Rebreanu"),
            Book("Frankenstein", "Mary Shelley"),
            Book("Fahrenheit 451", "Ray Bradbury")
            });
        

        
        rezervat.resize(carti.size());
        for (int i = 0; i < carti.size(); ++i) {
            rezervat[i].resize(carti[i].size(), false);
        }
    }
    void showReservation() {
        for (int i = 0; i < carti.size(); i++) {
            std::cout << "Categoria "<<i+1<<": " << categorii[i] << std::endl;
            for (int j = 0; j < carti[i].size();j++) {
                std::cout <<j+1<< ". Titlu: " << carti[i][j].getTitlu() << ", " << (rezervat[i][j] ? "Rezervat" : "Disponibil")
                    << std::endl;
            }
            std::cout << std::endl;
        }
    }

    void reserveBook(int categorie,int numar_carte) {
        if (categorie-1 < 5 && categorie-1 >= 0 && numar_carte-1 < 5 && numar_carte-1 >= 0) {
            if (rezervat[categorie-1][numar_carte-1] == true) {
                std::cout << "Cartea este deja rezervata!" << std::endl;
            }
            else {
                std::cout << "Cartea a fost rezervata cu succes!" << std::endl;
                rezervat[categorie-1][numar_carte-1] = true;
            }
        }
        else {
            std::cout << "Numere invalide!" << std::endl;
        }
    }
    
    void returnBook(int categorie, int numar_carte) {
        if (categorie-1 < 5 && categorie-1 >= 0 && numar_carte-1 < 5 && numar_carte-1 >= 0) {
            if (rezervat[categorie-1][numar_carte-1] == true) {
                std::cout << "Puneti cartea pe randul "<<categorie-1<<" raftul "<<numar_carte-1 << std::endl;
                rezervat[categorie-1][numar_carte-1] = false;
            }
            else {
                std::cout << "Cartea este deja acolo!" << std::endl;
            }
        }
        else {
            std::cout << "Numere invalide!" << std::endl;
        }
    }

};



int main()
{
    int exercitiu;
    std::cout << "Selectati exercitiul:\n1.Voturi\n2.Librarie " << std::endl;
    std::cin>>exercitiu;
    if (exercitiu == 1) {
        assignVotes();
    }
    else if (exercitiu == 2) {
        Library biblioteca;
        biblioteca.populateLibrary();
        std::cout << "Bun venit la Biblioteca noastra.\nAvem la dispozitie urmatoarele carti:\n";
        std::cout << "=======================================================================" << std::endl;
        biblioteca.showReservation();
        std::cout << "=======================================================================" << std::endl;
        bool ok = true;
        while (ok) {
            int n;
            std::cout << "Selectati un numar:\n1. Rezervare\n2. Returnare\n3. Afisare carti si status\n4. Iesire\n";
            std::cin >> n;
            switch (n) {
            case 1:
                std::cout << "Selectati categoria si numarul cartii: " << std::endl;
                int cat, nr;
                std::cin >> cat >> nr;
                biblioteca.reserveBook(cat, nr);
                break;
            case 2:
                std::cout << "Introduceti categoria si numarul cartii imprumutate: " << std::endl;
                int categoria, numar;
                std::cin >> categoria >> numar;
                biblioteca.returnBook(categoria, numar);
                break;
            case 3:
                biblioteca.showReservation();
                break;
            case 4:
                ok = false;
                std::cout << "La revedere!" <<std::endl;
                break;
            default:
                std::cout << "Numar invalid!" << std::endl;
                break;
            }
        }
        

        
    }
    else {
        std::cout << "Invalid";
        return 0;
    }
    return 0;
}
