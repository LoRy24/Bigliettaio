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
 * Costruisce in un buffer un box contenente un numero intero
 * 
 * @param buffer Buffer in cui scrivere il box
 * @param number Numero da scrivere nel box
 */
void buildNumericInputBox(char* buffer, int number);

/**
 * Stampa un messaggio di errore per l'acquisto dei biglietti
 * 
 * @param errorMessage Messaggio di errore da stampare
 */
void printErrorMessageTicketCheckout(const char* errorMessage);

/**
 * Aggiunge spazi al buffer per riempire il box
 * 
 * @param buffer Buffer da riempire
 * @param size Dimensione del box
 */
void printPadding(char* buffer, int size);

/**
 * Aggiorna il valore selezionato
 * 
 * @param selection Valore selezionato [0, 2]
 */
void updateBuySelection(int selection);

/**
 * Scrive le righe dei costi dell'acquisto con i valori selezionati (qt)
 * 
 * @param ticketsTotalPrice Prezzo totale senza iva (prezzo evento netto + provvigione)
 * @param ivaPercentage Percentuale di iva da applicare
 */
void printPricesRows(float ticketsTotalPrice, float ivaPercentage);

/**
 * Aggiorna il valore selezionato
 * 
 * @param selected Valore selezionato
 * @param newValue Nuovo valore
 */
void updateSelectedValue(int selected, int newValue);

/**
 * Aggiorna il form a causa dell'aggiornamento di un valore
 * 
 * @param price Prezzo dell'evento
 * @param selectedTickets Array contenente i biglietti selezionati
 * @param editingParameter Parametro che si sta modificando
 */
void updateFormByValueUpdate(float price, int* selectedTickets, int editingParameter);

/**
 * Stampa il form per l'acquisto dei biglietti
 * 
 * @param eventName Nome dell'evento
 * @param price Prezzo dell'evento
 * @param selectedTickets Array contenente le qt dei biglietti selezionati
 */
void printTicketsPurchaseMenu(char* eventName, float price, int* selectedTickets);

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