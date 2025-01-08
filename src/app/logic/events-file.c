//
// Autore: Lorenzo Rocca
//

//
// Inclusioni
//

#pragma region Inclusioni

#include "globals.h"

#pragma endregion

//
// Funzioni
//

#pragma region Funzioni

int createEventsFile() {
    // Verifica se il file esiste
    if (access(EVENTS_FILE, F_OK) == 0) {
        // Ritorna 0
        return 0;
    }

    // Crea il file
    FILE* file = fopen(EVENTS_FILE, "wb");

    // Controlla se il file è stato creato
    if (file == NULL) {
        // Ritorna 1
        return 1;
    }

    // Crea due eventi di default
    int eventsCount = 3;
    fwrite(&eventsCount, sizeof(int), 1, file);

    // Definisco i 3 eventi
    Event event1 = {
        1,
        "Gli scrocconi",
        "Magi",
        "25/02/2025",
        "20:30",
        50,
        100,
        100
    };

    Event event2 = {
        2,
        "Gli scrocconi 2",
        "Magi",
        "25/02/2026",
        "20:30",
        55,
        100,
        100
    };

    Event event3 = {
        3,
        "F1 Monza",
        "Autodromo Monza",
        "5/09/2025",
        "15:00",
        249,
        10000,
        10000
    };

    // Scrivo gli eventi
    fwrite(&event1, sizeof(Event), 1, file);
    fwrite(&event2, sizeof(Event), 1, file);
    fwrite(&event3, sizeof(Event), 1, file);

    // Chiudi il file
    fclose(file);
}

Event* loadEvents(int* eventsCount) {
    // Apre il file
    FILE* file = fopen(EVENTS_FILE, "rb");

    // Controlla se il file è stato aperto
    if (file == NULL) {
        // Ritorna NULL
        return NULL;
    }

    // Legge il numero di eventi
    fread(eventsCount, sizeof(int), 1, file);

    // Alloca la memoria per gli eventi
    Event* events = malloc(sizeof(Event) * (*eventsCount));

    // Legge gli eventi
    for (int i = 0; i < *eventsCount; i++) {
        fread(&events[i], sizeof(Event), 1, file);
    }

    // Chiude il file
    fclose(file);

    // Ritorna gli eventi
    return events;
}

void createEventAtIndex(Event event, int eventIndex) {
    // Numero di eventi
    int eventsCount;

    // Alloca la memoria per gli eventi
    Event* events = loadEvents(&eventsCount);

    // Apre il file in scrittura
    FILE* file = fopen(EVENTS_FILE, "wb");

    // Incrementa il numero di eventi
    eventsCount++;

    // Scrive il numero di eventi
    fwrite(&eventsCount, sizeof(int), 1, file);

    // Scrive gli eventi
    for (int i = 0; i < eventsCount; i++) {
        // Se l'indice è quello dell'evento da creare, scrivi l'evento e continua
        if (i == eventIndex) {
            fwrite(&event, sizeof(Event), 1, file);
            continue;
        }

        // Scrivi l'evento
        fwrite(&events[i < eventIndex ? i : i - 1], sizeof(Event), 1, file);
    }

    // Chiude il file
    fclose(file);
}

void deleteEvent(int eventIndex) {
    // Legge il numero di eventi
    int eventsCount;

    // Alloca la memoria per gli eventi
    Event* events = loadEvents(&eventsCount);

    // Apre il file in scrittura
    FILE* file = fopen(EVENTS_FILE, "wb");

    // Decrementa il numero di eventi
    eventsCount--;

    // Scrive il numero di eventi
    fwrite(&eventsCount, sizeof(int), 1, file);

    // Scrive gli eventi
    for (int i = 0; i < eventsCount + 1; i++) {
        if (i == eventIndex) {
            continue;
        }

        fwrite(&events[i], sizeof(Event), 1, file);
    }

    // Chiude il file
    fclose(file);
}

#pragma endregion