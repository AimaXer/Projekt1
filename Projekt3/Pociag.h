#pragma once
#include "stdafx.h"
#include <iostream>
#include "Pojazd.h"

using namespace std;
///KLASA DFZIEDZICZY PO POJEZDZIE
class Pociag : public Pojazd {
private:
	int ilosc_wagonow;///<OKRESLA ILOSC WAGONOW
	int moc_lokomotywy;///<OKRESLA MOC LOKOMOTYWY
	string nazwa_pociagu;///OKRESLA NAZWE POCIAGU

public:
	///KONSTRUKTOR DOMYSLNY
	Pociag();
	///KONSTRUKTOR Z PARAMETRAMI
	Pociag(int ile, int moc, string nazwa);
	///FUNKCJA USTAWIAJACA ILOSC WAGONOW
	void setIlosc_Wagonow(int ile);
	///FUNKCJA USTAWIAJACA MOC LOKOMOTYWY
	void setMoc_Lokomotywy(int moc);
	
	
	
	///FUNKCJA POBIERAJACA ILOSC WAGONOW
	int getIlosc_Wagonow();
	///FUNKCJA POBIERJACA MOC LOKOMOTYWY
	int getMoc_Lokomotywy();
	///FUNKCJA POBIERAJACA MODEL POCIAGU
	string getModel();


	///FUNKCJA ZAPISUJACA DO PLIKU
	void zapisDoPliku(string nazwa_pociagu, Pociag& pociag);
	///FUNKCJA ODCZYTUJACA Z PLIKU
	void odczytZPliku(string nazwa_pociagu, Pociag& pociag);

	///OPERATORY STRUMIENIOWE
	friend ostream& operator<<(ostream& out, Pociag& pociag);
	friend istream& operator>>(istream& in, Pociag& pociag);

	///METODA WIRTUALNA
	virtual void nazwa_pojazdu();

	///DESTRUKTOR
	~Pociag();
};