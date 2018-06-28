#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;
///KLASA STATYCZNA OPISUJACA KADLUB SAMOLOTU
class Kadlub {
private:
	int dlugosc, szerokosc;///<OKRESLAJA DLUGOSC I SZEROKOSC KADLUBA
public:
	///KONSTRUKTOR DOMYSLNY
	Kadlub();
	///KONSTRUKTOR Z PARAMETRAMI
	Kadlub(int dlugosc, int szerokosc);
	///FUNCKCJA USTAWIAJACA DLUGOSC KADLUBA
	void setDlugosc(int dlugosc);
	///FUNKCJA USTAWIAJACA SZEROKOSC KADLUBA
	void setSzerokosc(int szerokosc);
	///FUNKCJA POBIERAJACA DLUGOSC KADLUBA
	int getDlugosc();
	///FUNKCJA POBIERAJACA SZEROKOSC KADLUBA
	int getSzerokosc();
};