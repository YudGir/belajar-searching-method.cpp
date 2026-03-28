#include <iostream>

using namespace std;

struct Pos {
    string nama;
    int tinggi;
} p[4];

int FungsiRekursifHitungKetinggianSemuaPos (int jumlahPos) {
    if (jumlahPos == 0) return 0;
    return p[jumlahPos - 1].tinggi + FungsiRekursifHitungKetinggianSemuaPos(jumlahPos - 1);
}

int main () {
    int banyakPos, pilihMenu;
    string namaPos;
    bool melanjutkan;

    cout << "Hi!\n";
    cout << "Banyak pos (isi 4): "; cin >> banyakPos;
    cout << "===ISI LIST\n";

    for (int i = 0; i < banyakPos; i++) {
        cout << "Pos " << i + 1 << endl;
        cout << "Nama       : "; cin >> p[i].nama;
        cout << "Tinggi (m) : "; cin >> p[i].tinggi;
        cout << endl;
    }

    do {
    cout << "\n===============\n";
    cout << "MENU UTAMA\n";
    cout << "1. Cari pos\n";
    cout << "2. Lihat rata-rata ketinggian\n";
    cout << "3. Keluar\n";
    cout << "Pilih menu dari nomor 1-3, ketik di sini: ";
    cin >> pilihMenu;

        switch (pilihMenu) {
            case 1: {
                cout << "Cari pos (ketik namanya di sini): "; cin >> namaPos;

                int indeks = -1;
                for (int i = 0; i < banyakPos; i++) {
                    if (p[i].nama == namaPos) {
                        indeks = i;
                        break;
                    }
                }

                if (indeks != -1) {
                    cout << "Pos ditemukan. Ketinggian pos " << p[indeks].nama << " adalah " << p[indeks].tinggi << "m.";
                } else {
                    cout << "Maaf, nama pos yang Anda ketik tidak ditemukan.\n";
                }

                melanjutkan = true;
                break;
            } case 2: {
                int rataRata = FungsiRekursifHitungKetinggianSemuaPos(banyakPos) / banyakPos;
                cout << "Rata-rata ketinggian adalah: " << rataRata << "m\n";
                melanjutkan = true;
                break;
            } case 3: {
                cout << "Program berakhir.\n";
                return 0;
            } 
        }
    } while (melanjutkan == true);
}