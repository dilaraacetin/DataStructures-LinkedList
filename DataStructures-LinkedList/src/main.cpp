/**
* @file main.cpp
* @description Ana işlemlerin yapıldığı main metodu.
* @course 2. Öğretim C Grubu
* @assignment 1. Ödev
* @date 26.11.2024
* @author Dilara Çetin dilara.cetin2@ogr.sakarya.edu.tr
*/

#include "Kromozom.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "KromozomListesi.hpp"
using namespace std;

KromozomListesi kromozomListe;


//Caprazlama metodu..
void Caprazlama(int ksecim, int ksecim2) {
    
    if (ksecim <0 || ksecim2 <0 || ksecim > kromozomListe.kromozomSayisi-1 ||ksecim2> kromozomListe.kromozomSayisi-1) {
        cout << "Gecersiz kromozom secimi." << endl;
        return;
    }

    Kromozom* sKromozom1 = kromozomListe.kromozomBul(ksecim);
    Kromozom* sKromozom2 = kromozomListe.kromozomBul(ksecim2);

    Kromozom* yeniKromozom = new Kromozom();
    yeniKromozom->ilkCaprazlama(sKromozom1, sKromozom2);
    Kromozom* yeniKromozom2= new Kromozom();
    yeniKromozom2->ikinciCaprazlama(sKromozom1,sKromozom2);

    kromozomListe.kromozomEkle(yeniKromozom);
    kromozomListe.kromozomEkle(yeniKromozom2);
    
}

//Mutasyon metodu
void Mutasyon(int kSecim, int gSecim)
{
    if(kSecim>kromozomListe.kromozomSayisi-1||kSecim<0)
    {
        cout<<"Gecersiz kromozom sirasi..."<<endl;
    }
    else
    {
        Kromozom* secilenKromozom = kromozomListe.kromozomBul(kSecim);

        if (!secilenKromozom->dugumleriDegistir(gSecim)) 
        {
                cout << "Gecersiz gen sirasi..." << endl;
        }
    }
}

//Ekrana yaz metodu
void EkranaYaz()
{
    int index=0;
        while(index<kromozomListe.kromozomSayisi)
        {
            Kromozom* kromozom=kromozomListe.kromozomBul(index);
            cout<<kromozom->kucukGeniBul()<<" ";
            index++;
        }
}


int main() {

    
    //Dna.txt dosya okuma işlemleri.
    ifstream dosya("Dna.txt");
    if (!dosya.is_open()) {
        cout << "Dosya acilamadi." << endl;
        return 1;
    }
    //Okunan değerlere göre kromozomlar ve kromozom listesi oluşturuluyor...
    string satir;
    while (getline(dosya, satir)) {
        if (!satir.empty()) {
            Kromozom* yeniKromozom = new Kromozom();
            for (char gen : satir) {
                if(gen!=' ')
                    yeniKromozom->olusturDugumler(gen);
            }
            kromozomListe.kromozomEkle(yeniKromozom);
        }
    }
    dosya.close();

    int secim=0;
    
    do{

        system("cls");
        
        cout<<"1- Caprazlama"<<endl;
        cout<<"2- Mutasyon"<<endl;
        cout<<"3- Otomatik Islemler"<<endl;
        cout<<"4- Ekrana Yaz"<<endl;
        cout<<"5- Cikis"<<endl;
        cout<<"Lutfen bir secim yapiniz..."<<endl;
        cin>>secim;
        system("cls");
        
        //Kullanıcının seçimine göre yapılacak işlemlerin kontrolü...
        if(secim==1)
        {
            int kSecim, kSecim2;
            cout << "Hangi kromozomlar uzerinde islem yapacaginizi seciniz:" << endl;
            cin >> kSecim >> kSecim2;
            Caprazlama(kSecim,kSecim2);
            cout<<"Islem tamamlandi."<<endl;    
        }
        else if(secim==2)
        {
            int kSecim, gSecim;
            cout << "Lutfen sirasiyla kromozom ve gen numaralarini giriniz." << endl;
            cin >> kSecim >> gSecim;
            Mutasyon(kSecim,gSecim);
            cout<<"Islem tamamlandi."<<endl;
        }
        else if(secim==3)
        {
            //Islemler.tx dosyasından okuan değerlere göre yapılan islemler... 
            ifstream dosya2("Islemler.txt");
            if (dosya2.is_open())
            {
                string satir;
                char secim2;
                int deger1;
                int deger2;
                while (getline(dosya2, satir))
                {
                    stringstream ss(satir);    
                    ss >> secim2 >> deger1 >> deger2;
                    if (secim2 == 'C')
                    {
                        Caprazlama(deger1, deger2);
                    }
                    else if (secim2 == 'M')
                    {
                        Mutasyon(deger1, deger2);
                    }
                    else
                    {
                        cout << "Gecersiz Islem" << endl;
                    }
                }
            }
            else
            {
                cout << "Dosya acilamadi" << endl;
                return 1;
            }
            cout<<"Islem tamamlandi."<<endl;

        }
        else if(secim==4)
        {
            EkranaYaz();
        }
        else if(secim==5)
        {
            system("cls");
            cout << "Programdan cikiliyor..." << endl;
            return 0;
        }
        else
        {
            cout<<"Gecersiz secim. Lutfen tekrar secim yapiniz..."<<endl;
        }

        getchar();
        getchar();


    } while(secim!=5);

    return 0;

}
