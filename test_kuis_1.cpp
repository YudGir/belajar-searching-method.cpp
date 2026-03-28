//SISTEM MANAJEMEN INVENTARIS GUDANG

#include <iostream>

using namespace std;

struct item {
    int id;
    string nama;
    int stok;
};

item it[11];

int FungsiRekursifTotalStok (int jumlahItem) {
    if (jumlahItem == 0) return 0;
    return it[jumlahItem - 1].stok + FungsiRekursifTotalStok(jumlahItem - 1);        
}

int main () {
    int userMemilihMenu, banyakItemUser, idItemDicari;
    bool kembaliKeMenu = true;
    string namaItemDicari;

    cout << "[NOTE]: Ada dua submenu pada program: Input dan Proses\n";
    cout << "        Jadi, program akan mengarahkan Anda terlebih dahulu untuk Input, lalu pergi ke Proses.\n";
    
    cout << "Submenu: INPUT";
    cout << "Ada berapa item yang Anda ingin simpan ke dalam program? ";
    cin >> banyakItemUser;

    while (banyakItemUser < 0 || banyakItemUser > 10) {
        cout << "Maaf. Jumlah item yang Anda simpan sepertinya bermasalah. Coba dari 1-10 saja!\n";
        cin >> banyakItemUser;
    }

    if (banyakItemUser > 0 || banyakItemUser <= 10) 
        cout << "Baik. Lanjut ke dalam input-an-nya. \n";

    for (int i = 0; i < banyakItemUser; i++) {
        cout << "Untuk item-" << i + 1 << ":";
        cout << "Id item: "; cin >> it[i].id;
        cout << "Nama item: "; cin >> it[i].nama;
        cout << "Stok item: "; cin >> it[i].stok;
        cout << "=======================\n";
    }

    for (int i = 0; i < banyakItemUser - 1; i++) {
        for (int j = 0; j < banyakItemUser - i - 1; j++) {
            if (it[j].id > it[j+1].id) {
                item temp = it[j];
                it[j] = it[j+1];
                it[j+1] = temp; 
            }       
        }
    }

    do {
    cout << "Submenu: PROSES\n";
    cout << "Hai! Selamat datang ke dalam program Sistem Manajemen Inventaris Gudang kami!\n";
    cout << "Ini dia menu yang ada di dalam program: \n";
    cout << "1. Cari nama item\n";
    cout << "2. Cari id item\n";
    cout << "3. Hitung total stok\n";
    cout << "4. Keluar\n";
    cout << "Mau pilih menu yang mana? ";
    cin >> userMemilihMenu;

        switch (userMemilihMenu) {
            case 1: {
                cout << "(Memilih menu: MENCARI NAMA ITEM)\n";
                cout << "Ketik nama item di sini: ";
                cin >> namaItemDicari;

                string namaItemPalingUjung = it[banyakItemUser].nama;
                it[banyakItemUser].nama = namaItemDicari;

                int i = 0;
                while (it[i].nama != namaItemDicari) {
                    i++;
                }

                it[banyakItemUser].nama = namaItemPalingUjung;

                if (i < banyakItemUser || it[i].nama == namaItemDicari) {
                    cout << "Ketemu! Nama item " << namaItemDicari << " tersebut tersimpan di dalam program kami\n";
                } else {
                    cout << "Tidak ditemukan. (Tapi, sentinel ada di ujung)\n";
                }
                
                kembaliKeMenu = true;
                break;
            } case 2: {
                cout << "(Memilih menu: MENCARI ID ITEM)\n";
                cout << "Ketik id item di sini: ";
                cin >> idItemDicari;
                
                int kiri = 0;
                int kanan = banyakItemUser - 1;
                int indeks = -1;

                if (kiri > kanan) {
                    cout << "Maaf, id item: " << idItemDicari << " tidak ada di dalam program ini.\n";
                    break;
                }

                while (kiri <= kanan) {
                int mid = kiri + (kanan - kiri)/2;
                
                    if (it[mid].id == idItemDicari) {
                        indeks = mid;
                        break;
                    } 
                    
                    if (it[mid].id < idItemDicari) {
                        kiri = mid + 1;
                    } else {
                        kanan = mid - 1;
                    }
                }

                if (indeks != -1) { cout << "Ketemu! ID item: " << idItemDicari << " ada di dalam program ini!\n";
                    cout << "Di indeks " << indeks << ".\n";}
                else cout << "ID tidak ditemukan!\n";

                kembaliKeMenu = true;
                break;
            } case 3: {
                cout << "(Memilih menu: MENGHITUNG TOTAL STOK)\n";
                int hasil = FungsiRekursifTotalStok(banyakItemUser);
                cout << "Total seluruh stok item Anda adalah: " << hasil << ". " << endl;
                kembaliKeMenu = true;
                break;
            } case 4: {
                cout << "(Memilih menu: KELUAR)\n";
                kembaliKeMenu = false;
                return 0;
            } default: {
                cout << "Input Anda salah! Mohon input yang benar (1-4)!\n";
                kembaliKeMenu = true;
                break;
            }
        }
    } while (kembaliKeMenu == true);
    
    if (kembaliKeMenu == false) {
        cout << "Program akan berhenti. Terima kasih telah menggunakan program kami!\n";
        return 0;
    }

}