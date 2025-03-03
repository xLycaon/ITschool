#include <iostream>
#include "Book_Deep.h"
#include "Library_Deep.h"
using namespace std;

int main() {
    Library_Deep library;

    library.addBook(new Book_Deep("1984", "George Orwell", 1949, "Beletristica"));
    library.addBook(new Book_Deep("Sapiens", "Yuval Noah Harari", 2011, "Istorie"));
    library.addBook(new Book_Deep("Clean Code", "Robert C. Martin", 2008, "Bibliografie"));

    cout << "Available books:\n";
    library.listBooks();

    cout << "\nBorrowing '1984':\n";
    library.borrowBook("1984");

    cout << "\nBooks after borrowing:\n";
    library.listBooks();

    return 0;
}