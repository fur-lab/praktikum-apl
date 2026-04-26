#include <iostream>
#include <string>
using namespace std ;

#include "data.h"
#include "admin.h"
#include "user.h"

#include <iostream>
#include <string>
using namespace std ;

string Admin = "Rafli" ;
string Input_Admin ;
string Pw_Admin = "013" ;
string Input_Pw_Admin ;

int Kesempatan = 3 ;
string Program_Jalan = "y" ;
bool Menu_Admin = false ;
bool Menu_User = false ;

int Pilihan_Login ;
int Pilihan_Admin ;

int Input_ID_User ;
string Input_Pw_User ;
int Pilihan_User ;
int Panjang = 0 ;
Bio_Kos Bk [MAX_PENGHUNI_KOS] ;

void Terima_Kasih() {
    cout << "=================================== " << endl ;
    cout << "          Terima Kasih !" << endl ;
    cout << "===================================  " << endl ;
}   

int main () {

    Bk[0] = {100, "Putra", "A", 1, "Aktif", {10, 7, 2022}, "Apaajah"} ;
    Bk[1] = {101, "Ali", "B", 2, "Aktif", {4, 10, 2023}, "mainyukkk"} ;
    Bk[2] = {102, "Opi", "A", 3, "Aktif", {9, 8, 2023}, "23-08-09"} ;
    Bk[3] = {103, "Rudi", "B", 3, "Aktif", {11, 8, 2023}, "rudipakaii"} ;
    Bk[4] = {104, "Edi", "B", 5, "Aktif", {20, 4, 2024}, "Cas_0900"} ;

    Panjang = 5 ; 


while (Program_Jalan == "y") {

    system("cls") ;

    cout << "=================================== " << endl ;
    cout << "         Silahkan Login " << endl ;
    cout << "===================================  " << endl ;
    cout << " 1. Admin " << endl ;
    cout << " 2. Penghuni " << endl ;
    cout << " 3. Register (Jika anda adalah penghuni baru) " << endl ;
    cout << " 4. Exit " << endl ;
    cout << "-----------------------------------" << endl ; 

    try {
        cout << "Pilih (1-4) : " << endl ;
        cout << "=================================== " << endl ;
        cin >> Pilihan_Login ;

        if (cin.fail()) {
            throw invalid_argument("Inputan harus berupa angka !") ;
        }

        if (Pilihan_Login < 0) {
            throw runtime_error("Bilangan harus bernilai positif !") ;
        }

    
        switch (Pilihan_Login) {
            case 1 : 
                Login_Admin(Admin, Pw_Admin);
                break ;

            case 2 :          // User    
                int Index_Login;
                Login_User(Bk, Panjang, Index_Login);
                break ;

            case 3 :
                Registrasi(Bk, Panjang);
                break ; 

            case 4 :            // KEMBALI KE MENU UTAMA
                system("cls") ; 
                Program_Jalan = "n" ;
                break ; 
            
            default : 
                system("cls") ; 
                cout << "Pilihan Salah !" << endl ; 
                system("pause") ;
                break ; 
            } 
    
        }
        
        catch (const invalid_argument& e) {
            cin.clear() ;
            cin.ignore(1000, '\n') ;
            cout << "Error : " << e.what() << endl ;
            system("pause") ;
        }

        catch (const runtime_error& e) {
            cout << "Error : " << e.what() << endl ;
            system("pause") ;
        }

    }
    
    Terima_Kasih() ;
    return 0 ;
    }

