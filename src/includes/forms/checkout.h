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
 * Stampa un messaggio di errore per il form di checkout
 * 
 * @param message Messaggio di errore
 */
void printErrorMessageCheckout(char* message);

/**
 * Stampa i dettagli della carta di credito nel seguente formato:
 * 
 *                Dettagli Carta
 * ----------------------- ----------- ---------
 * Numero Carta            Scadenza    CVV      
 * ____ ____ ____ ____     __/____     ___      
 *
 * Nome sulla carta
 * _____________________________________________
 * 
 * Dove al posto delle linee sono presenti i dettagli della carta di credito o debito. I
 * dettagli sono passati come parametro tutti consecutivamente.
 * 
 * @param details Dettagli della carta di credito
 */
void printDebitCardDetails(char* details);

/**
 * Stampa il menu di checkout per l'acquisto dei biglietti
 * 
 * @param eventName Nome dell'evento
 * @param totalPrice Prezzo totale
 */
void printCheckoutMenu(char* eventName, float totalPrice);

/**
 * Stampa il menu di successo per il checkout
 * 
 * @param orderId ID dell'ordine
 * @param eventName Nome dell'evento
 * @param tickets Numero di biglietti acquistati
 * @param paidAmount Importo pagato
 */
void printCheckoutSuccessMenu(int orderId, char* eventName, int tickets, float paidAmount);

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