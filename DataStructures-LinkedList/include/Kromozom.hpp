/**
* @file Kromozom.hpp
* @description Kromozom adında bir bağlı listesinin başlık dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/
#ifndef Kromozom_hpp
#define Kromozom_hpp
#include <Gen.hpp>

class Kromozom
{
public:
    
    Kromozom();
    ~Kromozom();
    void olusturDugumler(char deger);
	void listeYazdir();
    bool dugumleriDegistir(int genSirasi);
    char kucukGeniBul();
    void ilkCaprazlama(Kromozom* ilkKromozom, Kromozom* ikinciKromozom);
    void ikinciCaprazlama(Kromozom* ilkKromozom, Kromozom* ikinciKromozom);
    Gen* dugumGetir(int sira);
    int genSayisi;
    
private:
    Gen* FindPrevByPosition(int position);
    Gen *ilk;
};

#endif