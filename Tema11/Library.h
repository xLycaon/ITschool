#pragma once


#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library {
public:
    virtual void addBook(Book* book) = 0;
    virtual void listBooks() const = 0;
    virtual void borrowBook(const string& title) = 0;
    virtual ~Library() {}
};

#endif