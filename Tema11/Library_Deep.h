#pragma once


#ifndef Library_Deep_H
#define Library_Deep_H

#include "Library.h"
#include <iostream>
#include <algorithm>

class Library_Deep : public Library {
private:
    vector<Book*> books;
public:
    void addBook(Book* book) override {
        books.push_back(book);
    }

    void listBooks() const override {
        for (const auto& book : books) {
            book->display();
        }
    }

    void borrowBook(const string& title) override {
        auto it = find_if(books.begin(), books.end(), [&title](Book* book) {
            return book->getTitle() == title;
            });

        if (it != books.end()) {
            cout << "Book borrowed: " << title << endl;
            books.erase(it);
        }
        else {
            cout << "Book not found!" << endl;
        }
    }
};

#endif