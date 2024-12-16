//
// Autore: Lorenzo Rocca
//

#pragma region Inclusioni

// Librerie Progetto
#include "globals.h"

#pragma endregion

//
// Definizioni Locali
//

#pragma region Definizioni Locali

// Spinner caricamento 
char SPINNER_STATES[8] = {'|', '/', '-', '\\', '|', '/', '-', '\\'};

#pragma endregion

//
// Prototipi Funzioni
//

#pragma region Prototipi

/**
 * Stampa un messaggio di benvenuto contenente la versione del programma. Il messaggio è 
 * racchiuso in una cornice composta da '#'.
 */
void printWelcomeMessage();

#pragma endregion

//
// Variabili Globali
//

#pragma region Variabili Globali

// Stato di login dell'utente
int logged = 0;
Account userAccount;

#pragma endregion

//
// Routine Principale
//

#pragma region Routine principale

/**
 * Entry point del programma
 */
int main() {
    // Pulisci lo schermo per sicurezza
    system("cls");

    // Stampa il messaggio di benvenuto
    printWelcomeMessage();

    // Spazio bianco
    printf("\n");

    // Piccolo caricamento
    for (int i = 0; i < 20; ++i) {
        printf("\rCaricamento in corso %c", SPINNER_STATES[i % 8]);
        msleep(125);
    }

    // Scrivi che il caricamento è stato completato
    printf("\rCaricamento completato!");

    // Attendi 1s
    sleep(1);

    // Pulisci lo schermo
    system("cls");

    // Avvia il menù principale
    launchMainMenu(&logged, &userAccount);

    return 0;
}

#pragma endregion

//
// Funzioni Generali
//

#pragma region Definizioni funzioni generali

void printHead() {
    printLine();
    printWhiteSpace();
    printCenteredText("Bigliettaio V1");
    printCenteredText("Versione: " VERSION);
    printWhiteSpace();
}

void printWelcomeMessage() {
    // Stampa il messaggio di benvenuto
    printLine();
    printWhiteSpace();
    printCenteredText("Benvenuto in Bigliettaio V1!");
    printCenteredText("Versione: " VERSION);
    printWhiteSpace();
    printWhiteSpace();
    printCenteredText("Made by Lorenzo Rocca");
    printWhiteSpace();
    printLine();
}

#pragma endregion
