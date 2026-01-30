#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <iomanip>

using namespace std;

// Egy Luxor szelvény generálása (5 oszlop, oszloponként 15-ös tartományok)
vector<vector<int>> szelvenyGeneralas() {
    vector<vector<int>> tabla(5, vector<int>(5));
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < 5; ++i) {
        int min = i * 15 + 1;
        int max = (i + 1) * 15;
        
        set<int> oszlopSzamok;
        while (oszlopSzamok.size() < 5) {
            uniform_int_distribution<> dis(min, max);
            oszlopSzamok.insert(dis(gen));
        }

        vector<int> rendezett(oszlopSzamok.begin(), oszlopSzamok.end());
        for (int j = 0; j < 5; ++j) {
            tabla[j][i] = rendezett[j];
        }
    }
    tabla[2][2] = 0; // A középső mező a Luxorban "lóhere", azaz alapból kijelölt
    return tabla;
}

void tablaKiir(const vector<vector<int>>& tabla) {
    cout << "\nAz On Luxor szelvenye:\n";
    cout << "---------------------\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (tabla[i][j] == 0) cout << "  X ";
            else cout << setw(3) << tabla[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------\n";
}

int main() {
    setlocale(LC_ALL, "hu_HU.UTF-8");
    
    vector<vector<int>> szelveny = szelvenyGeneralas();
    tablaKiir(szelveny);

    // Sorsolás szimulálása 1-75-ig
    vector<int> golyok;
    for (int i = 1; i <= 75; ++i) golyok.push_back(i);
    
    random_device rd;
    mt19937 gen(rd());
    shuffle(golyok.begin(), golyok.end(), gen);

    cout << "\nA sorsolas megkezdodott...\n";
    for (int i = 0; i < 20; ++i) { // Első 20 szám kiírása példaként
        cout << golyok[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    
    cout << "\n\n(A szimulacio a teljes sorsolashoz kesz.)" << endl;

    return 0;
}