/**
* @file KromozomDugum.cpp
* @description KromozomListesi bağlı listesinin düğüm dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/
#include "KromozomDugum.hpp"
#include <iostream>
KromozomDugum::KromozomDugum(Kromozom* kromozom)
        : kromozom(kromozom), sonraki(nullptr) {}