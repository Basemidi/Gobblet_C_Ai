
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
#include "IO_controller.h"
/*
Main class. Creates a Bot_Brain object a Game_Field object and a IO_controller object. As long as the game is not over the Game_Field gets actions from the AI and the human player.

@var Brain: Bot_Brain object represents the AI.
@var human: IO_controller object is used for the human input.
@var gobblet: Game_Field object represents the game.
*/
int main()
{
	Bot_Brain Brain;
	IO_controller human;
	Game_Field gobblet;
	
	gobblet.printField();


	while (gobblet.checkForWin() == 0) {
		gobblet.setField(Brain.think(gobblet));
		gobblet.printField();
		if (gobblet.checkForWin() != 0) {
			break;
		}
		gobblet.setField(human.get_Input(gobblet));
		gobblet.printField();
	}
	std::cout << to_string(gobblet.checkForWin()) << endl;
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwend^en Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
