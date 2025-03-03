#pragma once

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    virtual void display() const = 0;
    virtual string getCategory() const = 0;
    virtual string getTitle() const = 0;
    virtual ~Book() {}
};

#endif
