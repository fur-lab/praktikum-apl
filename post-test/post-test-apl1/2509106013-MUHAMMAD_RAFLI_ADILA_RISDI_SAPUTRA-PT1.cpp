#include <iostream>
using namespace std ;

int main() {

    // Deklar variabel
    string Nama = "Rafli" ;
    string Input_Nama ;
    string Pw_NIM = "013" ;
    string Input_NIM ;
    int Kesempatan = 3 ;

    int Input_Pilihan ;
    int Input_User ; 

    int Input_Jam ;
    int Input_Menit ;
    int Input_Detik ;

    string Program_Jalan = "y" ;

    // Program 
    system("cls") ;

    cout << "=================================== " << endl ;
    cout << "       Selamat Datang ! " << endl ;
    cout << "===================================  " << endl ;

    while (Kesempatan > 0) {
        cout << "Nama : " << endl ;
        cin >> Input_Nama ;
        cout << "NIM : " << endl ;
        cin >> Input_NIM ;


            
        if (Input_Nama != Nama || Input_NIM != Pw_NIM) {
            cout << "Nama / NIM salah!" << endl ;
            Kesempatan-- ;

        } else {
            break ;
            
        }
    }
    
    if (Kesempatan == 0) {
        return 0 ;
    }
    
    while (Program_Jalan == "y") {

        system("cls") ; 

        cout << "=================================== " << endl ;
        cout << "       Program Konversi Waktu" << endl ;
        cout << "=================================== " << endl ;
        cout << "1. Konversi Jam -> Waktu & Detik" << endl ;
        cout << "2. Konversi Menit-> Jam & Detik" << endl ;
        cout << "3. Konversi Detik -> Jam & Menit" << endl ;
        cout << "4. Selesai" << endl ;
        cout << "-----------------------------------" << endl ;
        cout << "Pilih (1-4) : " << endl ;
        cout << "=================================== " << endl ;

        cin >> Input_User;

        if (Input_User == 1) {
            cout << "Masukan Jam : " << endl ;
            cin >> Input_Jam ;

            int Jam_Menit = Input_Jam * 60 ;
            int Jam_Detik = Input_Jam * 3600 ;

            cout << "Menit : " << Jam_Menit << endl ;
            cout << "Detik : " << Jam_Detik << endl ;
        
        } else if (Input_User == 2) {
            cout << "Masukan Menit : " << endl ;
            cin >> Input_Menit ;

            int Menit_Jam = Input_Menit / 60 ;
            int Menit_Detik = Input_Menit * 60 ;

            cout << "Jam : " << Menit_Jam << endl ;
            cout << "Detik : " << Menit_Detik << endl ;
            

        } else if (Input_User == 3) {
            cout << "Masukan Detik : " << endl ;
            cin >> Input_Detik ;

            int Detik_Jam = Input_Detik / 3600 ;
            int Detik_Menit = Input_Detik / 60 ;

            cout << "Jam : " << Detik_Jam << endl ;
            cout << "Menit : " << Detik_Menit << endl ;

        } 
        else if (Input_User == 4) {
            Program_Jalan = "n" ;

        }else {
            cout << "Pilihan tidak ada !" << endl ;
    }

    if (Program_Jalan == "y") {
        cout << "Apakah anda ingin menggunakan program lagi ? : (y/n)" << endl ;
        cin >> Program_Jalan ;

        } 
    }


    cout << "Terima kasih sudah menggunakan program ini !" << endl ;

    return 0 ;
    }



