//
// Autore: Lorenzo Rocca
//

#ifndef UTILS_H
#define UTILS_H

//
// Inclusioni
//

#pragma region Inclusioni

// Globali
#include "globals.h"

#pragma endregion

//
// Prototipi Funzioni
//

#pragma region Prototipi Funzioni

/**
 * Questa funzione permette di attendere un numero definito di millisecondi. Utilizza
 * nanosleep
 * 
 * @param msec Il numero di millisecondi da attendere
 */
int msleep(long msec);

/**
 * Questa funzione calcola la commissione applicata sul prezzo inserito in base alla percentuale.
 * 
 * @param price Il prezzo su cui calcolare la commissione
 * @param percentage La percentuale da applicare
 */
float calculateCommission(float price, float percentage);

/**
 * Questa funzione permette di pulire un buffer di caratteri, impostando tutti i caratteri
 * a '\0'.
 * 
 * @param buffer Il buffer da pulire
 * @param length La lunghezza del buffer
 */
void clearStringBuffer(char* buffer, int length);

#pragma endregion

#endif