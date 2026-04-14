#include <iostream>
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

struct Tanggal_Mulai {
    int Hari ;
    int Bulan ; 
    int Tahun ;
} ;

struct Bio_Kos  {
    int ID  ;
    string Nama ;
    string Tipe_Kamar ;
    int No_Kamar ;
    string Status_Sewa ;
    Tanggal_Mulai Tanggal_Masuk ;
    string Password_User ;
    
} ;

#define MAX_PENGHUNI_KOS 10
int Panjang = 0 ;
Bio_Kos Bk [MAX_PENGHUNI_KOS] ;

///// FUNGSI ADMIN -----------------------------

void Tambah_Penghuni (Bio_Kos Bk[], int &Panjang) {
     // C
    system("cls") ;
    bool Kamar_Terisi_C = false ;

    if (Panjang < MAX_PENGHUNI_KOS) {
        cout << "Masukan ID penghuni baru : " ;
        cin >> Bk[Panjang].ID ;

        cout << "Masukan Nama penghuni baru : " ;
        cin.ignore() ;

        getline(cin, Bk[Panjang].Nama) ;
        cout << "Masukan Tipe Kamar penghuni baru (A / B) : " ;
        cin >> Bk[Panjang].Tipe_Kamar ;

        cout << "Masukan Nomor Kamar penghuni baru (1 - 5) : " ;
        cin >> Bk[Panjang].No_Kamar ;

        for (int i = 0 ; i < Panjang ; i++) {
            if (Bk[i].Tipe_Kamar == Bk[Panjang].Tipe_Kamar && Bk[i].No_Kamar == Bk[Panjang].No_Kamar) {
                Kamar_Terisi_C = true ;
                break ;
            }
        }

        if (Kamar_Terisi_C) {
            cout << "Kamar sudah terisi " << endl ;
            system("pause") ;

        } else {
        cout << "Masukan Status Sewa penghuni baru (Aktif / Tidak Aktif): " ;
        cin >> Bk[Panjang].Status_Sewa ;
        cout << "Masukan Tanggal Masuk penghuni baru : " ;
        cin >> Bk[Panjang].Tanggal_Masuk.Hari ;
        cout << "Masukan Bulan Masuk penghuni baru : " ;
        cin >> Bk[Panjang].Tanggal_Masuk.Bulan ;
        cout << "Masukan Tahun Masuk penghuni baru : " ;
        cin >> Bk[Panjang].Tanggal_Masuk.Tahun ;

        Panjang++ ;
        cout << "Penghuni baru berhasil ditambahkan" << endl ;

        system("pause") ;
        }

    } else {
        cout << "Kamar penuh !" << endl ;
        system("pause") ;
    }
                        

}

void Data_Penghuni (Bio_Kos Bk[], int Panjang) {
    // R
    system("cls") ; 
    if (Panjang == 0) {
        cout << "Belum ada data penghuni " << endl ;
    } else {
        cout << "=================================== " << endl ;
        cout << "       Daftar Penghuni Kos " << endl ;
        cout << "=================================== " << endl ;

        for (int i = 0 ; i < Panjang ; i++) {
            cout << "No. : " << i + 1 << endl ;
            cout << "ID : " << Bk[i].ID << endl ;
            cout << "Nama : " << Bk[i].Nama << endl ;
            cout << "Kamar : " << Bk[i].Tipe_Kamar << Bk[i].No_Kamar << endl ;
            cout << "Status Sewa : " << Bk[i].Status_Sewa << endl ;
            cout << "Tanggal Masuk : " << Bk[i].Tanggal_Masuk.Hari 
            << " \nBulan Masuk :  " << Bk[i].Tanggal_Masuk.Bulan 
            << " \nTahun Masuk : " << Bk[i].Tanggal_Masuk.Tahun << endl ; 
            cout << "=================================== " << endl ;
        } 
    }

    system("pause") ;
    
}

void Update_Penghuni (Bio_Kos Bk[], int Panjang) {
     // U
    system("cls") ; 
    bool Kamar_Terisi_U = false ;
    int ID_Cari_U ;
    bool ID_Ditemukan_U = false ;

    if (Panjang == 0) {
        cout << "Belum ada data Penghuni untuk diubah" << endl ;

    }else {
        cout << "Masukan ID penghuni yang ingin diubah : " ;
        cin >> ID_Cari_U ;

        for (int i = 0 ; i < Panjang ; i++) {
            if (Bk[i].ID == ID_Cari_U) {
                ID_Ditemukan_U = true ;

                cout << "Data Penghuni ditemukan ! " << endl ;

                cout << "Nama : " << Bk[i].Nama << endl ;
                cout << "Tipe Kamar : " << Bk[i].Tipe_Kamar << endl ;
                cout << "Nomor Kamar : " << Bk[i].No_Kamar << endl ;
                cout << "Status Sewa : " << Bk[i].Status_Sewa << endl ;
                cout << "=================================== " << endl ;

                cout << "Masukan Nama baru : " ;
                cin.ignore() ;
                getline(cin, Bk[i].Nama) ;

                cout << "Masukan Tipe Kamar baru (A / B ) : " ;
                cin >> Bk[i].Tipe_Kamar ;

                cout << "Masukan Nomor Kamar baru (1 - 5): " ;
                cin >> Bk[i].No_Kamar ;

                for (int j = 0 ; j < Panjang ; j++) {
                if (j != i && Bk[j].Tipe_Kamar == Bk[i].Tipe_Kamar && Bk[j].No_Kamar == Bk[i].No_Kamar) {
                    Kamar_Terisi_U = true ;
                    break ;
                }
            }

            if (Kamar_Terisi_U) {
                cout << "Kamar sudah terisi " << endl ;

            } else {

                cout << "Masukan Status Sewa baru (Aktif / Tidak Aktif) : " ;
                cin >> Bk[i].Status_Sewa ;

                cout << "Data berhasil diupdate !" << endl ;
                break ;
            }

            }
        }
        if (ID_Ditemukan_U == false) {
            cout << "ID tidak ditemukan !" << endl ;
        }
    }

    system("pause") ;
    
}

void Hapus_Penghuni (Bio_Kos Bk[], int &Panjang) {
    // D
    system("cls") ; 
    int ID_Cari_D ;
    bool ID_Ditemukan_D = false ;

    if (Panjang == 0) {
        cout << "Belum ada data Penghuni untuk dihapus" << endl ;

    }else {
        cout << "=================================== " << endl ;
        cout << "       Daftar Penghuni Kos " << endl ;
        cout << "=================================== " << endl ;

        for (int i = 0 ; i < Panjang ; i++) {
            cout << "No. : " << i + 1 << endl ;
            cout << "ID : " << Bk[i].ID << endl ;
            cout << "Nama : " << Bk[i].Nama << endl ;
            cout << "Kamar : " << Bk[i].Tipe_Kamar << Bk[i].No_Kamar << endl ;
            cout << "Status Sewa : " << Bk[i].Status_Sewa << endl ;
            cout << "Tanggal Masuk : " << Bk[i].Tanggal_Masuk.Hari 
            << " \nBulan Masuk :  " << Bk[i].Tanggal_Masuk.Bulan 
            << " \nTahun Masuk : " << Bk[i].Tanggal_Masuk.Tahun << endl ; 
            cout << "=================================== " << endl ;
        } 
        
            cout << "Masukan ID penghuni yang ingin dihapus : " ;
            cin >> ID_Cari_D ;
            
            for (int i = 0 ; i < Panjang ; i++) {
                if (Bk[i].ID == ID_Cari_D) {
                    ID_Ditemukan_D = true ;

                    for (int j = i ; j < Panjang - 1 ; j++) {
                        Bk[j] = Bk[j+1] ;
                    }

                    Panjang-- ;

                    cout << "Data penghuni berhasil dihapus ! " << endl ;
                    break ;
                }
            }
            if (ID_Ditemukan_D == false) {
                    cout << "ID tidak ditemukan !" << endl ;
                }
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

// Fungsi Sorting ---------------------------------------------
void Sort_Selection_Nama_Asc(Bio_Kos Bk[], int &Panjang) {
    for (int i = 0 ; i < Panjang - 1 ; i++) {
        int indeksMin = i ;

    for (int j = i + 1 ; j < Panjang ; j++) {
        if (Bk[j].Nama < Bk[indeksMin].Nama) {
            indeksMin = j ;
        }
    }

    if (indeksMin != i) {
        swap(Bk[i], Bk[indeksMin]) ;
        }
    }
}

void Tampilkan_Nama_Asc(Bio_Kos Bk[], int Panjang) {
    system("cls") ;

    if (Panjang == 0) {
        cout << "Belum ada data penghuni yag diurutkan !" << endl ;
    } else {
        Sort_Selection_Nama_Asc(Bk, Panjang) ;
        Data_Penghuni(Bk, Panjang) ;
    }
}

void Merge_Sort_ID_Desc(Bio_Kos Bk[], int l, int m, int r) {
    Bio_Kos temp[MAX_PENGHUNI_KOS] ;
    int i = l ; 
    int j = m + 1 ; 
    int k = 0 ; 

    while (i <= m && j <= r) {
        if (Bk[i].ID > Bk[j].ID) {
            temp[k] = Bk[i] ;
            i++ ;
        } else {
            temp[k] = Bk[j] ;
            j++ ;
        }

    k++ ;
    }

    while (i <= m) {
        temp[k] = Bk[i] ;
        i++ ;
        k++ ;
    }

    while (j <= r) {
        temp[k] = Bk[j] ;
        j++ ;
        k++ ;
    }

for (int x = 0 ; x < k ; x++) {
    Bk[l + x] = temp[x] ;
    }
}

void Merge_Sort(Bio_Kos Bk[], int l, int r) {
    if (l < r) {

        int m = (l + r) / 2 ;

        Merge_Sort(Bk, l, m) ;
        Merge_Sort(Bk, m + 1, r) ;

        Merge_Sort_ID_Desc(Bk, l, m, r) ;
    }
}

void Tampilkan_ID_Desc(Bio_Kos Bk[], int Panjang) {
    system("cls") ;

    if (Panjang == 0) {
        cout << "Belum ada data penghuni yag diurutkan !" << endl ;
    } else {
        Merge_Sort(Bk, 0, Panjang -1) ;

        Data_Penghuni(Bk, Panjang) ;
    }
}

void Quick_Sort_Status_Sewa_Desc(Bio_Kos Bk[], int low, int high) {
    if (low >= high) return ;

    int mid = low + (high - low) / 2 ;
    string pivot = Bk[mid].Status_Sewa ;
    int i = low, j = high ;

    while (i <= j) {
        while (Bk[i].Status_Sewa > pivot) {
            i++ ;
        }

        while (Bk[j].Status_Sewa < pivot) {
            j-- ;
        }

        if (i <= j) {
            swap(Bk[i], Bk[j]) ;
            i++ ;
            j-- ;
        }
    }

    if (low < j) {
        Quick_Sort_Status_Sewa_Desc(Bk, low, j) ;
    }

    if (i < high) {
        Quick_Sort_Status_Sewa_Desc(Bk, i, high) ;
    }
}

void Tampilkan_Status_Sewa_Desc(Bio_Kos Bk[], int Panjang) {
    system("cls") ;

    if (Panjang == 0) {
        cout << "Belum ada data penghuni yag diurutkan !" << endl ;
    } else {
        Quick_Sort_Status_Sewa_Desc(Bk, 0, Panjang -1) ;

        Data_Penghuni(Bk, Panjang) ;
    }
}

///// FUNGSI MENU UTAMA -------------

void Login_Admin (string Admin, string Pw_Admin) {
    system("cls") ;                                // ADMIN
    Kesempatan = 3 ;

    while (Kesempatan > 0) {
        cout << "Nama Admin : " << endl ;
        cin >> Input_Admin ;
        cout << "Password : " << endl ;
        cin >> Input_Pw_Admin ;


            
        if (Input_Admin != Admin || Input_Pw_Admin != Pw_Admin) {
            cout << "Inputan salah !" << endl ;
            Kesempatan-- ;

        } else {
            Menu_Admin = true ;
            break ;
                        
    }
}
        
    if (Kesempatan == 0) {
        cout << "Kesempatan habis !" << endl ;
        system("pause") ;
        return;
    }

    while (Menu_Admin) {

    system("cls") ; 

    cout << "=================================== " << endl ;
    cout << "       Selamat Datang !" << endl ;
    cout << "=================================== " << endl ;
    cout << "1. Tambah Penghuni Kos " << endl ;        // CREATE
    cout << "2. Data Biodata Penghuni Kos  " << endl ; // READ
    cout << "3. Edit Data Penghuni Kos " << endl ;      // UPDATE
    cout << "4. Hapus Data Penghuni Kos" << endl ;      // DELETE
    cout << "5. Mengurutkan Nama Ascending" << endl ;      // Asc Nama
    cout << "6. Mengurutkan ID Descending" << endl ;      // Desc ID
    cout << "7. Mengurutkan Status Sewa Descending" << endl ;      // Desc Status Sewa
    cout << "8. Kembali ke Menu Utama " << endl ;   
    cout << "-----------------------------------" << endl ;
    cout << "Pilih (1-8) : " << endl ;
    cout << "=================================== " << endl ;
    cin >> Pilihan_Admin ;

    switch (Pilihan_Admin) {

        case 1 : // C
            Tambah_Penghuni(Bk, Panjang);
            break ;

        case 2 : // R
            Data_Penghuni(Bk, Panjang);
            break ; 


        case 3 : // U
            Update_Penghuni(Bk, Panjang);
            break ; 


        case 4 : // D
            Hapus_Penghuni(Bk, Panjang);
            break ; 

        case 5 : // Asc Nama
            Tampilkan_Nama_Asc(Bk, Panjang) ;
            break ;
        
        case 6 :  // Desc ID
            Tampilkan_ID_Desc(Bk, Panjang) ;
            break ; 

        case 7 : // Desc Status Sewa
            Tampilkan_Status_Sewa_Desc(Bk, Panjang) ;
            break ; 

        case 8 : // MENU UTAMA
            system("cls") ; 
            Menu_Admin = false ;
            break ; 


        default : 
            system("cls") ; 
            cout << "Pilihan Tidak Ada !" << endl ;
            system("pause") ;
            break ;
    }
}
    
}

void Login_User (Bio_Kos Bk[], int Panjang, int &Index_Login) {
    system("cls") ; 
    Kesempatan = 3 ;
    Index_Login = -1 ;

    while (Kesempatan > 0) {
        cout << "ID : " << endl ;
        cin >> Input_ID_User ;
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
        cout << "Pilih (1-3) : " << endl ;
        cout << "=================================== " << endl ;
        cin >> Pilihan_User ;

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
                
                cout << "Bulan Masuk : " ;
                cin >> Bk[Panjang].Tanggal_Masuk.Bulan ;

                cout << "Tahun Masuk : " ;
                cin >> Bk[Panjang].Tanggal_Masuk.Tahun ;

                cout << "Password : " ;
                cin >> Bk[Panjang].Password_User ;


                Panjang++ ;
                cout << "Registrasi Berhasil !" << endl ;

    }

            system("pause") ;
    }

void Terima_Kasih() {
    cout << "=================================== " << endl ;
    cout << "          Terima Kasih !" << endl ;
    cout << "===================================  " << endl ;
}   

//---------------------------------------------------------------------------------------------

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
    cout << "Pilih (1-4) : " << endl ;
    cout << "=================================== " << endl ;
    cin >> Pilihan_Login ;
    
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

    Terima_Kasih() ;
    return 0 ;
    }

