// Gobblet_Mampfer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#pragma once
#include <tuple>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include "Bot_Brain.h"
#include "Game_Field.h"
#include <random>

int main()
{
	Bot_Brain Brain;
	Game_Field gobblet;
	
	gobblet.printField();

	while (gobblet.checkForWin() == 0) {
		gobblet.setField(Brain.think(gobblet));
		gobblet.printField();
		if (gobblet.checkForWin() != 0) {
			break;
		}
		gobblet.setField(Brain.makeRndMove(gobblet));
		gobblet.printField();
	}
	std::cout << to_string(gobblet.checkForWin()) << endl;
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
