//
// Autore: Lorenzo Rocca
//

#ifndef ADMIN_H
#define ADMIN_H

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

/**
 * Stampa un messaggio di errore nel menu di amministrazione.
 * 
 * @param message Messaggio di errore da stampare.
 */
void printErrorMessageAdminMenu(char* message);

/**
 * Stampa il menu di amministrazione.
 * 
 * @param account Account dell'utente loggato.
 */
void printAdminMenu(Account account);

/**
 * Lancia il menu di amministrazione.
 * 
 * @param account Account dell'utente loggato.
 */
int launchAdminMenu(Account account);

#pragma endregion

#endif