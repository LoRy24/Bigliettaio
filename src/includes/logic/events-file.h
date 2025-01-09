//
// Autore: Lorenzo Rocca
//

#ifndef EVENTS_FILE_H
#define EVENTS_FILE_H

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
 * Crea il file degli eventi se non esiste
 */
int createEventsFile();

/**
 * Carica gli eventi dal file
 * 
 * @param eventsCount Puntatore al numero di eventi
 */
Event* loadEvents(int* eventsCount);

/**
 * Crea un evento all'indice specificato
 * 
 * @param event Evento da creare
 * @param eventIndex Indice dell'evento (deve essere compreso fra gli eventi già presenti oppure subito uno dopo)
 */
void createEventAtIndex(Event event, int eventIndex);

/**
 * Elimina l'evento all'indice specificato
 * 
 * @param eventIndex Indice dell'evento
 */
void deleteEvent(int eventIndex);

/**
 * Ottiene il primo ID disponibile per un evento
 * 
 * @return ID disponibile
 */
int getFirstAvailableId();

/**
 * Elimina un evento tramite l'ID
 * 
 * @param eventId ID dell'evento
 */
void deleteEventByEventId(int eventId);

/**
 * Aggiorna un evento tramite l'ID
 * 
 * @param eventId ID dell'evento
 * @param newEvent Nuovo evento
 */
void updateEventByEventId(int eventId, Event newEvent);

/**
 * Rimuove i biglietti da un evento
 * 
 * @param event Evento
 * @param amount Quantità di biglietti da rimuovere
 */
void removeTicketsFromEvent(Event event, int amount);

#pragma endregion

#endif
