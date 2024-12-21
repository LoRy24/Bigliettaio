//
// Autore: Lorenzo Rocca
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

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
 * Questa funzione scrive l'account dell'utente a schermo.
 * 
 * @param logged Se l'utente è loggato
 * @param userAccount L'account dell'utente
 */
void printUserAccount(int logged, Account userAccount);

/**
 * Questa funzione stampa un messaggio di errore nel menu principale.
 * 
 * @param errorMessage Il messaggio di errore da stampare
 */
void printErrorMessageMainMenu(const char* errorMessage);

/**
 * Stampa il form del menu principale.
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

#pragma endregion

#endif
