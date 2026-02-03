#include "library.h"
#include <iostream>
using namespace std;

void initLibrary(Library& lib, const string& name) {
    lib.name = name;
    lib.books = nullptr;
    lib.count = 0;
}

void freeLibrary(Library& lib) {
    delete[] lib.books;
    lib.books = nullptr;
    lib.count = 0;
}

void addBook(Library& lib, const Book& book) {
    Book* newArr = new Book[lib.count + 1];

    for (int i = 0; i < lib.count; ++i) {
        newArr[i] = lib.books[i];
    }
    newArr[lib.count] = book;

    delete[] lib.books;
    lib.books = newArr;
    lib.count++;
}

void printBook(const Book& book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Year: " << book.year << endl;
    cout << "Price: " << book.price << endl;
}

void printLibrary(const Library& lib) {
    cout << "Library: " << lib.name << endl;
    cout << "Number of books: " << lib.count << endl;
    for (int i = 0; i < lib.count; ++i) {
        cout << "-------------------------" << endl;
        printBook(lib.books[i]);
    }
}

double averagePrice(const Library& lib) {
    if (lib.count == 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < lib.count; ++i) {
        sum += lib.books[i].price;
    }
    return sum / lib.count;
}

const Book* oldestBook(const Library& lib) {
    if (lib.count == 0) {
        return nullptr;
    }

    int minIndex = 0;
    for (int i = 1; i < lib.count; ++i) {
        if (lib.books[i].year < lib.books[minIndex].year) {
            minIndex = i;
        }
    }
    return &lib.books[minIndex];
}