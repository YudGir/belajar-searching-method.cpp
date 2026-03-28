// SISTEM PAPAN SKOR TURNAMEN E-SPORT
#include <iostream>

using namespace std;

struct Tim {
    string nama;
    int skor;
} t[3];

int FungsiRekursifSkorTertinggi (int jumlahTim) {
    if (t[jumlahTim].skor > t[jumlahTim - 1].skor) return t[jumlahTim].skor;
    return FungsiRekursifSkorTertinggi(jumlahTim - 1);
}

int main () {
    int banyakTim;
    cout << "LIST INPUT-AN\n";
    cout << "Ketik angka 3 di sini: "; //memastikan fungsi variabel input maksimal!
    cin >> banyakTim;

    for (int i = 0; i < banyakTim; i++) {
        cout << "Nama tim " << i + 1 << ": "; cin >> t[i].nama;
        cout << "Skor tim " << i + 1 << ": "; cin >> t[i].skor;
        cout << endl;
    }

    for (int i = 0; i < banyakTim - 1; i++) {
        for (int j = 0; j < banyakTim - i - 1; j++) {
            if (t[j].skor < t[j+1].skor) {
                Tim temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }

    cout << "Hasil Akhir: \n";
    for (int i = 0; i < banyakTim; i++) {
        cout << "Juara " << i + 1 << ": " << t[i].nama << endl;
    }
    
    int hasilAkhir = FungsiRekursifSkorTertinggi(banyakTim);
    cout << "Skor tertinggi dalam turnamen ini adalah: " << hasilAkhir;


}