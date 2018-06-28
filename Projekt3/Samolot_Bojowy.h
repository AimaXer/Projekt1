#pragma once
#include "stdafx.h"
#include <iostream>
#include "Samolot.h"
#include "queue"

using namespace std;
///KLASA DZIEDZICZY PO SAMOLOCIE
class Samolot_Bojowy : public Samolot {
private:
	int ilosc_bomb;///<OKRESLA ILOSC BOMB W SAMOLOCIE BOMBOWYM
public:

	queue <Pasazerowie> pasazerowieB;

	Kadlub kadlub;
	/// FUNKCJA USTAWIAJACA ILOSC BOMB
	void setIlosc_bomb(int ile);
	///FUNKCJA POBIERAJACA ILOSC BOMB
	int getIlosc_bomb();
	///KONSTRUKTOR DOMYSLNY
	Samolot_Bojowy();
	///KONSTRUKTOR Z PARAMETRAMI
	Samolot_Bojowy(int ilosc_bomb, string model, int ilosc_pasazerow, int max_predkosc, int dlugosc, int szerokosc);
	
	
	///FUNKCJA ZAPISUJACA DO PLIKU
	void zapisDoPliku(string nazwa_samolotu, Samolot_Bojowy& samolot);
	///FUNKCJA ODCZYTUJACA Z PLIKU
	void odczytZPliku(string nazwa_samolotu, Samolot_Bojowy& samolot);
	
	
	///OPERATORY STRUMIENIOWE
	friend ostream& operator<<(ostream& out, Samolot_Bojowy& samolot_b);
	friend istream& operator>>(istream& in, Samolot_Bojowy& samolot_b);
	
	///METODA VIRTUALNA
	virtual void nazwa_pojazdu();
	
	
	///DESTRUKTOR
	~Samolot_Bojowy();
};