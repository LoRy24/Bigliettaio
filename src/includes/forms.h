//
// Autore: Lorenzo Rocca
//

#ifndef FORMS_H
#define FORMS_H

//
// Inclusioni
//

#pragma region Inclusioni

// Librerie interne al progetto
#include "globals.h"

#pragma endregion

//
// Prototipi Funzioni
//

#pragma region Prototipi Funzioni

// Stesura form

/**
 * Stampa una linea composta da '#' ai lati e '-' al centro. La lunghezza della linea è 
 * definita dalla costante FORM_WIDTH.
 */
void printLine();

/**
 * Stampa un testo centrato all'interno di una cornice composta da '#'. Il testo è centrato
 * rispetto alla larghezza definita dalla costante FORM_WIDTH. Se il testo è più lungo della
 * larghezza, verrà troncato.
 * 
 * @param text Il testo da centrare.
 */
void printCenteredText(const char* text);

/**
 * Stampa una riga composta da '#' ai lati e ' ' al centro. La lunghezza della riga è definita
 * dalla costante FORM_WIDTH.
 */
void printWhiteSpace();

/**
 * Stampa un testo allineato a sinistra all'interno di una cornice composta da '#'.
 * 
 * @param text Il testo da allineare a sinistra.
 */
void printLeftAlignedText(const char* text);

/**
 * Stampa un testo allineato a destra all'interno di una cornice composta da '#'.
 * 
 * @param text Il testo da allineare a destra.
 */
void printRightAlignedText(const char* text);

/**
 * Vai a capo
 */
void newline();

// Utility forms

/**
 * Stampa l'intestazione dei form
 */
void printHead();

// Menu Principale

/**
 * Stampa il form del menu principale
 * 
 * @param logged Se l'utente è loggato
 * @param userAccount L'account dell'utente
 */
void printMainMenuForm(int logged, Account userAccount);

/**
 * Questa funzione avvia il menù principale.
 * 
 * @param logged Lo stato di login dell'utente
 * @param userAccount L'account dell'utente
 */
void launchMainMenu(int* logged, Account* userAccount);

// Login

/**
 * Stampa il form del login
 * 
 * @param selected Il campo selezionato
 */
void printLoginMenuForm(int selected);

/**
 * Avvia il menu di login
 * 
 * @param credentials Le credenziali dell'utente
 */
int launchLoginMenu(Credentials* credentials);

/**
 * Questa funzione sposta il cursore nella console alla posizione specificata.
 * 
 * @param x La coordinata x
 * @param y La coordinata y
 */
void moveCursor(int x, int y);

#pragma endregion

#endif
