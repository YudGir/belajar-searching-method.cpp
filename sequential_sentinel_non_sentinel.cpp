#include <iostream>

using namespace std;

int main () {
    int data[] = {10, 15, 35, 40, 60};
    int banyakElemenArrayData = 5;
    int angkaUserYangDicari;
    int indeks = -1;

    cout << "Hi!\n";
    cout << "Mau cari angka berapa dari array? ";
    cin >> angkaUserYangDicari;

    for (int i = 0; i < banyakElemenArrayData; i++) {
        if (data[i] == angkaUserYangDicari) {
            indeks = i;
        }
    }

    if (indeks != -1) cout << "Yeay, ketemu.\n";
    else cout << "Yah, ga ketemu brok!\n";
    
    //THIS IS SEQUENTIAL NON-SENTINEL SEARCHING
}