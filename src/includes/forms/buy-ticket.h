//
// Autore: Lorenzo Rocca
//

#ifndef BUY_TICKET_H
#define BUY_TICKET_H

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
 * Lancia il form per l'acquisto dei biglietti per un evento
 * 
 * @param selectedEvent Evento selezionato
 * @param buyer Account dell'acquirente
 * @return int Ritorna il codice di uscita del form
 */
int launchTicketPurchaseMenu(Event selectedEvent, Account buyer);

#pragma endregion

#endif