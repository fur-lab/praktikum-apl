#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

#include "data.h"

// CRUD
void Login_Admin (string Admin, string Pw_Admin) ;
void Tambah_Penghuni (Bio_Kos Bk[], int &Panjang) ;
void Data_Penghuni (Bio_Kos Bk[], int Panjang) ;
void Update_Penghuni (Bio_Kos Bk[], int Panjang) ;
void Hapus_Penghuni (Bio_Kos Bk[], int &Panjang) ;

// Sorting
void Sort_Selection_Nama_Asc(Bio_Kos Bk[], int &Panjang) ;
void Tampilkan_Nama_Asc(Bio_Kos Bk[], int Panjang) ;
void Merge_Sort_ID_Desc(Bio_Kos Bk[], int l, int m, int r) ;
void Merge_Sort(Bio_Kos Bk[], int l, int r) ;
void Tampilkan_ID_Desc(Bio_Kos Bk[], int Panjang) ;
void Quick_Sort_Status_Sewa_Desc(Bio_Kos Bk[], int low, int high) ;
void Tampilkan_Status_Sewa_Desc(Bio_Kos Bk[], int Panjang) ;

// Searching
int Cari_ID_Binary (Bio_Kos *Bk, int Panjang,  int Target) ;
void Menu_Cari_ID (Bio_Kos *Bk, int Panjang) ;
void Menu_Cari_Nama (Bio_Kos *Bk, int Panjang) ;

#endif