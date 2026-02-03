#pragma once

#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    double price;
};

struct Library {
    string name;
    Book* books;
    int count;
};

void initLibrary(Library& lib, const string& name);
void freeLibrary(Library& lib);

void addBook(Library& lib, const Book& book);
void printBook(const Book& book);
void printLibrary(const Library& lib);

double averagePrice(const Library& lib);
const Book* oldestBook(const Library& lib);

