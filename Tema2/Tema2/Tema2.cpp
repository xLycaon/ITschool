#include <iostream>
#include<iomanip>
#include<algorithm>
#include<string>

//ex 1
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
            
    }
    return true;
}

//ex 2
int gcc(int a, int b) {
    
    while (b!=0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//ex 3
void marketPrice() {
    int input{};
    double suma = 0.00;
    std::cout << "Alegeti produsele dorite, la finalizare apasati tasta 0: "<<std::endl;
    std::cout << "1. Mere" << std::endl;
    std::cout << "2. Pere" << std::endl;
    std::cout << "3. Banane" << std::endl;
    std::cout << "5. Carne" << std::endl;
    std::cout << "6. Salata" << std::endl;
    std::cout << "7. Paine" << std::endl;
    std::cout << "8. Ciocolata" << std::endl;
    std::cout << "9. Iaurt" << std::endl;
    std::cout << "10. Lapte" << std::endl;
    std::cout << "11. Orez" << std::endl;
    std::cout << "12. Cereale" << std::endl;
    std::cout << "13. Mezeluri" << std::endl;
    std::cout << "14. Vinete" << std::endl;
    std::cout << "15. Morcov" << std::endl;
    std::cout << "16. Cartofi" << std::endl;
    std::cout << "17. Zmeura" << std::endl;
    std::cout << "18. Apa" << std::endl;
    std::cout << "19. Sucuri" << std::endl;
    std::cout << "20. Bere" << std::endl;
    while (std::cin >> input) {
        switch (input) {
        case 1:suma += 2.99; break;
        case 2:suma += 4.99; break;
        case 3:suma += 3.99; break;
        case 4:suma += 7.99; break;
        case 5:suma += 6.99; break;
        case 6:suma += 9.99; break;
        case 7:suma += 2.99; break;
        case 8:suma += 8.99; break;
        case 9:suma += 6.99; break;
        case 10:suma += 10.99; break;
        case 11:suma += 23.99; break;
        case 12:suma += 2.99; break;
        case 13:suma += 6.99; break;
        case 14:suma += 87.99; break;
        case 15:suma += 7.99; break;
        case 16:suma += 11.99; break;
        case 17:suma += 22.99; break;
        case 18:suma += 12.99; break;
        case 19:suma += 15.99; break;
        case 20:suma += 18.99; break;
        default: if (input == 0) break; else std::cout << "Nu exista acest produs!" << std::endl; break;
        }
        if (input == 0) {
            std::cout << "Suma totala este: " << std::fixed << std::setprecision(2) << suma << std::endl;
            break;
        }
    }
    int plata=0;
    std::cout << "Introduceti suma de bani pentru a plati: ";
    std::cin >> plata;
    (suma > plata) ? std::cout << "Nu sunt destui bani, va rog sa puneti produsele inapoi!" : std::cout << "Poftiti restul: " << plata - suma;
}



int main()
{
    std::cout << isPrime(2)<<std::endl; //este prim
    std::cout << gcc(8, 6)<<std::endl; //2
    marketPrice();
}

