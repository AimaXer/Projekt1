#include <iostream>
#include <algorithm>
#include <string>
#pragma once

using namespace std;

template<class Typ>
class Element
{
public:
	Element(Typ o);
	~Element();
	Typ ob;
	Element* next;
	Element* back;
};

template <class Typ>
Element<Typ>::Element(Typ o) {
	this->ob = o;
}

template <class Typ>
Element<Typ>::~Element() {
	Element *b, *f;

	b = this->back;
	f = this->next;
	if (b != NULL) {
		b->next = this->next;
	}
	if (f != NULL) {
		f->back = this->back;
	}
	delete ob;
}

template <class Typ>
class Kontener
{
public:
	int liczba_elementow;

	Element<Typ>* front, *tyl, *ten;
	Kontener();
	~Kontener();

	void Usun_element();
	void Dodaj_Element(Typ o);
	void ZamianaMiejscami(unsigned int pozycja1, unsigned int pozycja2);

	Element<Typ>* zwrocWskaznikElementu(unsigned int index);

	Kontener<Typ>& operator = (const Kontener & o);
	bool operator==(const Kontener & o);
	Kontener<Typ>& operator+=(Kontener& o);

	string size();

	bool contains(Typ& e);
};

template <class Typ>
string Kontener<Typ>::size() {
	return to_string(liczba_elementow);
}

template <class Typ>
bool Kontener<Typ>::contains(Typ &e) {

	if (liczba_elementow == 0)
		return false;

	Element<Typ>* ePomocniczy = this->front;
	for (int i = 0; i < liczba_elementow; i++) {
		if (e == ePomocniczy->ob) {
			return true;
		}
		ePomocniczy = ePomocniczy->next;
	}
	return false;
}

template <class Typ>
bool Kontener<Typ>::operator==(const Kontener& o) {
	if (this->front == o.front || this->liczba_elementow == o.liczba_elementow) {
		for (int i = 0; i < liczba_elementow; i++) {
			if (this->ten->ob != o.ten->ob) {
				return false;
			}
			return true;
		}
	}
	return false;
}

template <class Typ>
Kontener<Typ>& Kontener<Typ>:: operator+=(Kontener& o) {
	o.ten = o.front;
	for (int i = 0; i < o.liczba_elementow; i++) {
		this->Dodaj_Element(o.ten->ob);
		o.ten = o.ten->next;
	}
	return *this;
}

template<class Typ>
Kontener<Typ>::Kontener()
{
	tyl = front = ten = NULL;

	cout << "konstruktor pustego kontenera" << endl;
	liczba_elementow = 0;
}

template<class Typ>
Kontener<Typ>::~Kontener()
{
	cout << "wywolano destruktor kontenera " << endl;
	for (int i = 0; i < liczba_elementow; i++) { ; }
}


template <class Typ>
Element<Typ>* Kontener<Typ>::zwrocWskaznikElementu(unsigned int index) {
	ten = front;
	if (index >= liczba_elementow) {
		return NULL;
	}

	for (int i = 0; i < index; i++) {
		if (ten == NULL) {
			return NULL;
		}
		ten = ten->next;
	}
	return ten;
}

template <class Typ>
void Kontener<Typ>::Usun_element() {

	Element<Typ> *nowyTen = nullptr;

	if (liczba_elementow < 1) {
		return;
	}

	if (liczba_elementow == 1) {
		front = tyl = ten = NULL;
	}
	else if (front == ten) {
		nowyTen = ten->next;
		nowyTen->back = NULL;
		front = nowyTen;
	}
	else if (ten == tyl) {
		nowyTen = ten->back;
		nowyTen->next = NULL;
		tyl = nowyTen;
	}
	else {
		nowyTen = ten->next;
	}

	liczba_elementow--;
}

template <class Typ>
void Kontener<Typ>::ZamianaMiejscami(unsigned int pozycja1, unsigned int pozycja2) {

	if (pozycja1 == pozycja2 || pozycja1 >= liczba_elementow || pozycja2 >= liczba_elementow) {
		return;
	}

	Element<Typ> *tymczasowy1, *tymczasowy2, *tymczasowy1Back, *tymczasowy1Next, *tymczasowy2Back, *tymczasowy2Next;
	tymczasowy1 = zwrocWskaznikElementu(pozycja1);
	tymczasowy2 = zwrocWskaznikElementu(pozycja2);

	tymczasowy1Back = tymczasowy1->back;
	tymczasowy2Next = tymczasowy2->next;

	if (abs((int)(pozycja1 - pozycja2)) == 1) {
		tymczasowy1->back = tymczasowy2;
		tymczasowy1->next = tymczasowy2Next;
		tymczasowy2->next = tymczasowy1;
		tymczasowy2->back = tymczasowy1Back;
		return;
	}

	tymczasowy1Next = tymczasowy1->next;
	tymczasowy2Back = tymczasowy2->back;

	tymczasowy1->back = tymczasowy2Back;
	tymczasowy1->next = tymczasowy2Next;
	tymczasowy2->back = tymczasowy1Back;
	tymczasowy2->next = tymczasowy1Next;

	tymczasowy2Back->next = tymczasowy1;
	tymczasowy1Next->back = tymczasowy2;

	if (min((int)pozycja1, (int)pozycja2) == 0) { front = tymczasowy2; }
	if (max((int)pozycja1, (int)pozycja2) == liczba_elementow) { tyl = tymczasowy1; }

	if (tymczasowy1Back != nullptr) { tymczasowy1Back->next = tymczasowy2; }
	if (tymczasowy2Next != nullptr) { tymczasowy2Next->back = tymczasowy1; }

}

template <class Typ>
Kontener<Typ>& Kontener<Typ>::operator= (const Kontener & o) {

	while (liczba_elementow > 0) {
		this->ten = front;
		this->Usun_element();
	}

	Element<Typ> *element = o.front;

	if (o.liczba_elementow == 0) {
		this->front = this->ten = this->tyl = NULL;
		this->liczba_elementow = 0;
		return *this;
	}

	for (int i = 0; i < o.liczba_elementow; i++) {
		this->Dodaj_Element(element->ob);
		element = element->next;
	}

	return *this;
}

template <class Typ>
void Kontener<Typ>::Dodaj_Element(Typ o) {

	Element<Typ> *element = new Element<Typ>(o);

	if (liczba_elementow == 0) {
		front = tyl = element;
		element->back = element->next = NULL;
	}
	else {
		tyl->next = element;
		element->back = tyl;
		element->next = NULL;
		tyl = element;
	}

	liczba_elementow++;
	ten = element;
}