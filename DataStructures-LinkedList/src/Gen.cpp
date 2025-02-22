/**
* @file Gen.cpp
* @description Kromozom bağlı listesinin düğüm dosyası.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/

#include "Gen.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
Gen::Gen(const char& veri)
{
    this->veri=veri;
    onceki=sonraki=0;
}
Gen::~Gen(){}