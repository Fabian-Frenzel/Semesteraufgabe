//von VS17 erstellt_____________________________________________________________________________________________________________
// CppCLR_WinformsProjekt.cpp: Hauptprojektdatei.

// #include "stdafx.h"
// using namespace System;

//int main(array<System::String ^> ^args)
//{
//    Console::WriteLine(L"Hello World");
//    return 0;
//}
//______________________________________________________________________________________________________________________________


#include "stdafx.h"																										//von VS17
#include "Form1.h"																										//von VS17

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Datentypen.h"
#include "Funktionen.h"

using namespace System;																									//von VS17
using namespace System::Windows::Forms;																					//von VS17

[STAThread]																												//von VS17
// int main(array<String^>^ args) { // Kann Fehler nach 'using namespace std;' verursachen								//von VS17
int main() {																											//von VS17
	Application::EnableVisualStyles();																					//von VS17
	Application::SetCompatibleTextRenderingDefault(false);																//von VS17
	Application::Run(gcnew CppCLR_WinformsProjekt::Form1()); // "CppCLR_WinformsProjekt" noch anpassen					//von VS17
		//Variablendeklarationen
	int auswahl, c = 0, a = 1;
	char buf[10];
	Daten Datensatz[1000];

	system("title Literaturverwaltung by Roman Rohlfs");		//Fenster�berschrift �ndern
	nullen(Datensatz);											//Datens�tze mit Nullen f�llen
	einlesen(Datensatz);										//Gespeicherte Datens�tze von HD einlesen

	//Programm l�uft so lange, bis es im Men� beendet wird
	while (a == 1) {
		auswahl = -1;
		//Auswahl abfragen
		do {
			clear();
			menu();
			printf("\nAuswahl: ");
			fgets(buf, 10, stdin);			//Auswahl abfragen
			sscanf(buf, "%i", &auswahl);	//Auswahl als Zahl umwandeln
			//Fehlerhafte Eingabe abfangen
			if ((auswahl < 1) || (auswahl > 8)) {
				printf("\nFehlerhafte Eingabe!");
				getchar();
			}
		} while ((auswahl < 1) || (auswahl > 8));

		//Men�auswahl
		switch (auswahl) {
			//Datens�tze eingeben
		case 1: {
			eingabe(Datensatz);
			break;
		}
				//Datens�tze ausgeben
		case 2: {
			ausgabe(Datensatz);
			break;
		}
				//Datens�tze durchsuchen
		case 3: {
			suchen(Datensatz);
			break;
		}
				//Datens�tze speichern
		case 4: {
			speichern(Datensatz);
			break;
		}
				//Datensatz �ndern
		case 5: {
			aendern(Datensatz);
			break;
		}
				//Datensatz l�schen
		case 6: {
			loeschen(Datensatz);
			break;
		}
				//Datens�tze als BibTex exportieren
		case 7: {
			exportbib(Datensatz);
			break;
		}
				//Programm beenden
		case 8: {
			do {
				clear();
				printf("Programm beenden.\n\n");
				printf("Aenderungen speichern?\n\nJa..... 1\nNein... 2\n\nAuswahl: ");
				fgets(buf, 10, stdin);			//Auswahl abfragen
				sscanf(buf, "%i", &c);			//Auswahl als Zahl umwandeln
				if ((c < 1) || (c > 2)) {
					printf("\nFehlerhafte Eingabe!");	//Fehlerhafte Eingabe abfangen
					getchar();
				}
			} while ((c < 1) || (c > 2));
			if (c == 1) {
				speichern(Datensatz);			//Datens�tze speichern
			}
			a = 0;
			break;
		}
		}
	}

	return 0;
}