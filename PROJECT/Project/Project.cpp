#include <iostream>
#include "../StaticLib1/library.h"
using namespace std;

int main() {
    Library lib;
    initLibrary(lib, "City Library");

    Book b1 = { "Crime and Punishment", "Fyodor Dostoevsky", 1866, 19.90 };
    Book b2 = { "Under the Yoke", "Ivan Vazov", 1894, 14.50 };
    Book b3 = { "1984", "George Orwell", 1949, 17.20 };

    addBook(lib, b1);
    addBook(lib, b2);
    addBook(lib, b3);

    printLibrary(lib);

    cout << "-------------------------" << endl;
    cout << "Average price: " << averagePrice(lib) << endl;

    const Book* oldest = oldestBook(lib);
    if (oldest != nullptr) {
        cout << "-------------------------" << endl;
        cout << "Oldest book:" << endl;
        printBook(*oldest);
    }

    freeLibrary(lib);
}
