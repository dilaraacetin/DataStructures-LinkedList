/**
* @file KromozomDugum.hpp
* @description KromozomListesi bağlı listesinin düğüm dosyasının başlık dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/
#ifndef KromozomDugum_hpp
#define KromozomDugum_hpp

#include <Kromozom.hpp>

class KromozomDugum {
public:
    Kromozom* kromozom;  
    KromozomDugum* sonraki;  
    KromozomDugum(Kromozom* kromozom);
};


#endif