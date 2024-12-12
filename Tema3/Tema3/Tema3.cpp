#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <string>
#include<algorithm>


void populateArray(int array[],int dim) {
    std::srand((int)time(0));
    for (int i = 0; i < dim; i++) {
        array[i] = rand() % 100 + 1;
    }
}

bool findChar(char inp, char arr[],int arrDim) {
    for (int i = 0; i < arrDim; i++)
        if (inp == arr[i])
            return true;
    return false;
}

//Exercitiul 1
void outputArray(const int array[],int dim) {
   const int* index_ptr = array;

   for (int i = 0; i < dim; i++) {
       std::cout << index_ptr[i]<<" ";
   }
   std::cout <<std::endl;

}

//Exercitiul 2
void findFactorial(int n) {
    int produs = 1;
    int* ptr{ &produs };
    for (int i = 1; i <= n; i++) {
        *ptr *= i;
    }
    std::cout << "Factorialul este: " << *ptr << std::endl;
}

//Exercitiul 3
void findC_V(std::string sir) {
    int s_C = 0;
    int s_V = 0;
    int* ptr_C{ &s_C };
    int* ptr_V{ &s_V };
    char vocale[] = { 'a','e','i','o','u'};
    char numere[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    std::transform(sir.begin(),sir.end(),sir.begin(), [](unsigned char c) { return std::tolower(c);}); //sirul o sa aiba numai litere mici

    for (int i = 0; i < sir.size(); i++) {
        if (findChar(sir[i], vocale,5))
            ++*ptr_V;
        else if(sir[i]!=' ' && sir[i]!='\n' && !findChar(sir[i],numere,10))
            ++*ptr_C;
    }
    std::cout << "Sunt " << *ptr_C << " consoane si " << *ptr_V << " vocale" << std::endl;
}

//Exercitiul 4
void outputSortedArray( int array[],const int dim) {
    const int* index_ptr = array;
    std::sort(array, array+dim);

    for (int i = 0; i < dim; i++) {
        std::cout << index_ptr[i] << " ";
    }
    std::cout << std::endl;

}

int main()
{
    int dim;
    std::cout << "Introduceti dimensiunea: " << std::endl;
    std::cin >> dim;
    int* array = new int[dim]; 

    populateArray(array, dim);
    outputArray(array, dim);

    int n;
    std::cout << "Alegeti un numar: " << std::endl;
    std::cin >> n;
    findFactorial(n);

    std::cout << "Introduceti sirul: " << std::endl;
    std::string sir;
    std::cin.ignore();
    getline(std::cin, sir);
    findC_V(sir);

    std::cout << "Sorted Array: ";
    outputSortedArray(array, dim);

}
