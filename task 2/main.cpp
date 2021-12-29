#include <iostream>
#include "HashTable.h"
#include "Exceptions/Exception.h"

int main() {
    try {
        HashTable a, b;
        Value Petya(20, 60);
        Value Vasya(18, 55);
        a.insert("petya", Petya);
        b.insert("vasya", Vasya);
        b = a;
        std::cout << b.contains("vasya") << " " << b.contains("petya") << std::endl;
        } catch(Exceptions::Exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
