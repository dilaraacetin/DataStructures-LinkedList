/**
* @file KromozomListesi.hpp
* @description KromozomListesi adında bir bağlı liste başlık dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/
#ifndef KromozomListesi_hpp
#define KromozomListesi_hpp
#include <KromozomDugum.hpp>
#include <iostream>
#include <ostream>

class KromozomListesi {    
public:
    int kromozomSayisi;  
    KromozomDugum* ilk; 
    KromozomListesi();
    ~KromozomListesi();
    void kromozomEkle(Kromozom* yeniKromozom);
    void kromozomlariListele();
    Kromozom* kromozomBul(int sira);

};
#endif
