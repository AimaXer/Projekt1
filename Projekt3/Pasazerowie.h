#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;
///KLASA DYNAMICZNA OPISUJACA PASAZEROW
class Pasazerowie {
private:
	string plec;///<OKRESLA PLEC
	int wiek;///<OKRESLA WIEK 
public:
	///KONSTRUKTOR DOMYSLNY
	Pasazerowie();
	///KONSTRUKTOR Z PARAMETRAMI
	Pasazerowie(string plec, int wiek);
	///FUNKCJA USTAWIAJACA PLEC
	void setPlec(string plec);
	///FUNKCJA USTAWIAJACA WIEK
	void setWiek(int wiek);
	///FUNKCJA POBIERAJACA PLEC
	string getPlec();
	///FUNKCJA POBIERAJACA WIEK
	int getWiek();
};