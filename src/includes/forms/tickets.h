//
// Autore: Lorenzo Rocca
//

#ifndef TICKETS_H
#define TICKETS_H

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

// Selezione

/**
 * Stampa le frecce di selezione (con i caratteri specificati)
 * 
 * @param cardIndex Indice della card
 * @param c1 Primo carattere
 * @param c2 Secondo carattere
 */
void writeArrowsShape(int cardIndex, char c1, char c2);

/**
 * Cancella le frecce di selezione
 * 
 * @param cardIndex Indice della card
 */
void clearSelectionArrows(int cardIndex);

/**
 * Stampa le frecce di selezione
 * 
 * @param cardIndex Indice della card
 */
void writeSelectionArrows(int cardIndex);

/**
 * Seleziona una card
 * 
 * @param cardIndex Indice della card
 */
void selectCard(int cardIndex);

// Scrittura card

/**
 * Stampa una linea
 */
void printCardStraightLine();

/**
 * Stampa una linea vuota
 */
void printCardEmptyLine();

/**
 * Stampa un testo centrato in una card
 * 
 * @param text Testo da stampare
 */
void printCardCenteredText(const char* text);

/**
 * Stampa i prezzi in una card
 * 
 * @param basePrice Prezzo base
 */
void printCardPrices(float basePrice);

/**
 * Scrive la card di un biglietto (evento)
 * 
 * @param event Evento
 * @param row Riga da cui iniziare a scrivere
 */
void printTicketCard(Event event, int row);

// Menu

/**
 * Stampa la card di un evento
 * 
 * @param event Evento da stampare
 * @param selected Indice dell'evento selezionato
 * @param eventsCount Numero totale di eventi
 * @param updateCursor Se deve aggiornare il cursore
 */
void displayEventCard(Event event, int selected, int eventsCount, int updateCursor);

/**
 * Stampa il form per la vendita dei biglietti
 * 
 * @param displayEvent Evento da visualizzare
 * @param eventsCount Numero totale di eventi
 * @param selected Indice dell'evento selezionato
 */
void printTicketsMenuForm(Event displayEvent, int eventsCount, int selected);

/**
 * Stampa il form per la vendita dei biglietti
 * 
 * @param buyer Account dell'acquirente
 * @return int Ritorna il codice di uscita del form
 */
int launchTicketsMenu(Account buyer);

#pragma endregion

#endif