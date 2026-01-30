#include <iostream>
#include <vector>
#include <algorithm> // A rendezéshez (std::sort)
#include <random>    // Modern véletlenszám-generátor
#include <ctime>     // Az időhöz a seed-eléshez
#include <set>       // Az ismétlődések elkerüléséhez

using namespace std;

// Függvény egy 7 számból álló sorsolás szimulálásához
vector<int> sorsolas() {
    set<int> szamok;
    // Modern véletlenszám-generálás (Mersenne Twister)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 35);

    // Addig generálunk, amíg nincs 7 különböző számunk
    while (szamok.size() < 7) {
        szamok.insert(dis(gen));
    }

    // A szetből vektorba rakjuk, hogy könnyebb legyen rendezni és kiírni
    vector<int> eredmeny(szamok.begin(), szamok.end());
    return eredmeny;
}

void kiir(string nev, vector<int> szamok) {
    cout << nev << " sorsolas nyeroszamai: ";
    for (int i = 0; i < szamok.size(); ++i) {
        cout << szamok[i] << (i == szamok.size() - 1 ? "" : ", ");
    }
    cout << endl;
}

int main() {
    // Magyar karakterek kezelése (Windows konzolon)
    setlocale(LC_ALL, "hu_HU.UTF-8");

    cout << "--- Skandináv Lottó Húzó Program ---" << endl;
    
    // 1. Gépi sorsolás
    vector<int> gepi = sorsolas();
    kiir("GEPI", gepi);

    // 2. Kézi sorsolás
    vector<int> kezi = sorsolas();
    kiir("KEZI", kezi);

    cout << "------------------------------------" << endl;

    return 0;
}