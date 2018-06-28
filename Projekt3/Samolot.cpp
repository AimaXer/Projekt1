#include "stdafx.h"
#include <iostream>
#include "Samolot.h"
#include <string>
#include <queue>
#include "Pasazerowie.h"
#include <fstream>

using namespace std;

int Samolot::ile_samolotow = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ KONSTRUKTORY
Samolot::Samolot() {
#ifdef _DEBUG
	cout << "konstruktor domyslny SAMOLOTU" << endl;
#endif // !_DEBUG

	ile_samolotow++;
	liczba_pasazerow = 1;
	maxpredkosc = 0;
	kadlub.setDlugosc(0);
	kadlub.setSzerokosc(0);
	model = "sd";
}

Samolot::Samolot(int maxpredkosc, string model, int liczba_pasazerow, int dlugosc_k, int szerokosc_k) {
#ifdef _DEBUG
	cout << "konstruktor SAMOLOTU" << endl;
#endif // !_DEBUG
	ile_samolotow++;
	this->maxpredkosc = maxpredkosc;
	this->liczba_pasazerow = liczba_pasazerow;
	this->kadlub.setDlugosc(dlugosc_k);
	this->kadlub.setSzerokosc(szerokosc_k);
	this->model = model;

	for (int i = 0; i < liczba_pasazerow; i++) {
		pasazerowie.push(Pasazerowie());
	}

}

Samolot::Samolot(const Samolot &s) {
#ifdef _DEBUG
	cout << "konstruktor kopiujacy SAMOLOTU" << endl;
#endif // !_DEBUG
	this->ile_samolotow++;
	this->liczba_pasazerow = s.liczba_pasazerow;
	this->maxpredkosc = s.maxpredkosc;
	this->model = s.model;
	this->kadlub = s.kadlub;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORY
int operator+(const Samolot& samolot1, const Samolot& samolot2) {
	return samolot1.liczba_pasazerow + samolot2.liczba_pasazerow;
}

Samolot& Samolot::operator++() {
	maxpredkosc++;
	return *this;
}

Samolot& Samolot::operator=(const Samolot& s) {
	this->ile_samolotow++;
	this->liczba_pasazerow = s.liczba_pasazerow;
	this->maxpredkosc = s.maxpredkosc;
	this->model = s.model;
	this->kadlub = s.kadlub;
	return *this;
}

Samolot::operator int() {
	return liczba_pasazerow;
}

const double& Samolot::operator[](int i) {
	if (i>0 and i<10)
		return kmh[i];
}

ostream& operator<<(ostream& out, Samolot& samolot) {
	out << samolot.model << endl << samolot.liczba_pasazerow << endl << samolot.maxpredkosc;

	return out;
}

istream& operator>>(istream& in, Samolot& samolot) {
	in >> samolot.model >> samolot.liczba_pasazerow >> samolot.maxpredkosc;

	return in;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FUNKCJE PRZYPISANIA I ODCZYTU
void Samolot::setModel(string model) {
	this->model = model;
}
void Samolot::setLiczbaPasazerow(int lp) {
	this->liczba_pasazerow = lp;
}
void Samolot::setMaxPredkosc(int mp) {
	this->maxpredkosc = mp;
}

string Samolot::getModel() {
	return this->model;
}
int Samolot::getLiczbaPasazerow() {
	return this->liczba_pasazerow;
}
int Samolot::getMaxPredkosc() {
	return this->maxpredkosc;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ VIRTUALNE METODY
void Samolot::nazwa_pojazdu() {
	cout << "SAMOLOT";
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ZAPIS/ODCZYT DO/Z PLIKU
void Samolot::zapisDoPliku(string nazwa_samolotu, Samolot& samolot) {
	fstream plik;
	plik.open(nazwa_samolotu + "_Dane.txt", ios::out | ios::trunc);

	plik << samolot;

	plik.close();
}
void Samolot::odczytZPliku(string nazwa_samolotu, Samolot& samolot) {
	fstream plik;
	plik.open(nazwa_samolotu + "_Dane.txt", ios::in);

	plik >> samolot;

	plik.close();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUKTOR
Samolot::~Samolot() {
#ifdef _DEBUG
	cout << "Destruktor SAMOLOTU" << endl;
#endif // !_DEBUG
	ile_samolotow--;
	pasazerowie.empty();
}