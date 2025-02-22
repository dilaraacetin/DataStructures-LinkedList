/**
* @file Gen.hpp
* @description Kromozom bağlı listesinin düğüm başlık dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/
#ifndef Gen_hpp
#define Gen_hpp

class Gen
{
public:
    
    Gen(const char& veri);
    ~Gen();
    char veri;
    Gen* sonraki;
    Gen* onceki;

};




#endif