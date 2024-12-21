//
// Autore: Lorenzo Rocca
//

#ifndef LOGIN_H
#define LOGIN_H

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
 * Questa funzione costruisce un box di input per il login
 * 
 * @param buffer Il buffer in cui scrivere il box
 * @param text Il testo da inserire nel box
 */
void buildLoginInputBox(char* buffer, char* text);

/**
 * Stampa un messaggio di errore per il login
 * 
 * @param errorMessage Il messaggio di errore da stampare
 */
void printErrorMessageLogin(const char* errorMessage);

/**
 * Stampa il prompt per l'username
 * 
 * @param username L'username da stampare
 */
void printUsernamePrompt(char* username);

/**
 * Stampa il prompt per la password (con asterischi)
 * 
 * @param password La password da stampare
 */
void printPasswordPrompt(char* password);

/**
 * Aggiorna uno dei due prompt
 * 
 * @param selected Il campo selezionato
 * @param content Il contenuto del campo
 */
void updatePrompt(int selected, char* content);

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

#pragma endregion

#endif
