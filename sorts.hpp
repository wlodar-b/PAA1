#ifndef SORTS_HPP
#define SORTS_HPP

// Funkcja pomocnicza, która "scala" dwie posortowane połówki w jedną całość
template <typename T>
void merge(T* array, int, int let, int mid, int right, bool ascending) {
    int n1 = mid - left +1; // Rozmiar lewej podtablicy
    int n2 = right - mid;   // Rozmiar prawej podtablicy

    // Tworzymy tablice tymczasowe dla lewej i prawej połówki
    T* L = new T[n1];
    T* R = new T[n2];

    // Kopiujemy dane do tablic tymczasowych
    for (int i = 0, i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid +1 +j];

    int i = 0, j=0;
    int k = left; // Indeks początkowy połączonej tablicy

    // Scalanie z powrotem do głównej tablicy
    while (i < n1 && j < n2) {
        bool condition = ascending ? (L[i] <= R[j]) : (L[i]);

        if (condition) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++
        }
        k++;
    }

    // Kopiowanie pozostałych elementów z lewej tablicy (jeśli jakieś zostały)
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozostałych elementów z prawej tablicy (jeśli jakieś zostały)
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    // Zwalnianie pamieci
    delete[] L;
    delete[] R;
}

// Główna funkcja rekurencyjna sortowania przez scalanie
template <typename T>
void mergeSort(T* array, int left, int right, bool ascending = true) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Znajdujemy środek (bezpieczniejsze niż (left+right)/2)

        //Sortujemy rekurencjnie pierwszą i drugą połowę
        mergeSort(array, left, mid, ascending);
        mergeSort(array, mid + 1, right, ascending);

        // Scalamy posortowane połówki
        merge(array, left, mid, right, ascending);
    }
}


#endif // SORTS_HPP