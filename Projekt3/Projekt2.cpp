// Projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Samolot.h"
#include "Pojazd.h"
#include "Pociag.h"
#include "Samolot_Bojowy.h"
#include "Kontener.h"
#include <queue>

queue <Samolot> kolejkaSamolotow;
queue <Samolot_Bojowy> kolejkaSamolotowBojowych;
queue <Pociag> kolejkaPociagow;

using namespace std;
// -------------------------------------------- OBSLUGA INTERFJSU

void glownyInterfejsAplikacji() {
	cout << " --- INTERFEJS APLIKACJI ---" << endl << endl;
	cout << "1 - Stworz obiekt           " << endl;
	cout << "2 - Zapisz/Wypisz obiekt w/z pliku" << endl;
	cout << "3-  Testuj kontener" << endl;
	cout << "0 - WYJSCIE Z APLIKACJI" << endl;
}
//skonczone

void wyborObiektuDoStworzenia() {

	int decyzja;
	void tworzenieSamolotu();
	void tworzenieSamolotuBojowego();
	void tworzeniePociagu();

	for (;;) {
		cout << endl << " --- JAKI OBIEKT CHCESZ STWORZYC ? --- " << endl;
		cout << "1 - Samolot (Zwykly)" << endl;
		cout << "2 - Samolot Bojowy" << endl;
		cout << "3 - Pociag" << endl << endl;
		cout << "0 - WYJSCIE Z WYTWORNI OBIEKTOW" << endl;
		do {
			cin >> decyzja;
			if (decyzja < 0 || decyzja > 3) {
				cout << "BŁĘDNE DANE - SPROBUJ PONOWNIE" << endl;
			}
		} while (decyzja < 0 || decyzja > 3);
		switch (decyzja)
		{
		case 1: tworzenieSamolotu(); break;
		case 2: tworzenieSamolotuBojowego(); break;
		case 3: tworzeniePociagu(); break;
		case 0: break;
		}
		if (decyzja == 0) { break; }
	}
}
//skonczone

// --------------------------------------------- TWORZENIE OBIEKTOW

void tworzenieSamolotu() {
	Pojazd *wsk;
	string model;
	int dlugosc, szerokosc, max_predkosc, ilosc_pasazerow;

	cout << "Podaj model Samolotu : "; cin >> model;
	do {
		cout << "Podaj liczbe pasazerow (maxymalna pojemnosc samolotu to 50 soob) : "; cin >> ilosc_pasazerow;
		if (ilosc_pasazerow <= 0 || ilosc_pasazerow > 50) {
			cout << "BLEDNA ILOSC PASAZEROW, SPROBUJ PONOWNIE ! " << endl;
		}
	} while (ilosc_pasazerow <= 0 || ilosc_pasazerow > 50);
	cout << "Podaj szerokosc kadluba : "; cin >> szerokosc;
	cout << "Podaj dlugosc kadluba : "; cin >> dlugosc;
	cout << "Podaj maksymalna predkosc samolotu : "; cin >> max_predkosc;
	cout << endl;
	Samolot samolot(max_predkosc, model, ilosc_pasazerow, dlugosc, szerokosc);
	kolejkaSamolotow.push(samolot);
	wsk = &samolot;
	cout << "Obiekt "; wsk->nazwa_pojazdu(); cout << " zostal utworzony pomyslnie !" << endl;
}
//skonczone

void tworzenieSamolotuBojowego() {
	Pojazd *wsk;
	string model;
	int ilosc_bomb, dlugosc, szerokosc, max_predkosc, ilosc_pasazerow;

	cout << "Podaj model Samolotu : "; cin >> model;
	do {
		cout << "Podaj liczbe pasazerow (maxymalna pojemnosc samolotu to 50 soob) : "; cin >> ilosc_pasazerow;
		if (ilosc_pasazerow <= 0 || ilosc_pasazerow > 50) {
			cout << "BLEDNA ILOSC PASAZEROW, SPROBUJ PONOWNIE ! " << endl;
		}
	} while (ilosc_pasazerow <= 0 || ilosc_pasazerow > 50);
	cout << "Podaj szerokosc kadluba : "; cin >> szerokosc;
	cout << "Podaj dlugosc kadluba : "; cin >> dlugosc;
	cout << "Podaj maksymalna predkosc samolotu : "; cin >> max_predkosc;
	do {
		cout << "Ile bomb ma posiadac Samolot Bojowy ? (maksymalnie 4) : "; cin >> ilosc_bomb;
		if (ilosc_bomb <= 0 || ilosc_bomb > 4) {
			cout << "BLEDNA ILOSC BOMB, SPROBUJ PONOWNIE ! " << endl;
		}
	} while (ilosc_bomb <= 0 || ilosc_bomb > 4);
	cout << endl;
	Samolot_Bojowy samolot_b(ilosc_bomb, model, ilosc_pasazerow, max_predkosc, dlugosc, szerokosc);
	kolejkaSamolotowBojowych.push(samolot_b);
	wsk = &samolot_b;
	cout << "Obiekt "; wsk->nazwa_pojazdu(); cout << " zostal utworzony pomyslnie !" << endl;
}
//skonczone

void tworzeniePociagu() {
	Pojazd *wsk;
	string nazwa;
	int moc, ilosc_wagonow;

	cout << "Podaj nazwe Pociagu : "; cin >> nazwa;
	do {
		cout << "Podaj liczbe wagonow (maxymalna liczba wagonow to 80) : "; cin >> ilosc_wagonow;
		if (ilosc_wagonow <= 0 || ilosc_wagonow > 80) {
			cout << "BLEDNA ILOSC WAGONOW, SPROBUJ PONOWNIE ! " << endl;
		}
	} while (ilosc_wagonow <= 0 || ilosc_wagonow > 80);
	cout << "Podaj moc pociagu : "; cin >> moc;
	cout << endl;
	Pociag pociag(ilosc_wagonow, moc, nazwa);
	kolejkaPociagow.push(pociag);
	wsk = &pociag;
	cout << "Obiekt "; wsk->nazwa_pojazdu(); cout << " zostal utworzony pomyslnie !" << endl;
}
//skonczone



// ---------------------------------------------- ZAPIS/ODCZYT NA/Z PLIKU
void zapisOdczyt(int x);
void zapisSamolotu(bool czy_znaleziono, string model);
void zapisSamolotuBojowego(bool czy_znaleziono, string model);
void zapisPociagu(bool czy_znaleziono, string model);

void odczytSamolotu(bool czy_znaleziono, bool czy_znaleziono2, string model, string model2);
void odczytSamolotuBojowego(bool czy_znaleziono, bool czy_znaleziono2, string model, string model2);
void odczytPociagu(bool czy_znaleziono, bool czy_znaleziono2, string model, string model2);

void wyborObiektuIZapisNaPlik() {
	int wybor;

	for (;;) {

		cout << " --- WYBIERZ OBIEKT DO ZAPISU/ODCZYTU ---" << endl;
		cout << "1 - Samolot" << endl;
		cout << "2 - Samolot Bojowy" << endl;
		cout << "3 - Pociag" << endl;
		cout << "0 - WYJSCIE Z MODYFIKATORNI OBIEKTOW" << endl;
		do {
			cin >> wybor;
			if (wybor < 0 || wybor > 3) {
				cout << "BŁĘDNE DANE - SPROBUJ PONOWNIE" << endl;
			}
		} while (wybor < 0 || wybor > 3);
		switch (wybor)
		{
		case 1: if (kolejkaSamolotow.size() > 0) {
			zapisOdczyt(1);
		}
				else { cout << "NIE MA SAMOLOTOW DO ZAPISU/ ODCZYTU ! ";  break; }; break;
		case 2: if (kolejkaSamolotowBojowych.size() > 0) {
			zapisOdczyt(2);
		}
				else { cout << "NIE MA SAMOLOTOW DO ZAPISU/ ODCZYTU ! ";  break; }; break;
		case 3: if (kolejkaPociagow.size() > 0) {
			zapisOdczyt(3);
		}
				else { cout << "NIE MA POCIAGOW DO ZAPISU/ ODCZYTU ! ";  break; }; break;
		case 0: break;
		}
		if (wybor == 0) { break; }
	}
}
void zapisOdczyt(int x) {

	string model, model2;
	int wybor2;
	bool czy_znaleziono = false;
	bool czy_znaleziono2 = false;
	cout << " --- ZAPIS/ ODCZYT ? ---" << endl;
	cout << "1 - Zapis" << endl;
	cout << "2 - Odczyt" << endl;
	cout << "0 - WYJSCIE" << endl;
	do {
		cin >> wybor2; cin.ignore();
		if (wybor2 < 0 || wybor2 > 2) {
			cout << "BLEDNE DANE - SPROBUJ PONOWNIE" << endl;
		}
	} while (wybor2 < 0 || wybor2 > 2);
	switch (wybor2) {
	case 0: break;
	case 1: cout << "Podaj MODEL pojazdu do ZAPISU : "; cin >> model; cin.ignore();
		if (x == 1) {
			zapisSamolotu(czy_znaleziono, model);
		}
		else if (x == 2) {
			zapisSamolotuBojowego(czy_znaleziono, model);
		}
		else if (x == 3) {
			zapisPociagu(czy_znaleziono, model);
		}
		break;
	case 2: cout << "Podaj MODEL pojazdu do ODCZYTU : "; cin >> model; cin.ignore();
		cout << "Podaj MODEL pojazdu na ktory maja byc wpisane dane : "; cin >> model2; cin.ignore();
		if (x == 1) {
			odczytSamolotu(czy_znaleziono, czy_znaleziono2, model, model2);
		}
		else if (x == 2) {
			odczytSamolotuBojowego(czy_znaleziono, czy_znaleziono2, model, model2);
		}
		else if (x == 3) {
			odczytPociagu(czy_znaleziono, czy_znaleziono2, model, model2);
		}
		break;
	}
}
void zapisSamolotu(bool czy_znaleziono, string model) {
	Samolot pomocniczy;
	queue <Samolot> pomoc;
	while (!kolejkaSamolotow.empty()) {
		if (kolejkaSamolotow.front().getModel() == model) {
			czy_znaleziono = true;
			kolejkaSamolotow.front().zapisDoPliku(model, kolejkaSamolotow.front());
			cout << " --- POMYSLNY ZAPIS OBIEKTU NA PLIK --- " << endl;
		}
		pomoc.push(kolejkaSamolotow.front());
		kolejkaSamolotow.pop();
	}
	while (!pomoc.empty()) {
		kolejkaSamolotow.push(pomoc.front());
		pomoc.pop();
	}
	if (!czy_znaleziono) { cout << "NIE ZNALEZIONO TAKIEGO MODELU" << endl; }
}

void zapisSamolotuBojowego(bool czy_znaleziono, string model) {
	Samolot_Bojowy pomocniczy;
	queue <Samolot_Bojowy> pomoc;
	while (!kolejkaSamolotowBojowych.empty()) {
		if (kolejkaSamolotowBojowych.front().getModel() == model) {
			czy_znaleziono = true;
			kolejkaSamolotowBojowych.front().zapisDoPliku(model, kolejkaSamolotowBojowych.front());
			cout << " --- POMYSLNY ZAPIS OBIEKTU NA PLIK --- " << endl;
		}
		pomoc.push(kolejkaSamolotowBojowych.front());
		kolejkaSamolotowBojowych.pop();
	}
	while (!pomoc.empty()) {
		kolejkaSamolotowBojowych.push(pomoc.front());
		pomoc.pop();
	}
	if (!czy_znaleziono) { cout << "NIE ZNALEZIONO TAKIEGO MODELU" << endl; }
}

void zapisPociagu(bool czy_znaleziono, string model) {
	Pociag pomocniczy;
	queue <Pociag> pomoc;
	while (!kolejkaPociagow.empty()) {
		if (kolejkaPociagow.front().getModel() == model) {
			czy_znaleziono = true;
			kolejkaPociagow.front().zapisDoPliku(model, kolejkaPociagow.front());
			cout << " --- POMYSLNY ZAPIS OBIEKTU NA PLIK --- " << endl;
		}
		pomoc.push(kolejkaPociagow.front());
		kolejkaPociagow.pop();
	}
	while (!pomoc.empty()) {
		kolejkaPociagow.push(pomoc.front());
		pomoc.pop();
	}

	if (!czy_znaleziono) { cout << "NIE ZNALEZIONO TAKIEGO MODELU" << endl; }
}



void odczytSamolotu(bool czy_znaleziono, bool czy_znaleziono2, string model, string model2) {
	Samolot pomocniczy, pomocniczy2;
	queue <Samolot> pomoc;
	do {
		while (!kolejkaSamolotow.empty()) {
			if (kolejkaSamolotow.front().getModel() == model) {
				czy_znaleziono = true;
				pomocniczy = kolejkaSamolotow.front();
			}
			pomoc.push(kolejkaSamolotow.front());
			kolejkaSamolotow.pop();
		}

		while (!pomoc.empty()) {
			if (pomoc.front().getModel() == model2) {
				czy_znaleziono2 = true;
				pomocniczy2 = pomoc.front();
				if (czy_znaleziono) {
					pomocniczy.odczytZPliku(model, pomocniczy2);
				}
				pomoc.front() = pomocniczy2;
			}
			kolejkaSamolotow.push(pomoc.front());
			pomoc.pop();
		}
		if (czy_znaleziono && czy_znaleziono2) {
			cout << " --- POMYSLNY ZAPIS Z PLIKU NA OBIEKT --- " << endl;
		}
		else if ((!czy_znaleziono) || (!czy_znaleziono2)) { cout << "NIE ZNALEZIONO TAKIEGO MODELU ODCZYTU" << endl; }
	} while ((!czy_znaleziono) || (!czy_znaleziono2));
}

void odczytSamolotuBojowego(bool czy_znaleziono, bool czy_znaleziono2, string model, string model2) {
	Samolot_Bojowy pomocniczy, pomocniczy2;
	queue <Samolot_Bojowy> pomoc;
	do {
		while (!kolejkaSamolotowBojowych.empty()) {
			if (kolejkaSamolotowBojowych.front().getModel() == model) {
				czy_znaleziono = true;
				pomocniczy = kolejkaSamolotowBojowych.front();
			}
			pomoc.push(kolejkaSamolotowBojowych.front());
			kolejkaSamolotowBojowych.pop();
		}

		while (!pomoc.empty()) {
			if (pomoc.front().getModel() == model2) {
				czy_znaleziono2 = true;
				pomocniczy2 = pomoc.front();
				if (czy_znaleziono) {
					pomocniczy.odczytZPliku(model, pomocniczy2);
				}
				pomoc.front() = pomocniczy2;
			}
			kolejkaSamolotowBojowych.push(pomoc.front());
			pomoc.pop();
		}
		if (czy_znaleziono && czy_znaleziono2) {
			cout << " --- POMYSLNY ZAPIS Z PLIKU NA OBIEKT --- " << endl;
		}
		else if ((!czy_znaleziono) || (!czy_znaleziono2)) { cout << "NIE ZNALEZIONO TAKIEGO MODELU ODCZYTU" << endl; }
	} while ((!czy_znaleziono) || (!czy_znaleziono2));
}

void odczytPociagu(bool czy_znaleziono, bool czy_znaleziono2, string model, string model2) {
	Pociag pomocniczy, pomocniczy2;
	queue <Pociag> pomoc;
	do {
		while (!kolejkaPociagow.empty()) {
			if (kolejkaPociagow.front().getModel() == model) {
				czy_znaleziono = true;
				pomocniczy = kolejkaPociagow.front();
			}
			pomoc.push(kolejkaPociagow.front());
			kolejkaPociagow.pop();
		}

		while (!pomoc.empty()) {
			if (pomoc.front().getModel() == model2) {
				czy_znaleziono2 = true;
				pomocniczy2 = pomoc.front();
				if (czy_znaleziono) {
					pomocniczy.odczytZPliku(model, pomocniczy2);
				}
				pomoc.front() = pomocniczy2;
			}
			kolejkaPociagow.push(pomoc.front());
			pomoc.pop();
		}
		if (czy_znaleziono && czy_znaleziono2) {
			cout << " --- POMYSLNY ZAPIS Z PLIKU NA OBIEKT --- " << endl;
		}
		else if ((!czy_znaleziono) || (!czy_znaleziono2)) { cout << "NIE ZNALEZIONO TAKIEGO MODELU ODCZYTU" << endl; }
	} while ((!czy_znaleziono) || (!czy_znaleziono2));
}

void testKontenera() {
	Kontener<Samolot> kontener;
	Kontener<Samolot> kontener2;
	Samolot samolot1(111, "xxx", 1, 2, 3), samolot2(222, "yyy", 2, 3, 2), samolot3(445, "fff", 1, 2, 3), samolot4(445, "lll", 5, 3, 3);

	kontener.Dodaj_Element(samolot1);
	kontener.Dodaj_Element(samolot2);
	kontener.Dodaj_Element(samolot3);

	kontener2.Dodaj_Element(samolot3);
	kontener2.Dodaj_Element(samolot4);

	kontener.zwrocWskaznikElementu(0);
	cout << "Samolot nr1 : " << kontener.ten->ob.getModel() << endl;
	kontener.zwrocWskaznikElementu(1);
	cout << "Samolot nr2 : " << kontener.ten->ob.getModel() << endl;
	kontener.zwrocWskaznikElementu(2);
	cout << "Samolot nr3 : " << kontener.ten->ob.getModel() << endl << endl;

	kontener.ZamianaMiejscami(0, 2);

	kontener.zwrocWskaznikElementu(0);
	cout << "Samolot nr1 : " << kontener.ten->ob.getModel() << endl;
	kontener.zwrocWskaznikElementu(1);
	cout << "Samolot nr2 : " << kontener.ten->ob.getModel() << endl;
	kontener.zwrocWskaznikElementu(2);
	cout << "Samolot nr3 : " << kontener.ten->ob.getModel() << endl << endl;

	kontener = kontener2;

	kontener.zwrocWskaznikElementu(1);
	cout << "Samolot nr4 : " << kontener.ten->ob.getModel() << endl << endl;

	cout << "Liczba elementow : " << kontener.size() << endl;
	kontener.Usun_element(); kontener.Usun_element();
	cout << "Liczba elementow : " << kontener.size() << endl << endl;
	kontener.Usun_element(); kontener.Usun_element();

	kontener.Dodaj_Element(samolot1);
	kontener.Dodaj_Element(samolot2);
	kontener.Dodaj_Element(samolot3);

	cout << "Liczba elementow : " << kontener.size() << endl;

	kontener += kontener2;

	cout << "Liczba elementow : " << kontener.size() << endl;

	if (kontener == kontener) {
		cout << "Porownanie kontenerow" << endl;
	}
	kontener2.zwrocWskaznikElementu(0);
	if (kontener.contains(kontener2.ten->ob)) {
		cout << "Powinien zawierac " << endl;
	}

}


int main()
{

	void glownyInterfejsAplikacji();
	void wyborObiektuDoStworzenia();
	for (;;) {
		glownyInterfejsAplikacji();

		int odpowiedz_uzytkownika;
		do {
			cin >> odpowiedz_uzytkownika;
			if (odpowiedz_uzytkownika < 0 || odpowiedz_uzytkownika > 4) {
				cout << "BŁĘDNE DANE - SPROBUJ PONOWNIE" << endl;
			}
		} while (odpowiedz_uzytkownika < 0 || odpowiedz_uzytkownika > 4);

		switch (odpowiedz_uzytkownika) {
		case 0: break;
		case 1: wyborObiektuDoStworzenia(); break;
		case 2: wyborObiektuIZapisNaPlik(); break;
		case 3: testKontenera(); break;

		}
		if (odpowiedz_uzytkownika == 0) { break; }
	}
	return 0;
}



