
#include "stdafx.h"
#include <iostream>
#include "Kadlub.h"

using namespace std;

Kadlub::Kadlub() {}
Kadlub::Kadlub(int dlugosc, int szerokosc) {
	this->dlugosc = dlugosc;
	this->szerokosc = szerokosc;
}

int Kadlub::getDlugosc() {
	return this->dlugosc;
}

int Kadlub::getSzerokosc() {
	return this->szerokosc;
}

void Kadlub::setSzerokosc(int szerokosc) {
	this->szerokosc = szerokosc;
}

void Kadlub::setDlugosc(int dlugosc) {
	this->dlugosc = dlugosc;
}