#pragma once
#include "stdafx.h"
#include <iostream>
#include "Pasazerowie.h"

using namespace std;

Pasazerowie::Pasazerowie() {
#ifdef _DEBUG
	cout << "konstruktor domyslny PASAZERA" << endl;
#endif // !_DEBUG
	this->wiek = 20;
	this->plec = "nieznana";
}
Pasazerowie::Pasazerowie(string plec, int wiek) {
#ifdef _DEBUG
	cout << "konstruktor PASAZERA" << endl;
#endif // !_DEBUG
	this->plec = plec;
	this->wiek = wiek;
}

void Pasazerowie::setPlec(string plec) {
	this->plec = plec;
}
void Pasazerowie::setWiek(int wiek) {
	this->wiek = wiek;
}
string Pasazerowie::getPlec() {
	return plec;
}
int Pasazerowie::getWiek() {
	return wiek;
}