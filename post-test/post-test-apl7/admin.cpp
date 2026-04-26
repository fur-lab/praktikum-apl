#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

#include "admin.h"

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
    cout << "8. Cari berdasarkan ID " << endl ;     // Cari ID Binary
    cout << "9. Cari berdasarkan Nama " << endl ;   // Cari Nama Linear
    cout << "10. Kembali ke Menu Utama " << endl ;   
    cout << "-----------------------------------" << endl ;

    try {
        cout << "Pilih (1-10) : " << endl ;
        cout << "=================================== " << endl ;
        cin >> Pilihan_Admin ;

        if (cin.fail()) {
                    throw invalid_argument("Inputan harus berupa angka !") ;
                }

        if (Pilihan_Admin < 0) {
            throw runtime_error("Bilangan harus bernilai positif !") ;
        }
        

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
            
            case 8 : // Cari ID
                Menu_Cari_ID(Bk, Panjang) ;
                break ; 

            case 9 : // Cari Nama
                Menu_Cari_Nama(Bk, Panjang) ;
                break ; 

            case 10 : // MENU UTAMA
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

void Tambah_Penghuni (Bio_Kos Bk[], int &Panjang) {
     // C
    system("cls") ;
    bool Kamar_Terisi_C = false ;

    if (Panjang < MAX_PENGHUNI_KOS) {
        cout << "Masukan ID penghuni baru : " ;
        cin >> Bk[Panjang].ID ;

        if (cin.fail()) {
            cin.clear() ;
            cin.ignore(1000, '\n') ;
            cout << "ID berupa angka dan bilangan positif !" << endl ;
            system("pause") ;
            return ;
        }

        cout << "Masukan Nama penghuni baru : " ;
        cin.ignore() ;

        getline(cin, Bk[Panjang].Nama) ;
        cout << "Masukan Tipe Kamar penghuni baru (A / B) : " ;
        cin >> Bk[Panjang].Tipe_Kamar ;

        cout << "Masukan Nomor Kamar penghuni baru (1 - 5) : " ;
        cin >> Bk[Panjang].No_Kamar ;

        if (cin.fail()) {
                cin.clear() ;
                cin.ignore(1000, '\n') ;
                cout << "Nomor kamar harus berupa angka dan bilangan positif !" << endl ;
                system("pause") ;
                return ;
        }

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

        if (cin.fail()) {
            cin.clear() ;
            cin.ignore(1000, '\n') ;
            cout << "Hari berupa angka dan bilangan positif !" << endl ;
            system("pause") ;
            return ;
        }
        
        cout << "Masukan Bulan Masuk penghuni baru : " ;
        cin >> Bk[Panjang].Tanggal_Masuk.Bulan ;

        if (cin.fail()) {
            cin.clear() ;
            cin.ignore(1000, '\n') ;
            cout << "Bulan berupa angka dan bilangan positif !" << endl ;
            system("pause") ;
            return ;
        }

        cout << "Masukan Tahun Masuk penghuni baru : " ;
        cin >> Bk[Panjang].Tanggal_Masuk.Tahun ;

        if (cin.fail()) {
            cin.clear() ;
            cin.ignore(1000, '\n') ;
            cout << "Tahun berupa angka dan bilangan positif !" << endl ;
            system("pause") ;
            return ;
        }

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

        if (cin.fail()) {
            cin.clear() ;
            cin.ignore(1000, '\n') ;
            cout << "ID berupa angka dan bilangan positif !" << endl ;
            system("pause") ;
            return ;
        }

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

                if (cin.fail()) {
                    cin.clear() ;
                    cin.ignore(1000, '\n') ;
                    cout << "Nomor kamar harus berupa angka dan bilangan positif !" << endl ;
                    system("pause") ;
                    return ;
                }

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

            if (cin.fail()) {
                    cin.clear() ;
                    cin.ignore(1000, '\n') ;
                    cout << "ID harus berupa angka dan bilangan positif !" << endl ;
                    system("pause") ;
                    return ;
                }
            
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

// FUNGSI SEARCHING ----------------
int Cari_ID_Binary (Bio_Kos *Bk, int Panjang,  int Target) { // Binary search cari ID
    int low = 0 ;
    int high = Panjang - 1 ;

    while (low <= high) {
        int mid = low + (high - low) / 2 ; 

        if (Bk[mid].ID == Target) {
            return mid ;

        } else if (Bk[mid].ID < Target) {
            high = mid - 1 ;

        } else {
            low = mid + 1 ;
            }
        }
        
    return -1 ;
}

void Menu_Cari_ID (Bio_Kos *Bk, int Panjang) {
    int Target ;
    system("cls") ;

    if (Panjang == 0) {
        cout << "Data masih kosong" ;
        system("pause") ;
        return ;
    }

    Bio_Kos Bk_Temp [MAX_PENGHUNI_KOS] ;
    for (int i = 0 ; i < Panjang ; i++) {
        Bk_Temp[i] = Bk[i] ;
    }

    Merge_Sort(Bk_Temp, 0, Panjang - 1) ;

    cout << "=================================== " << endl ;
    cout << "            CARI ID        " << endl ;
    cout << "=================================== " << endl ;
    cout << "Masukan ID yang ingin dicari : " ; cin >> Target ;

    if (cin.fail()) {
        cin.clear() ;
        cin.ignore(1000, '\n') ;
        cout << "ID harus berupa angka dan bilangan positif !" << endl ;
        system("pause") ;
        return ;
    }
    
    int Hasil = Cari_ID_Binary(Bk_Temp, Panjang, Target) ;

    if (Hasil != -1) {
        system("cls") ;
        cout << "ID ditemukan !" << endl ;
        cout << "------------------------------" << endl ;
        cout << " ID : " << Bk_Temp[Hasil].ID << endl ;
        cout << " Nama : " << Bk_Temp[Hasil].Nama << endl ;
        cout << " Tipe Kamar : " <<Bk_Temp[Hasil].Tipe_Kamar << endl ;
        cout << " Nomor Kamar : " << Bk_Temp[Hasil].No_Kamar << endl ;
        cout << " Status : " << Bk_Temp[Hasil].Status_Sewa << endl ;

        system("pause") ;

    } else {
        cout << "ID tidak ditemukan dalam data ! " << endl ;
        system("pause") ;
    }
}


int Cari_Nama_Linear (Bio_Kos *Bk, int Panjang, string Target) {
    for (int i = 0 ; i < Panjang ; i++) {
        if (Bk[i].Nama == Target) {
            return i ;
            break ;
            }
        }

    return -1 ; 
}

void Menu_Cari_Nama (Bio_Kos *Bk, int Panjang) {
    string Target ;
    system("cls") ;

    if (Panjang == 0) {
        cout << "Data masih kosong" ;
        system("pause") ;
        return ;
    }

    cout << "=================================== " << endl ;
    cout << "            CARI NAMA       " << endl ;
    cout << "=================================== " << endl ;
    cout << "Masukan Nama yang ingin dicari : " ; cin >> Target ;
    
    int Hasil = Cari_Nama_Linear(Bk, Panjang, Target) ;

    if (Hasil != -1) {
        system("cls") ;
        cout << "Nama ditemukan !" << endl ;
        cout << "------------------------------" << endl ;
        cout << " ID : " << Bk[Hasil].ID << endl ;
        cout << " Nama : " << Bk[Hasil].Nama << endl ;
        cout << " Tipe Kamar : " <<Bk[Hasil].Tipe_Kamar << endl ;
        cout << " Nomor Kamar : " << Bk[Hasil].No_Kamar << endl ;
        cout << " Status : " << Bk[Hasil].Status_Sewa << endl ;

        system("pause") ;

    } else {
        cout << "Nama tidak ditemukan dalam data ! " << endl ;
        system("pause") ;
    }
}