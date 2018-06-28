#include "stdafx.h"
#include <iostream>
#include "Pociag.h"
#include <string>
#include <fstream>

using namespace std;
// -------------------------------------------------- KONSTRUKTORY
Pociag::Pociag() {
#ifdef _DEBUG
	cout << "konstruktor domyslny POCIAGU" << endl;
#endif // !_DEBUG
	ilosc_wagonow = 1;
	moc_lokomotywy = 0;

}

Pociag::Pociag(int ile, int moc, string nazwa) {
#ifdef _DEBUG
	cout << "konstruktor POCIAGU" << endl;
#endif // !_DEBUG
	this->ilosc_wagonow = ile;
	this->moc_lokomotywy = moc;
	this->nazwa_pociagu = nazwa;
}
// ------------------------------------------------- ZMIENNA VIRTUALNA
void Pociag::nazwa_pojazdu() {
	cout << "POCIAG";
}
// ------------------------------------------------- OPERATORY
ostream& operator<<(ostream& out, Pociag& pociag) {
	out << "Liczba wagonow: "<<pociag.ilosc_wagonow<< endl <<"Moc lokomotywy:"<<pociag.moc_lokomotywy;

	return out;
}

istream& operator>>(istream& in, Pociag& pociag) {
	in>>pociag.ilosc_wagonow>> pociag.moc_lokomotywy;

	return in;
}
// ------------------------------------------------- ZAPIS/ODCZYT DO/Z PLIKU
void Pociag::zapisDoPliku(string nazwa_pociagu, Pociag& pociag) {
	fstream plik;
	plik.open(nazwa_pociagu + "_Dane.txt", ios::out | ios::trunc);

	plik << pociag;

	plik.close();
}
void Pociag::odczytZPliku(string nazwa_pociagu, Pociag& pociag) {
	fstream plik;
	plik.open(nazwa_pociagu + "_Dane.txt", ios::in);

	plik >> pociag;

	plik.close();
}
// ------------------------------------------------------ METODY PRZYPISANIA/ODCZYTU
void Pociag::setIlosc_Wagonow(int ile) {
	this->ilosc_wagonow = ile;
}
void Pociag::setMoc_Lokomotywy(int moc) {
	this->moc_lokomotywy = moc;
}

int Pociag::getIlosc_Wagonow() {
	return this->ilosc_wagonow;
}
int Pociag::getMoc_Lokomotywy() {
	return this->moc_lokomotywy;
}
string Pociag::getModel() {
	return this->nazwa_pociagu;
}

// ------------------------------------------------------ DESTRUKTOR
Pociag::~Pociag() {
#ifdef _DEBUG
	cout << "Destruktor POCIAGU" << endl;
#endif // !_DEBUG
}