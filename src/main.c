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
 * Questa funzione avvia il menù principale.
 */
void launchMainMenu();

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
    //system("cls");

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

void printMainMenuForm(int error, const char* errorMessage) {
    // Head
    printHead();

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
    printCenteredText("Account: ");

    // Scrivi l'account
    if (logged == 1) {
        // Prepara la stringa dell'account  
        char* text = malloc(strlen(userAccount.name) + strlen(userAccount.surname) + 1);
        sprintf(text, "%s %s", userAccount.name, userAccount.surname);
        printCenteredText(text);
    }
    else {
        printCenteredText("Non autenticato");
    }

    printWhiteSpace();
    printLine();
}

#pragma endregion

//
// Forms
//

#pragma region Forms

void launchMainMenu() {
    // Definisco eventuali errori
    int errorState = 0;
    char* errorMessage;
    errorMessage = NULL;

    // Inizia il ciclo di richiesta
    do {
        // Pulisci lo schermo
        system("cls");
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
            case '1': {
                // Se l'utente non è autenticato, dai un errore
                if (logged == 0) {
                    errorState = 1;
                    errorMessage = "Non hai eseguito l'accesso!";
                    continue;
                }
            }

            case '2': {
                // Esegui il form di login
                int loginMenu = launchLoginMenu();

                if (loginMenu == 1) {
                    goto mainMenuEnd;
                }
                else if (loginMenu == 2) {
                    continue;
                }

                // Non fare altro
                break;
            }

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

    mainMenuEnd:
    return;
}

#pragma endregion
