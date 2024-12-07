//
// Autore: Lorenzo Rocca
//

#ifndef FORMS_H
#define FORMS_H

#pragma region Inclusioni

// Librerie interne al progetto
#include "globals.h"

#pragma endregion

#pragma region Prototipi Funzioni

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

#pragma endregion

#endif
