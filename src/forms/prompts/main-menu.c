//
// Autore: Lorenzo Rocca
//

//
// Inclusioni
//

#pragma region Inclusioni

#include "forms.h"

#pragma endregion

//
// Main Menu Form
//

#pragma region Form

void printMainMenuForm(int error, const char* errorMessage, int logged, Account userAccount) {
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

void launchMainMenu(int* logged, Account* userAccount) {
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
        printMainMenuForm(errorState, errorMessage, *logged, *userAccount);

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
                if (*logged == 0) {
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
