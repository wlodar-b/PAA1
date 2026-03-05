// Zabezpieczenie przed wielokrotnym dołączeniem tego samego pliku
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream> // bibliotegka do wypisywania tekstu na ekran

// Szablon funkcji - pozwala funkcji przyjmować tablice dowonlego typu (np. int, float, double)
template <typename T> 
bool isSorted(T* array, int size, bool ascending = true) {
    
    // Przechodzimy pętlą przez całą tablicę (do przedostatniego elementu)
     for (int i = 0; i < size -1; i++) {

        // Jeśli sprawdzamy sortowanie rosnące
        if (ascending) {
            // Jeśli obecny element jest większy od następnego, tablica nie jest posortowana rosnąco
            if (array[i] > array[i + 1]) {
                return false;
            }   
        }
        // Jeśli sprawdzamy sortowanie malejące
        else { 
            // Jeśli obecny element jest mniejszy od następnego, tablica nie jest posortowana malejąco
            if (array[i] < array[i + 1]) {
                return false;
            }
        }
     }

     // Jeśli pętla przeszła do końca i nie znalazlła błędów, tablica jest posortowana 
     return true;
}

#endif // Koniec zabezpieczenia pliku