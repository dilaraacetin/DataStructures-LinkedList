/**
* @file Kromozom.cpp
* @description Kromozom adında bir bağlı liste dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/
#include "Kromozom.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Kromozom::Kromozom() 
{
    ilk=nullptr;
    genSayisi=0;
}

Kromozom::~Kromozom() {
    Gen* gecici = ilk;
    while (gecici != nullptr) {
        Gen* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}

//Kromozom üzerinde Gen oluştur metot...
void Kromozom::olusturDugumler(char deger) {
    Gen* yeni = new Gen(deger);
    if (ilk == nullptr) {
        ilk = yeni;
        
    } 
    else {
        Gen* gecici = ilk;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
    genSayisi++;
}

//Kromozomu ekrana yazdran metot...
void Kromozom::listeYazdir() {
    /*
    Gen* gecici = ilk;
    cout << "-------------------------------" << endl;
    cout << setw(10) << "Adres:" << setw(10) << "Veri:" << setw(15) << "Sonraki:" << endl;
    cout << "-------------------------------" << endl;
    while (gecici != nullptr) {
        cout << setw(10) << gecici << setw(10) << gecici->veri << setw(15) << gecici->sonraki << endl;
        cout << "-------------------------------" << endl;
        gecici = gecici->sonraki;
    }
    */
   Gen* gecici=ilk;
   while(gecici!=nullptr)
   {
    cout<<gecici->veri<<" ";
    gecici=gecici->sonraki;
   }
    
}

//Mutasyon işleminde seçilen geni 'X' yapan metot...
bool Kromozom::dugumleriDegistir(int genSirasi) {
    Gen* gecici = ilk;
    int index = 0;

    while (gecici != nullptr && index != genSirasi) {
        gecici = gecici->sonraki;
        index++;
    }

    if (gecici == nullptr) {
        return false; 
    }

    gecici->veri = 'X';
    return true;
}

//Ekrana yaz işleminde karşılaştırma yaıp kromozomdaki küçük geni bulan metot...
char Kromozom:: kucukGeniBul()
{
    Gen* gecici=ilk;
    int kucukGen= (int)ilk->veri;

    for(int i=genSayisi-1;i>=0;i--)
    {
        gecici= FindPrevByPosition(i);
        if((int)gecici->veri<kucukGen)
        {
            kucukGen=(int)gecici->veri;
            break;
        }
    }
    return (char)kucukGen;

}
Gen* Kromozom::FindPrevByPosition(int position)
{
    if (position < 0 || position > genSayisi)
    {
        throw "Position out of range";
    }
    int index = 0;
    for (Gen* itr = ilk; itr != nullptr; itr = itr->sonraki, index++)
    {
        if (index == position)
        {
            return itr;
        }
    }
    return nullptr;
}

Gen* Kromozom:: dugumGetir(int sira)
{
    if(sira<0||sira>=genSayisi)
            return 0;
        
        Gen* gecici= ilk;
        
        for(int i=0;i<sira;i++)
        {
            gecici=gecici->sonraki;
        }
        return gecici;
}

//Çaprazlama esnasında kullanıcının seçimine göre kromozomları çaprazlaan metot...
void Kromozom::ilkCaprazlama(Kromozom* ilkKromozom, Kromozom* ikinciKromozom) {

    int ilkGenSayisi = ilkKromozom->genSayisi; 
    for (int i = 0; i < ilkGenSayisi / 2; i++) {
        Gen* dugum = ilkKromozom->dugumGetir(i);
        if (dugum != nullptr) { 
            olusturDugumler(dugum->veri);
        }
    }
    

    int ikinciGenSayisi = ikinciKromozom->genSayisi; 
    if(ikinciGenSayisi%2!=0)
    {
        for (int i = (ikinciGenSayisi / 2)+1; i < ikinciGenSayisi; i++) {
        Gen* dugum = ikinciKromozom->dugumGetir(i);
        if (dugum != nullptr) { 
            olusturDugumler(dugum->veri);
        }
    }
    }
    else
    {
        for (int i = ikinciGenSayisi / 2; i < ikinciGenSayisi; i++) {
        Gen* dugum = ikinciKromozom->dugumGetir(i);
        if (dugum != nullptr) { 
            olusturDugumler(dugum->veri);
        }
        }
    }
}

void Kromozom::ikinciCaprazlama(Kromozom* ilkKromozom, Kromozom* ikinciKromozom) {

    int ikinciGenSayisi = ikinciKromozom->genSayisi; 
    for (int i = 0; i < ikinciGenSayisi/2; i++) {
        Gen* dugum = ikinciKromozom->dugumGetir(i);
        if (dugum != nullptr) { 
            olusturDugumler(dugum->veri);
        }
    }

    int ilkGenSayisi = ilkKromozom->genSayisi; 
    if(ilkGenSayisi%2!=0)
    {
        for (int i = (ilkGenSayisi/2)+1; i < ilkGenSayisi; i++) {
        Gen* dugum = ilkKromozom->dugumGetir(i);
        if (dugum != nullptr) { 
            olusturDugumler(dugum->veri);
        }
        }
    }
    else
    {
        for (int i = ilkGenSayisi/2; i < ilkGenSayisi; i++) {
        Gen* dugum = ilkKromozom->dugumGetir(i);
        if (dugum != nullptr) { 
            olusturDugumler(dugum->veri);
        }
        }
    }
 
}











 