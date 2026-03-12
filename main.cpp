#include "tester.hpp"
#include <iostream>

int main() {
    std::cout << "---PROJEKT PAA: ANALIZA ALGORYTMOW SORTOWANIA ---" << std::endl;
    std::cout << "Inicjalizacja modulu testujacego..." << std::endl;

    // Tworzymy obiekt naszej klasy Tester
    Tester tester;

    // Uruchamiamy program
    tester.runAllTests();

    std::cout << "=== KONIEC PROGRAMU ---" << std::endl;
    return 0;
}