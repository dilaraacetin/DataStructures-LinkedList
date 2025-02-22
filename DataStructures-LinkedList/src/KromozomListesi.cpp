/**
* @file KromozomListesi.cpp
* @description KromozomListesi adında bir bağlı liste dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/

#include "KromozomListesi.hpp"
#include <ostream>
#include <iostream>
#include <iomanip>
using namespace std;

KromozomListesi::KromozomListesi() : ilk(nullptr), kromozomSayisi(0) {}

KromozomListesi::~KromozomListesi() {
    KromozomDugum* gecici = ilk;
    while (gecici != nullptr) {
        KromozomDugum* silinecek = gecici;
        delete gecici->kromozom; 
        gecici = gecici->sonraki;
        delete silinecek;
    }
    cout<<"Liste yikici fonksiyon ile serbest birakildi"<<endl;
}

// Kromozom listesine kromozom ekleyen metot...
void KromozomListesi::kromozomEkle(Kromozom* yeniKromozom) {
    KromozomDugum* yeniDugum = new KromozomDugum(yeniKromozom);
    if (ilk == nullptr) {
        ilk = yeniDugum;
    } else {
        KromozomDugum* gecici = ilk;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
    }
    kromozomSayisi++;
}

//Listedeki kromozomları ekrana yazıran metot...
void KromozomListesi::kromozomlariListele() {
    KromozomDugum* gecici = ilk; 
    int index = 1;              
    while (gecici != nullptr) {
        //cout << "Kromozom " << index++ << ": ";
        gecici->kromozom->listeYazdir(); 
        gecici = gecici->sonraki;
        cout<<endl;
    }
}

//Liste üzernden seçilen kromozomu bulan metot...
Kromozom* KromozomListesi::kromozomBul(int sira) {

    KromozomDugum* gecici = ilk;
    for (int i = 0; i < sira; i++) { 
        gecici = gecici->sonraki;
    }
    return gecici->kromozom;
}



