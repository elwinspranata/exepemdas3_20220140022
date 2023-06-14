#pragma once
#ifndef PENGARANGBUKU_H
#define PENGARANGBUKU_H
#include <iostream>;
#include "Buku.h"
#include <vector>
using namespace std;

class pengarangbuku {
public:
	string nama;
	vector<buku*> daftar_buku;

	pengarangbuku(string pNama) :nama(pNama) {}

	void tambahBuku(buku* pBuku) {
		daftar_buku.push_back(pBuku);
	}
	void cetakBuku() {
		cout << "\nDaftar Buku Yang Dikarang \"" << this->nama << "\":\n";
		for (auto& a : daftar_buku) {
			cout << a->nama << "\n";
		}
		cout << endl;
	}


};
#endif // !PENGARANGBUKU_H
