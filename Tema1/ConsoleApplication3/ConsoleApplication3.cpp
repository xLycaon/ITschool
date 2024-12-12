#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>


//Rezolvare 1 -> 5
void exercitiu_1_5() {
    int myNumber = 50;
    float myNumber1 = 75.5;
    myNumber++;
    myNumber1--;
    int suma = myNumber + myNumber1;
    float sumareal = myNumber1 + myNumber;
    suma *= 5;
    suma /= 12;
    sumareal *= 5;
    sumareal /= 12;
    float rest = sumareal - (int)sumareal;
    std::cout<<"Partea fractionara dupa operatii: "<< rest << '\n';
}



//Rezolvare 6 -> 9
std::string exercitiu_6_9(std::string nume, std::string prenume) {
    std::string nume_complet = nume + " " + prenume;
    std::string sirul_meu = "Acesta este continutul initial al sirului";
    std::cout << sirul_meu << '\n';

    return nume_complet;
}


//Rezolvare 10 (cel mai mic)
unsigned int exercitiu_10_a(unsigned int a, unsigned int b, unsigned int c){
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

//Rezolvare 10 (cel mai mare) 
unsigned int exercitiu_10_b(unsigned int a, unsigned int b, unsigned int c) {
    //unsigned float? incompatibil --> unsigned nu poate stoca float sau double
    //return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);  <-- ternary operator
    return std::max(a,std::max(b,c)); //mai usor :)
}



//Rezolvare 12
void exercitiu_12() {
    const float a = 23.6;
    //a *= 72;  nu inteleg cerinta, --> constante nu pot fi schimbate (capcana?)
    float res = (a > 1500.3) ? a : 1500.3;
    std::cout << "Variabile CONSTANTE nu pot fi schimbate si cum stim ca a = 23.6 afisam: "<< res << '\n';
}


//Rezolvare 13
int exercitiu_13(float y, float z) {
    //nu se pot stoca unsigned float sau double 
    int result = y / z;
    return result;
}



//Rezolvare 15
void exercitiu_15() {
    unsigned int var = 3;
    //shift stanga adica *2
    var <<= 1;  
    std::cout << "Valoare dupa LEFT SHIFT : " << var << '\n';
    //shift dreapta adica /2
    var >>= 1; 
    std::cout << "Valoare dupa RIGHT SHIFT : " << var << '\n';

    unsigned int var1 = 1;

    //copiile lui var
    std::bitset<8> copie_var = var;
    std::bitset<8> copie_var1 = var;
    std::bitset<8> copie_var2 = var;

    //OR
    copie_var = var | var1; 
    std::cout <<(std::bitset<8>)var << " OR  " << (std::bitset<8>)var1 <<" = " <<  copie_var << '\n';

    //AND 
    copie_var1 = var & var1; 
    std::cout << (std::bitset<8>)var << " AND " << (std::bitset<8>)var1 << " = " << copie_var1 << '\n';
    //XOR
    copie_var2 = var ^ var1; 
    std::cout << (std::bitset<8>)var << " XOR " << (std::bitset<8>)var1 << " = " << copie_var2 << '\n';
}

int main()
{
    std::cout << "---------------------------------------" << '\n';
    exercitiu_1_5();
    std::cout << "---------------------------------------" << '\n';

    std::string res = exercitiu_6_9("Marin", "Vlad-Alexandru");
    std::cout << res << '\n';
    std::cout << "---------------------------------------" << '\n';

    

    unsigned int rezultat_10_a = exercitiu_10_a(7, 9, 3);
    std::cout <<"Cel mai mic numar dintre 7, 9, 3 este: "<< rezultat_10_a << '\n';
    std::cout << "---------------------------------------" << '\n';

    unsigned int rezultat_10_b = exercitiu_10_b(72.3, 1387.12344, 6);
    std::cout << "Cel mai mare numar dintre 72.3, 1387.12344, 6 este: " << rezultat_10_b << '\n';
    std::cout << "---------------------------------------" << '\n';

    exercitiu_12();
    std::cout << "---------------------------------------" << '\n';

    int rezultat_13 = exercitiu_13(2379.8909, 11.4);
    std::cout << "Partea intreaga din impartirea 2379.8909/11.4 = " << rezultat_13 << '\n';
    std::cout << "---------------------------------------" << '\n';
    std::cout << "Ex: 14 Varianta 2" << '\n';
    std::cout << "---------------------------------------" << '\n';
    exercitiu_15();
    std::cout << "---------------------------------------" << '\n';

    
    return 0;
}

