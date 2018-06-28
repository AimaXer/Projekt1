#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Kadlub.h"
#include "Pojazd.h"
#include "Pasazerowie.h"
#include <queue>

using namespace std;
///KLASA DZIEDZICZY PO POJEZDZIE
class Samolot : public Pojazd {
protected:

	int maxpredkosc;///<OKRESLA MAKSYMALNA PREDKOSC SAMOLOTU
	string model;///<OKRESLA MODEL SAMOLOTU
	int liczba_pasazerow;///<OKRESLA ILOSC PASAZEROW W SAMOLOCIE
	int dlugosc, szerokosc;///<OKRESLAJA DLUGOSC I SZEROKOSC SAMOLOTU
	
public:
	double kmh[10];
	static int ile_samolotow;
	Kadlub kadlub;
	queue <Pasazerowie> pasazerowie;

	/// KONSTRUKTORY DOMYSLNY
	Samolot();
	///KONSTRUKTOR Z PARAMETRAMI
	Samolot(int maxpredkosc, string model, int liczba_pasazerow, int dlugosc_k, int szerokosc_k);
	///KONSTRUKTOR KOPIUJACY
	Samolot(const Samolot &s);

	/// OPERATORY STRUMIENIOWE
	friend ostream& operator<<(ostream& out, Samolot& samolot);
	friend istream& operator>>(istream& in, Samolot& samolot);
	///OPERATOR DODAWANIA
	friend int operator+(const Samolot& samolot1, const Samolot& samolot2);
	///OPERATOR INKREMENTACJI
	Samolot& operator++();
	///OPERATOR PRZYPISANIA
	Samolot& operator=(const Samolot& s);
	///OPERATOR RZUTOWANIA
	operator int();
	///OPERATOR INDEKSOWANIA
	const double& operator[](int i);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FUNKCJE PRZYPISANIA I ODCZYTU
	///FUNKCJA USTAWIAJACA MODEL SAMOLOTU
	void setModel(string model);
	///FUNKCJA USTAWIAJACA LICZBE PASAZEROW
	void setLiczbaPasazerow(int lp);
	///FUNKCJA USTAWIAJACA MAKS PREDKOSC
	void setMaxPredkosc(int mp);
	///FUNKCJA POBIERAJACA MODEL SAMOLOTU
	string getModel();
	///FUNKCJA POBIERAJACA LICZBE PASAZEROW
	int getLiczbaPasazerow();
	///FUNKCJA POBIERAJACA MAKS PREDKOSC
	int getMaxPredkosc();

	/// VIRTUALNA METODA SAMOLOTU
	virtual void nazwa_pojazdu();


	///FUNKCJA ZAPISUJACA  DO PLIKU
	void zapisDoPliku(string nazwa_samolotu, Samolot& samolot);
	///FUNKCJA ODCZYTUJACA Z PLIKU
	void odczytZPliku(string nazwa_samolotu, Samolot& samolot);

	/// DESTRUKTOR 
	~Samolot();

};