// praktikum APL 26 feb 2025
//` ada buffer (cls / pembersih saat spasi) di terminal

#include <iostream>
using namespace std;

int main() {

    int a, b, hasil;

    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;

    // Penjumlahan
    hasil = a + b;
    cout << "Hasil penjumlahan: " << hasil << endl;

    // Pengurangan
    hasil = a - b;
    cout << "Hasil pengurangan: " << hasil << endl;

    // Perkalian
    hasil = a * b;
    cout << "Hasil perkalian: " << hasil << endl;

    // Pembagian
    hasil = a / b;

    cout << "Hasil pembagian: " << hasil << endl;

    // Modulus
    hasil = a % b;
    cout << "Hasil modulus: " << hasil << endl;

    return 0;
}