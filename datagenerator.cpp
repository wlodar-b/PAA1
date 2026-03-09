#include "datagenerator.hpp"
#include <random>    // Nowoczesna biblioteka C++ do generowania liczb losowych
#include <algorithm> // Zawiera std::sort i std::greater (przydatne do przygotowania danych)

int* DataGenerator::generateRandom(int size) {
    // Rezerwujemy pamięć na nową tablicę o podanym rozmiarze
    int* array = new int[size];

    // Konfiguracja nowoczesnego generatora liczb losowych (Mersenne Twister)
    std::random_device rd;
    std::mt19937 gen(rd());
    // Chcemy liczby całkowite np. z zakresu od 1 do 1 000 000
    std::uniform_int_distribution<int> dist(1, 1000000);

    for (int i = 0; i < size; i++) {
        array[i] = dist(gen);
    }

    return array;
}

int* DataGenerator::generatePartiallySorted(int size, double percentage) {
    // Najpierw generujemy całkowicie losową tablicę, używając funkcji wyżej
    int* array = generateRandom(size);

    // Obliczamy, ile elementów (od początku) musimy posortować
    int elementsToSort = static_cast<int>(size * (percentage / 100.0));

    // Używamy WBUDOWANEGO sortowania z C++ do przygotowania danych.
    // (Nie musimy używać tu naszych algorytmów, bo to tylko etap tworzenia testów)
    std::sort(array, array + elementsToSort);

    return array;
}

int* DataGenerator::generateReverseSorted(int size) {
    // Znów zaczynamy od losowej tablicy
    int* array = generateRandom(size);

    // Sortujemy CAŁĄ tablicę, ale używamy std::greater<int>(),
    // co wymusza sortowanie malejące (odwrotne)
    std::sort(array, array + size, std::greater<int>());

    return array;
}