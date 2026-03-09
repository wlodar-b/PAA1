#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

class DataGenerator {
    public:
    // Generuje tablicę wypełnioną całkowicie losowymi liczbami
    static int* generateRandom(int size);

    // Generuje tablicę, w której zadany procent początkowych elementów jest posortowany
    static int* generatePartiallySorted(int size, double percentage);

    // Generuje tablicę całkowicie posortowaną, ale w odwrotnej kolejności (malejąco)
    static int* generateReverseSorted(int size);
};

#endif // DATAGENERATOR_HPP