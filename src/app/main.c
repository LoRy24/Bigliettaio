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

// Spinner caricamento ⣾⣽⣻⢿⡿⣟⣯⣷
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

/**
 * Crea le cartelle necessarie per il funzionamento del programma.
 */
int createFolders();

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
    SetConsoleOutputCP(CP_UTF8);

    // Setup dei files
    int result = createFolders();

    // Crea file eventi
    int eventsFileCreation = createEventsFile();

    // Crea file statistiche
    int statsFileCreation = createStatsFile();

    // Controllo se è andato tutto bene
    if (result != 0 || eventsFileCreation != 0 || statsFileCreation != 0) {
        // Stampa un errore
        printf("Errore durante la creazione delle risorse necessarie per il funzionamento del programma.\n");

        // Esci dal programma
        return 1;
    }

    // Imposta la larghezza del form
    FORM_WIDTH = getConsoleWidth();

    // Variabili generali ma da utilizzare ovunque
    #pragma region Variabili Generali

    // Stato di login dell'utente
    int logged = 0;

    // Account dell'utente
    Account* userAccount = malloc(sizeof(Account));
    clearStringBuffer(userAccount->name, 129);
    clearStringBuffer(userAccount->surname, 129);
    clearStringBuffer(userAccount->username, 33);
    clearStringBuffer(userAccount->hashedPassword, 65);
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

int createFolders() {
    // Crea la cartella data
    int s1 = mkdir(DATA_FOLDER);

    // Controllo se la cartella è stata creata
    if (s1 != 0 && errno != EEXIST) {
        return 1;
    }

    // Crea la cartella degli utenti
    int s2 = mkdir(USERS_FOLDER);

    // Controllo se la cartella è stata creata
    if (s2 != 0 && errno != EEXIST) {
        return 2;
    }

    // Tutto ok
    return 0;
}

#pragma endregion
