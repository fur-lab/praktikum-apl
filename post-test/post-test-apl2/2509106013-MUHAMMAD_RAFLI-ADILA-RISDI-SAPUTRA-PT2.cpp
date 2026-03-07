#include <iostream>
using namespace std ;

string Admin = "Rafli" ;
string Input_Admin ;
string Pw_Admin = "013" ;
string Input_Pw_Admin ;

int Kesempatan = 3 ;
string Program_Jalan = "y" ;
int Pilihan_Login ;


string Input_User ;
string Input_Pw_User ;



struct Tanggal_Mulai {
    int Hari ;
    int Bulan ; 
    int Tahun ;
} ;


struct Bio_Kos  {
    int ID  ;
    string Nama ;
    int No_Kamar ;
    string Status_Sewa ;
    struct Tanggal_Mulai Tanggal_Masuk ;
    
} ;


int main () {
    system("cls") ;

    cout << "=================================== " << endl ;
    cout << "         Silahkan Login " << endl ;
    cout << "===================================  " << endl ;
    cout << " 1. Admin " << endl ;
    cout << " 2. Penghuni " << endl ;
    cout << " 3. Register (Jika anda adalah penghuni baru) " << endl ;
    cout << " 4. Exit " << endl ;
    cin >> Pilihan_Login ;
    
    switch (Pilihan_Login) {
        case 1 :                                // ADMIN
                while (Kesempatan > 0) {
                cout << "Admin : " << endl ;
                cin >> Input_Admin ;
                cout << "Password : " << endl ;
                cin >> Input_Pw_Admin ;


                    
                if (Input_Admin != Admin || Input_Pw_Admin != Pw_Admin) {
                    cout << "Inputan salah !" << endl ;
                    Kesempatan-- ;

                } else {
                    while (Program_Jalan == "y") {

                        system("cls") ; 

                        cout << "=================================== " << endl ;
                        cout << "       Selamat Datang !" << endl ;
                        cout << "=================================== " << endl ;
                        cout << "1. Tambah Penghuni Kos " << endl ;        // CREATE
                        cout << "2. Data Biodata Penghuni Kos  " << endl ; // READ
                        cout << "3. Edit Data Penghuni Kos " << endl ;      // UPDATE
                        cout << "4. Hapus Data Penghuni Kos" << endl ;      // DELETE
                        cout << "5. EXIT " << endl ;   
                        cout << "-----------------------------------" << endl ;
                        cout << "Pilih (1-5) : " << endl ;
                        cout << "=================================== " << endl ;
                        ;
                                }
            }
                            break ;

        case 2 : 
            while (Kesempatan > 0) {
                cout << "Username : " << endl ;
                cin >> Input_User ;
                cout << "Password : " << endl ;
                cin >> Input_Pw_User ;


                    // MASIH BELUM `````
                if (Input_User !=  || Input_Pw_User != ) {
                    cout << "Inputan salah !" << endl ;
                    Kesempatan-- ;

                } else {
                    while (Program_Jalan == "y") {

                        system("cls") ; 

                        cout << "=================================== " << endl ;
                        cout << "       Selamat Datang !" << endl ;
                        cout << "=================================== " << endl ;
                        cout << "1  Biodata Anda    " << endl ;        // READ  
                        cout << "2. Data Penghuni Kos " << endl ;       // SELURUH NAMA DAN ID PENGHUNI
                        cout << "3. Kos Services " << endl ;              // 1. PESAN 2. KRITIK DAN SARAN 3. LAPOR
                        cout << "4. EXIT " << endl ;   
                        cout << "-----------------------------------" << endl ;
                        cout << "Pilih (1-4) : " << endl ;
                        cout << "=================================== " << endl ;
                        ;
                                }
            }
                            break ;
            
        case 3 : 

        case 4 : 
                Program_Jalan = "n" ;
        
        default : 
            cout << "Pilihan Salah !" << endl ; 
            break ; 
    } 
    

    
    if (Kesempatan == 0) {
        return 0 ;
    }
    

    if (Program_Jalan == "y") {
        cout << "Apakah anda ingin menggunakan program lagi ? : (y/n)" << endl ;
        cin >> Program_Jalan ;

        } 
} 


    cout << "Terima kasih sudah menggunakan program ini !" << endl ;

    return 0 ;
    }