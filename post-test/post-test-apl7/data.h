#ifndef DATA_H
#define DATA_H

#define MAX_PENGHUNI_KOS 10

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

extern string Admin ;
extern string Input_Admin ;
extern string Pw_Admin ;
extern string Input_Pw_Admin ;
extern int Kesempatan ;
extern string Program_Jalan ;
extern bool Menu_Admin ;
extern bool Menu_User ;
extern int Pilihan_Login ;
extern int Pilihan_Admin ;
extern int Pilihan_User ;
extern int Input_ID_User ;
extern string Input_Pw_User ;
extern int Panjang ;
extern Bio_Kos Bk [MAX_PENGHUNI_KOS] ;



#endif