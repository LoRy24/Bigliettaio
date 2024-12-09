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
 */
void printLeftAlignedText(const char* text);

/**
 * Stampa un testo allineato a destra all'interno di una cornice composta da '#'.
 */
void printRightAlignedText(const char* text);

// Utility forms

/**
 * Stampa l'intestazione dei form
 */
void printHead();

// Login

/**
 * Stampa il form del login
 * 
 * @param username Il nome utente
 * @param password La password inserita
 * @param selected Il campo selezionato
 * @param error Se è presente un errore
 * @param errorMessage Il messaggio di errore
 */
void printLoginMenuForm(char* username, char* password, int selected, int error, const char* errorMessage);

/**
 * Avvia il menu di login
 */
int launchLoginMenu();

#pragma endregion

#endif
