#include "tester.hpp"
#include "datagenerator.hpp"
#include "sorts.hpp"
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

// Funkcja pomocnicza do skopiowania tablicy (zeby każdy algorytm sortował dokładnie te same dane)
void copyArray(int* source, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void Tester::runAllTests() {
    // Zgodnie z instrukcją: rozmiary i ilość tablic
    std::vector<int> sizes = {10000, 50000, 100000, 500000, 1000000};
    int arraysPerCase = 100;

    // Procenty dla tablic częśćiowo posortowanych
    std::vector<double> percentages = {25.0, 50.0, 75.0, 95.0, 99.0, 99.7};
    
    // Otwieramy plik CSV do zapisu
    std::ofstream file("wyniki.csv");
    // Nagłówki kolumn w pliku 
    file << "Rozmiar,Ulozenie,Algorytm,Czas_ms\n";

    std::cout << "Rozpoczynam testy... Tomoze potrwac kilka/kilkanascie minut!";

    for (int size : sizes) {
        std::cout << "Testuje rozmiar: " << size << " elementów..." <<  std::endl;

        // Zmienne do przechowywania średniego czasu z 100 prób
        double totalTimeMerge = 0, totalTimeQuick = 0, totalTimeIntro = 0;

        // --- TEST 1: TABLICE LOSOWE ---
        std::cout << " -> Generowanie i sortowanie 100 tablic losowych..." << std::endl;
        totalTimeMerge = totalTimeQuick = totalTimeIntro = 0;
        for (int i = 0; i <arraysPerCase; i++) {
            int* original = DataGenerator::generateRandom(size);
            int* copy = new int[size];

            // Test Merge Sort
            copyArray(original, copy, size);
            auto start = std::chrono::high_resolution_clock::now();
            
        }
    }
}