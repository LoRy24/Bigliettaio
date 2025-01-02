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

// Librerie forms
#include "forms/login.h"
#include "forms/main-menu.h"
#include "forms/tickets.h"
#include "forms/buy-ticket.h"

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

// Cursor

/**
 * Questa funzione sposta il cursore nella console alla posizione specificata.
 * 
 * @param x La coordinata x
 * @param y La coordinata y
 */
void moveCursor(int x, int y);

#pragma endregion

#endif
