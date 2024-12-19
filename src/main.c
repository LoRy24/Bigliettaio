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

/**
 * Ottiene la larghezza della console in caratteri.
 */
int getConsoleWidth();

#pragma endregion

//
// Routine Principale
//

#pragma region Routine principale

/**
 * Entry point del programma
 */
int main() {
    // Imposta il charset in UTF-8
    system("chcp 65001");

    // Imposta la larghezza del form
    FORM_WIDTH = getConsoleWidth();

    // Variabili generali ma da utilizzare ovunque
    #pragma region Variabili Generali

    // Stato di login dell'utente
    int logged = 0;

    // Account dell'utente
    Account* userAccount = malloc(sizeof(Account));
    clearStringBuffer(userAccount->name, 128);
    clearStringBuffer(userAccount->surname, 128);
    userAccount->admin = 0;
    userAccount->age = 0;

    #pragma endregion

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

    // Avvia il menù principale e definisci una struttura per le credenziali
    launchMainMenu(&logged, userAccount);

    // Pulisci la memoria
    free(userAccount);

    // Esci dal programma
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

int getConsoleWidth() {
    // Ottieni le informazioni sulla console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns; // Risultato

    // Ottieni le informazioni sulla console
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    // Calcola la larghezza della console
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Ritorna la larghezza
    return columns;
}

#pragma endregion
