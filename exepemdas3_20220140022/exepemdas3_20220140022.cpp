#include <iostream>
#include <vector>
using namespace std;
#include "Buku.h"
#include "Pengarang buku.h"

class Penerbit;
class Pengarang {
public:
    string nama;
    vector<Penerbit*> daftar_Penerbit;
    Pengarang(string pNama) :nama(pNama) {}

    void tambahPenerbit(Penerbit*);
    void cetakPenerbit();

};

class Penerbit {
public:
    string nama;
    vector<Pengarang*> daftar_Pengarang;


    Penerbit(string pNama) :nama(pNama) { }


    void tambahPengarang(Pengarang*);
    void cetakPengarang();

};

void Pengarang::tambahPenerbit(Penerbit* pPenerbit) {
    daftar_Penerbit.push_back(pPenerbit);
}

void Pengarang::cetakPenerbit() {
    cout << "Daftar Penerbit yang diikuti \"" << this->nama << "\":\n";
    for (auto& a : daftar_Penerbit) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void Penerbit::tambahPengarang(Pengarang* pPengarang) {
    daftar_Pengarang.push_back(pPengarang);
    pPengarang->tambahPenerbit(this);
}

void Penerbit::cetakPengarang() {
    cout << "Daftar Pengarang dari  \"" << this->nama << "\":\n";
    for (auto& a : daftar_Pengarang) {
        cout << a->nama << "\n";
    }
    cout << endl;
}


int main()
{
    Penerbit* varPenerbit1 = new Penerbit("Gama Press");
    Penerbit* varPenerbit2 = new Penerbit("Intan Pariwara");
    Pengarang* varPengarang1 = new Pengarang("Giga");
    Pengarang* varPengarang2 = new Pengarang("Joko");
    Pengarang* varPengarang3 = new Pengarang("Lia");
    Pengarang* varPengarang4 = new Pengarang("Asroni");

    varPenerbit1->tambahPengarang(varPengarang1);
    varPenerbit1->tambahPengarang(varPengarang2);
    varPenerbit1->tambahPengarang(varPengarang3);
    varPenerbit2->tambahPengarang(varPengarang4);
    varPenerbit2->tambahPengarang(varPengarang1);

    varPenerbit1->cetakPengarang();
    varPenerbit2->cetakPengarang();
    varPengarang1->cetakPenerbit();

    buku* varbuku1 = new buku("Matematika");
    buku* varbuku2 = new buku("Multimedia");
    buku* varbuku3 = new buku("Dasar Pemrograman");
    buku* varbuku4 = new buku("Basis Data");
    buku* varbuku5 = new buku("Algorithma");
    buku* varbuku6 = new buku("Fisika");

    pengarangbuku* varP = new pengarangbuku("Joko");
    pengarangbuku* varP1 = new pengarangbuku("Lia");
    pengarangbuku* varP2 = new pengarangbuku("Asroni");
    pengarangbuku* varP3 = new pengarangbuku("Giga");


    varP->tambahBuku(varbuku6);
    varP->tambahBuku(varbuku5);
    varP1->tambahBuku(varbuku4);
    varP2->tambahBuku(varbuku3);

    varP3->tambahBuku(varbuku2);

    varP->cetakBuku();
    varP1->cetakBuku();
    varP2->cetakBuku();
    varP3->cetakBuku();

    return 0;
};