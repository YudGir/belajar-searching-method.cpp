#include <iostream>

using namespace std;

struct Barang {
    int id;
    string nama;
    int harga;
} b[11];

int FungsiRekursifHitungTotalNilaiInventaris (int jumlahBarang) {
    if (jumlahBarang == 0) return 0;
    return b[jumlahBarang - 1].harga + FungsiRekursifHitungTotalNilaiInventaris(jumlahBarang - 1);
}

int main () {
    int banyakBarangUser;

    cout << "Input Barang (List)\n";
    cout << "Berapa banyak barang yang Anda ingin tambahkan? ";
    cin >> banyakBarangUser;

    while (banyakBarangUser < 0 || banyakBarangUser > 10) {
        cout << "Input Anda error! Mohon masukkan banyak barang dari 1-10 saja.\n";
        cin >> banyakBarangUser;
    }

    for (int i = 0; i < banyakBarangUser; i++) {
        cout << "Untuk barang " << i + 1 << ": " << endl;
        cout << "ID    : "; cin >> b[i].id;
        cout << "Nama  : "; cin >> b[i].nama;
        cout << "Harga : "; cin >> b[i].harga;
        cout << "(Lanjut) ....\n";
    }

    for (int i = 0; i < banyakBarangUser - 1; i++) {
        for (int j = 0; j < banyakBarangUser - i - 1; j++) {
            if (b[j].id > b[j+1].id) {
                Barang sementara = b[j];
                b[j] = b[j+1];
                b[j+1] = sementara;
            }
        }
    }

    int pilihMenu;
    cout << "=== MENU UTAMA ===\n";
    cout << "1. Cari barang berdasarkan id\n";
    cout << "2. Cari barang berdasarkan nama\n";
    cout << "3. Lihat total nilai inventaris\n";
    cout << "Ketik nomor menu Anda di sini: "; cin >> pilihMenu;

    switch (pilihMenu) {
        case 1: {
            int cariID;
            cout << "Masukkan ID-nya di sini: "; cin >> cariID;

            int kiri = 0, kanan = banyakBarangUser - 1;
            int indeks = -1;

            while (kiri <= kanan) {
                int mid = kiri + (kanan - kiri)/2;
                
                if (b[mid].id == cariID) {
                    indeks = mid; 
                    break;
                }
                
                if (b[mid].id > cariID) {
                    kanan = mid - 1;
                } else {
                    kiri = mid + 1;
                }
            }

            if (indeks != -1) {
                cout << "Ketemu! Berikut detail barangnya: \n";
                cout << "Nama barang  : " << b[indeks].nama << endl;
                cout << "Harga barang : " << b[indeks].harga << endl;
            } else {
                cout << "Maaf, barang dengan ID " << cariID << " tidak ditemukan.\n";
            }
            break;
        } case 2: {
            string cariNama;
            cout << "Ketik nama barang yang Anda ingin cari: "; cin >> cariNama;

            string ujungNamaBarang = b[banyakBarangUser].nama;
            b[banyakBarangUser].nama = cariNama;
            int i = 0;

            while (b[i].nama != cariNama) {
                i++;
            }

            b[banyakBarangUser].nama = ujungNamaBarang;

            if (i < banyakBarangUser|| b[banyakBarangUser].nama == cariNama) {
                cout << "Ketemu! Nama barang " << cariNama << " beneran tersimpan di dalam program.\n";
            } else {
                cout << "Tidak ditemukan! (Tapi sentinel-nya yang ada)\n";
            }
            break;
        } case 3: {
            int total = FungsiRekursifHitungTotalNilaiInventaris;
            cout << "Total nilai inventaris adalah Rp" << total << endl;
            break;
        }
    }
    


}