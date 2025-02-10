#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>




std::string toLower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}



class Produs
{
private:
    std::string nume;
    double pret;
    int cantitate;

public:
    Produs(std::string n, double p, int c) : nume(n), pret(p), cantitate(c) {}

    Produs(const Produs &other) : nume(other.nume), pret(other.pret), cantitate(other.cantitate)
    {
        std::cout << "Produs adus din depozit: " << nume << " x" << cantitate << "\n";
    }

    Produs(Produs &&other) noexcept : nume(std::move(other.nume)), pret(other.pret), cantitate(other.cantitate)
    {
        std::cout << "Produs mutat din depozit: " << nume << " x" << cantitate << "\n";
        other.cantitate = 0;
    }

    std::string getNume() const { return nume; }
    double getPret() const { return pret; }
    int getCantitate() const { return cantitate; }

    void setCantitate(int newCantitate)
    {
        if (newCantitate >= 0)
        {
            cantitate = newCantitate;
        }
    }

    bool operator<(int requested) const
    {
        return cantitate < requested;
    }
};



class Magazin
{
private:
    std::vector<Produs> produse; // has-a
public:
    Magazin()
    {
        std::cout << "Bun venit in magazin, urmatoarele produse pot fi gasite pe rafturi:\n";

        produse.emplace_back("Cartofi", 3.5, 10);
        produse.emplace_back("Mere", 4.2, 15);
        produse.emplace_back("Paine", 2.0, 20);
        produse.emplace_back("Lapte", 5.0, 10);
        produse.emplace_back("Zahar", 4.5, 5);
        produse.emplace_back("Ulei", 10.0, 8);
        produse.emplace_back("Cafea", 15.0, 7);
        produse.emplace_back("Oua", 12.0, 12);
        produse.emplace_back("Carne de pui", 25.0, 5);
        produse.emplace_back("Carne de vita", 40.0, 3);
        produse.emplace_back("Cascaval", 30.0, 6);
        produse.emplace_back("Ciocolata", 8.0, 10);
        produse.emplace_back("Pasta de dinti", 9.5, 10);
        produse.emplace_back("Sampon", 15.0, 6);
        produse.emplace_back("Bere", 7.0, 20);
        produse.emplace_back("Vin", 25.0, 4);
        produse.emplace_back("Apa plata", 3.0, 20);
        produse.emplace_back("Faina", 4.0, 10);
        produse.emplace_back("Orez", 5.0, 10);
        produse.emplace_back("Sapun", 6.0, 8);

        for (const auto &prod : produse)
        {
            std::cout << prod.getNume() << " - " << prod.getPret() << " RON - " << prod.getCantitate() << " bucati\n";
        }
    }

    Produs getProdus(std::string nume, int cantitateDorit)
    {
        for (auto &prod : produse)
        {
            if (toLower(prod.getNume()) == toLower(nume))
            {
                if (prod < cantitateDorit)
                {
                    std::cout << "Stoc insuficient! Aducem din depozit...\n";
                    return Produs(std::move(prod.getNume()), prod.getPret(), cantitateDorit);
                }
                else
                {
                    prod.setCantitate(prod.getCantitate() - cantitateDorit);
                    return Produs(prod.getNume(), prod.getPret(), cantitateDorit);
                }
            }
        }
        std::cout << "Produsul nu exista!\n";
        return Produs("", 0, 0);
    }

    void procesareComanda()
    {
        std::vector<Produs> cosCumparaturi;
        double total = 0.0;
        std::string numeProdus;
        int cantitate;

        std::cout << "\nIntroduceti produsele dorite. Scrieti 'gata' pentru finalizare.\n";
        while (true)
        {
            std::cout << "Produs: ";
            std::cin >> numeProdus;
            if (numeProdus == "gata")
                break;

            std::cout << "Cantitate: ";
            std::cin >> cantitate;

            Produs achizitie = getProdus(numeProdus, cantitate);
            if (achizitie.getCantitate() > 0)
            {
                cosCumparaturi.push_back(achizitie);
                total += achizitie.getPret() * achizitie.getCantitate();
            }
        }

        std::cout << "\nTotal de plata: " << std::fixed << std::setprecision(2) << total << " RON\n";
        double sumaPrimita;
        do
        {
            std::cout << "Introduceti suma primita: ";
            std::cin >> sumaPrimita;

            if (sumaPrimita < total)
            {
                std::cout << "Suma insuficienta! Introduceti o suma mai mare.\n";
            }
        } while (sumaPrimita < total);

        double rest = sumaPrimita - total;
        std::cout << "Rest: " << std::fixed << std::setprecision(2) << rest << " RON\n";
        std::cout << "Multumim pentru cumparaturi!\n";
    }

    friend class Produs;
};



int main()
{
    Magazin magazin;
    magazin.procesareComanda();
    return 0;
}
