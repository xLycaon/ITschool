#pragma once

#ifndef Book_Deep_H
#define Book_Deep_H

#include "Book.h"
#include <iostream>

class Book_Deep : public Book {
private:
    string title;
    string author;
    int year;
    string category;
public:
    Book_Deep(string t, string a, int y, string c)
        : title(t), author(a), year(y), category(c) {}

    void display() const override {
        cout << "Title: " << title << ", Author: " << author
            << ", Year: " << year << ", Category: " << category << endl;
    }

    string getCategory() const override { return category; }
    string getTitle() const override { return title; }
};

#endif