#include <iostream>
using namespace std ;

#include "user.h"

void Login_User (Bio_Kos Bk[], int Panjang, int &Index_Login) {
    system("cls") ; 
    Kesempatan = 3 ;
    Index_Login = -1 ;

    while (Kesempatan > 0) {
        cout << "ID : " << endl ;
        cin >> Input_ID_User ;

        if (cin.fail()) {
            cin.clear() ;
            cin.ignore(1000, '\n') ;
            cout << "ID harus berupa angka dan bilangan positif !" << endl ;
            system("pause") ;
            Kesempatan-- ;
            continue ;
        }

        cout << "Password : " << endl ;
        cin >> Input_Pw_User ;

        for (int i = 0 ; i < Panjang ; i++ ) {

            if (Input_ID_User == Bk[i].ID  && Input_Pw_User ==Bk[i].Password_User) {
                Index_Login = i ;
                break ;
            }
        } 

        if (Index_Login != -1 ) {
            cout << "Login Berhasil !" << endl ;
            Menu_User = true ;
            break ;

        } else {
            cout << "Inputan salah !" << endl ;
            Kesempatan-- ;  
        }

        if (Kesempatan == 0) {
            cout << "Kesempatan habis ! " << endl ;
            system("pause") ;
            return;
        }
    }

        while (Menu_User) {

        system("cls") ; 

        cout << "=================================== " << endl ;
        cout << "       Selamat Datang !" << endl ;
        cout << "=================================== " << endl ;
        cout << "1  Data Anda    " << endl ;        // READ  
        cout << "2. Edit Biodata Anda " << endl ;       // UPDATE
        cout << "3. Kembali ke Menu Utama " << endl ;   
        cout << "-----------------------------------" << endl ;

        try {

            cout << "Pilih (1-3) : " << endl ;
            cout << "=================================== " << endl ;
            cin >> Pilihan_User ;

            if (cin.fail()) {
                    throw invalid_argument("Inputan harus berupa angka !") ;
                }

            if (Pilihan_User < 0) {
                throw runtime_error("Bilangan harus bernilai positif !") ;
            }

            switch (Pilihan_User) {
                case 1 : // READ
                    Data_User(&Bk[Index_Login]);
                    break ;

                case 2 : // UPDATE
                    Edit_Bio_User(&Bk[Index_Login]);
                    break ;


                case 3 : // EXIT
                    system("cls") ; 
                    Menu_User = false ;
                    break ; 


                default :
                    system("cls") ; 
                    cout << "Pilihan Tidak Ada !" << endl ;
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
    
}

void Registrasi (Bio_Kos Bk[], int &Panjang) {
    // Registrasi
            system("cls") ; 
            bool ID_Sama = false ;
            bool Kamar_Terisi_Regis = false ;

            if (Panjang >= MAX_PENGHUNI_KOS) {
                cout << "Kos Sudah Penuh !" << endl ;

            } else {
                cout << "=================================== " << endl ;
                cout << "     Registrasi Penghuni Baru " << endl ;
                cout << "=================================== " << endl ;

                cout << "ID : " ;
                cin >> Bk[Panjang].ID ;

                        if (cin.fail()) {
                            cin.clear() ;
                            cin.ignore(1000, '\n') ;
                            cout << "ID harus berupa angka dan bilangan positif !" << endl ;
                            system("pause") ;
                            return ;
                        }

                for (int i = 0 ; i < Panjang ; i++) {
                    if (Bk[Panjang].ID == Bk[i].ID) {
                        ID_Sama = true ;
                    }
                }

                if (ID_Sama) {
                    cout << "ID sudah digunakan !" << endl ;
                    system("pause") ;
                    return;
                }

                cout << "Nama : " ;
                cin.ignore() ;
                getline(cin, Bk[Panjang].Nama) ;

                cout << "Tipe Kamar (A / B) : " ;
                cin >> Bk[Panjang]. Tipe_Kamar ;

                cout << "Nomor Kamar (1 - 5) : " ;
                cin >> Bk[Panjang].No_Kamar ;

                if (cin.fail()) {
                        cin.clear() ;
                        cin.ignore(1000, '\n') ;
                        cout << "Nomor Kamar harus berupa angka dan bilangan positif !" << endl ;
                        system("pause") ;
                        return ;
                    }

                for (int i = 0 ; i < Panjang ; i++) {
                if (Bk[i].No_Kamar == Bk[Panjang].No_Kamar &&Bk[i].Tipe_Kamar == Bk[Panjang].Tipe_Kamar ) {
                    Kamar_Terisi_Regis = true ;
                    break;
                }
            }

            if (Kamar_Terisi_Regis) {
                cout << "Kamar sudah ditempati !" << endl ;
                system("pause") ;
                return;

            }

                cout << "Tanggal Masuk : " ;
                cin >> Bk[Panjang].Tanggal_Masuk.Hari ;

                if (cin.fail()) {
                    cin.clear() ;
                    cin.ignore(1000, '\n') ;
                    cout << "Hari berupa angka dan bilangan positif !" << endl ;
                    system("pause") ;
                    return ;
                }
                
                cout << "Bulan Masuk : " ;
                cin >> Bk[Panjang].Tanggal_Masuk.Bulan ;

                if (cin.fail()) {
                    cin.clear() ;
                    cin.ignore(1000, '\n') ;
                    cout << "Bulan berupa angka dan bilangan positif !" << endl ;
                    system("pause") ;
                    return ;
                }

                cout << "Tahun Masuk : " ;
                cin >> Bk[Panjang].Tanggal_Masuk.Tahun ;

                if (cin.fail()) {
                    cin.clear() ;
                    cin.ignore(1000, '\n') ;
                    cout << "Tahun berupa angka dan bilangan positif !" << endl ;
                    system("pause") ;
                    return ;
                }

                cout << "Password : " ;
                cin >> Bk[Panjang].Password_User ;


                Panjang++ ;
                cout << "Registrasi Berhasil !" << endl ;
    }

            system("pause") ;
    }


///// FUNGSI USER -----------------------------

void Data_User (Bio_Kos *ptr_Penghuni) {
    // READ
        system("cls") ; 
        cout << "=================================== " << endl ;
        cout << "           Data Anda" << endl ;
        cout << "=================================== " << endl ;

        cout << " ID : " << ptr_Penghuni->ID << endl ;
        cout << " Nama : " << ptr_Penghuni->Nama << endl ;
        cout << " Tipe Kamar : " << ptr_Penghuni->Tipe_Kamar << endl ;
        cout << " Nomor Kamar : " << ptr_Penghuni->No_Kamar << endl ;
        cout << " Status : " << ptr_Penghuni->Status_Sewa << endl ;

        system("pause") ;
    
}

void Edit_Bio_User (Bio_Kos *ptr_Penghuni) {
    // UPDATE
    system("cls") ;
    bool Kamar_Terisi_User = false ;
    cout << "=================================== " << endl ;
    cout << "        Edit Data Anda" << endl ;
    cout << "=================================== " << endl ;
    cout << "NOTE : Jika data tidak ingin diubah, isi dengan data yang sebelumnya !" << endl ;
    cout << "-----------------------------------" << endl ;

    cout << "Nama baru : " << endl ;
    cin.ignore() ;
    getline(cin, ptr_Penghuni->Nama) ;

    cout << "Tipe Kamar Baru (A / B) : " ;
    cin >> ptr_Penghuni->Tipe_Kamar ;

    cout << "Nomor Kamar Baru (1 - 5): " ;
    cin >> ptr_Penghuni->No_Kamar ;

    if (cin.fail()) {
        cin.clear() ;
        cin.ignore(1000, '\n') ;
        cout << "Nomor kamar harus berupa angka dan bilangan positif !" << endl ;
        system("pause") ;
        return ;
    }

    for (int i = 0 ; i < Panjang ; i++) {
        if (&Bk[i] != ptr_Penghuni && Bk[i].No_Kamar == ptr_Penghuni->No_Kamar  &&  Bk[i].Tipe_Kamar == ptr_Penghuni->Tipe_Kamar ) {
            Kamar_Terisi_User = true ;
            break;
        }
    }

    if (Kamar_Terisi_User) {
        cout << "Kamar sudah ditempati !" << endl ;
        system("pause") ;
        return;

    }

    cout << "Password baru : " ;
    cin >> ptr_Penghuni->Password_User ;

    cout << "Data Berhasil Diubah !" << endl ;

    system("pause") ;
    
}
