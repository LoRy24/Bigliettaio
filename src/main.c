//
// Autore: Lorenzo Rocca
//

#pragma region Inclusioni

// Librerie Progetto
#include "globals.h"
#include "forms.h"

#pragma endregion

#pragma region Definizioni

// Spinner caricamento 
char SPINNER_STATES[8] = {'|', '/', '-', '\\', '|', '/', '-', '\\'};

#pragma endregion

#pragma region Prototipi

/**
 * Questa funzione permette di attendere un numero definito di millisecondi. Utilizza
 * nanosleep
 * 
 * @param msec Il numero di millisecondi da attendere
 */
int msleep(long msec);

/**
 * Stampa un messaggio di benvenuto contenente la versione del programma. Il messaggio è 
 * racchiuso in una cornice composta da '#'.
 */
void printWelcomeMessage();

/**
 * Questa funzione avvia il menù principale.
 */
void launchMainMenu();

#pragma endregion

#pragma region Variabili Globali

// Stato di login dell'utente
int logged = 0;
Account userAccount;

#pragma endregion

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
    launchMainMenu();

    return 0;
}

#pragma endregion

#pragma region Definizioni funzioni generali

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

void printMainMenuForm(int error, const char* errorMessage) {
    // Prima parte
    printLine();
    printWhiteSpace();
    printCenteredText("Scegli un operazione da svolgere");

    // Messaggio sotto-titolo
    if (error == 1) {
        char* text = malloc(strlen(errorMessage) + 14);
        sprintf(text, "-> Errore! %s <-", errorMessage);
        printCenteredText(text);
    }
    else {
        printCenteredText("-> Attesa Input <-");
    }

    // Pulsanti
    printWhiteSpace();
    printCenteredText("< 1. Lista Biglietti >");
    printCenteredText("< 2. Effettua Login  >");
    printCenteredText("< 3. Crea Account    >");
    printWhiteSpace();
    printCenteredText("< q. Esci >");
    printWhiteSpace();
    printLine();
}

#pragma endregion

#pragma region Forms

void launchMainMenu() {
    // Definisco eventuali errori
    int errorState = 0;
    char* errorMessage;
    errorMessage = NULL;

    // Inizia il ciclo di richiesta
    do {
        // Pulisci lo schermo
        printf("\e[1;1H\e[2J");
        fflush(stdout);

        // Stampa il form principale
        printMainMenuForm(errorState, errorMessage);

        // Leggi carattere da tastiera
        char c = _getch();

        // Se il carattere è la q, esci dal programma
        if (c == 'q') {
            break;
        }

        // In base al carattere letto
        switch (c) {
            case '1':
            case '2': 
            case '3': {
                errorState = 1;
                errorMessage = "Coming Soon!";
                continue;
            }
        
            default: {
                // Errore di comando non trovato
                errorState = 1;
                errorMessage = "Comando invalido!";
                break;
            }
        }
    } while(1);
}

#pragma endregion

#pragma region Utils

int msleep(long msec) {
    // Definisco alcune variabili locali
    struct timespec ts;
    int res;

    // Solo numeri di millisecondi positivi
    if (msec < 0) {
        errno = EINVAL;
        return -1;
    }

    // Ricavo il tempo di attesa
    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    // Tento l'esecuzione finchè non viene svolta
    do {
        res = nanosleep(&ts, NULL);
    } while (res && errno == EINTR);

    // Ritorno lo stato di uscita
    return res;
}

#pragma endregion
