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

/**
 * Questa funzione permette di verificare se una data è valida.
 * Formato validazione: mmyyyy
 * 
 * @param date La data da verificare
 * @return 1 se la data è valida, -1 se il mese non è valido, -2 se la carta è scaduta
 */
int isDateValid(char* date);

#pragma endregion

#endif