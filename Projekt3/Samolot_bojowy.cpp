#include "stdafx.h"
#include <iostream>
#include "Samolot_Bojowy.h"
#include <string>
#include <fstream>

using namespace std;

Samolot_Bojowy::Samolot_Bojowy() {
#ifdef _DEBUG
	cout << "konstruktor domyslny SAMOLOTU BOJOWEGO" << endl;
#endif // !_DEBUG
	ile_samolotow++;
	maxpredkosc = 100;
	model = "domyslny";
	liczba_pasazerow = 3;
	ilosc_bomb = 1;
}

Samolot_Bojowy::Samolot_Bojowy(int ilosc_bomb, string model, int ilosc_pasazerow, int max_predkosc, int dlugosc_k, int szerokosc_k) {
#ifdef _DEBUG
	cout << "konstruktor SAMOLOTU BOJOWEGO" << endl;
#endif // !_DEBUG

	this->maxpredkosc = max_predkosc;
	this->model = model;
	this->liczba_pasazerow = ilosc_pasazerow;
	this->ilosc_bomb = ilosc_bomb;
	this->kadlub.setDlugosc(dlugosc_k);
	this->kadlub.setSzerokosc(szerokosc_k);
	for (int i = 0; i < liczba_pasazerow; i++) {
		pasazerowieB.push(Pasazerowie());
	}
}

void Samolot_Bojowy::nazwa_pojazdu() {
	cout << "SAMOLOT_BOJOWY";
}

ostream& operator<<(ostream& out, Samolot_Bojowy& samolot_b) {
	out << samolot_b.maxpredkosc << endl << samolot_b.model << endl << samolot_b.liczba_pasazerow << endl << samolot_b.ilosc_bomb;

	return out;
}

istream& operator>>(istream& in, Samolot_Bojowy& samolot_b) {
	in >> samolot_b.maxpredkosc >> samolot_b.model >> samolot_b.liczba_pasazerow >> samolot_b.ilosc_bomb;

	return in;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ZAPIS/ODCZYT DO/Z PLIKU
void Samolot_Bojowy::zapisDoPliku(string nazwa_samolotu, Samolot_Bojowy& samolot) {
	fstream plik;
	plik.open(nazwa_samolotu + "_Dane.txt", ios::out | ios::trunc);

	plik << samolot;

	plik.close();
}

void Samolot_Bojowy::odczytZPliku(string nazwa_samolotu, Samolot_Bojowy& samolot) {
	fstream plik;
	plik.open(nazwa_samolotu + "_Dane.txt", ios::in);

	plik >> samolot;

	plik.close();
}

void Samolot_Bojowy::setIlosc_bomb(int ile) {
	this->ilosc_bomb = ile;
}

int Samolot_Bojowy::getIlosc_bomb() {
	return this->ilosc_bomb;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUKTOR
Samolot_Bojowy::~Samolot_Bojowy() {
#ifdef _DEBUG
	cout << "Destruktor SAMOLOTU BOJOWEGO" << endl;
#endif // !_DEBUG
	ile_samolotow--;
	pasazerowieB.empty();
}
