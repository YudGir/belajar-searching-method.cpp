// #include <iostream>

// using namespace std;

// int main () {
//     int data[] = {10, 15, 35, 40, 60};
//     int banyakElemenArrayData = 5;
//     int angkaUserYangDicari;
//     int indeks = -1;

//     cout << "Hi!\n";
//     cout << "Mau cari angka berapa dari array? ";
//     cin >> angkaUserYangDicari;

//     for (int i = 0; i < banyakElemenArrayData; i++) {
//         if (data[i] == angkaUserYangDicari) {
//             indeks = i;
//             break;
//         }
//     }

//     if (indeks != -1) cout << "Yeay, ketemu.\n";
//     else cout << "Yah, ga ketemu brok!\n";
    
//     ------------------------------- | THIS IS SEQUENTIAL SEARCHING: NON-SENTINEL 
// }

#include <iostream>

using namespace std;

int main () {
    int data[] = {1,2,3,4,5};
    int JumlahElemenArray = 5, i = 0;
    int angkaUserYangDicari; 

    cout << "Hi!\n";
    cout << "Mau cari angka berapa dari array? ";
    cin >> angkaUserYangDicari;

    int angkaTerakhir = data[JumlahElemenArray - 1]; //inisialisasi elemen akhir array = posisi array di paling ujung
    data[JumlahElemenArray - 1] = angkaUserYangDicari; //inisialisasi nilai di ujung array adalah angka yg user cari

    while (data[i] != angkaUserYangDicari) 
        i++; //terus ulangi while-iteration sampai data[i] = angka user yg diinginkan utk dicari

    data[JumlahElemenArray - 1] = angkaTerakhir; //buat ngembaliin nilai array paling terakhir menjadi semestinya

    if (i < JumlahElemenArray - 1 || data[JumlahElemenArray - 1] == angkaUserYangDicari) 
        cout << "mantap, ketemu brok di indeks ke- " << i << ". (AI, Asli Itu) HAHA\n";
    else 
        cout << "yah, ga ketemu brok! (cuman adanya di paling ujung)\n";
}