//
// Autore: Lorenzo Rocca
//

#ifndef CHECKOUT_H
#define CHECKOUT_H

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
 * Lancia il menu di checkout per l'acquisto dei biglietti precedentemente selezionati
 * 
 * @param event Evento selezionato
 * @param buyer Account dell'acquirente
 * @param sFullPrice Numero di biglietti interi selezionati
 * @param sO65 Numero di biglietti over 65 selezionati
 * @param sU14 Numero di biglietti under 14 selezionati
 * 
 * @return int Ritorna il codice di uscita del form
 */
int launchCheckoutMenu(Event event, Account buyer, int sFullPrice, int sO65, int sU14);

#pragma endregion

#endif