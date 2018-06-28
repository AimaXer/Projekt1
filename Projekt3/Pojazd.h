#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;
///KLASA GLOWNA ABSTRAKCYJNA
class Pojazd {
public:
	///METODA WIRTUALNA
	virtual void nazwa_pojazdu() = 0;
};