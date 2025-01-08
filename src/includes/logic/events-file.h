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

int getFirstAvailableId();

void deleteEventByEventId(int eventId);

void updateEventByEventId(int eventId, Event newEvent);

void removeTicketsFromEvent(Event event, int amount);

#pragma endregion

#endif
