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

    // Se è loggato, mostra il pulsante per il logout
    if (logged == 1) {
        printCenteredText("< 4. Effettua Logout >");
    }

    printWhiteSpace();
    printCenteredText("< ctrl + x. Esci >");
    printWhiteSpace();
    printCenteredText("Account: ");

    // Scrivi l'account
    if (logged == 1) {
        // Prepara la stringa dell'account  
        char* text = malloc(strlen(userAccount.name) + strlen(userAccount.surname) + 1);
        sprintf(text, "%s%s %s",userAccount.admin == 1 ? ADMIN_PREFIX : "", userAccount.name, userAccount.surname);
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

    // Credenziali temporanee
    Credentials credentials;

    // Inizia il ciclo di richiesta
    do {
        // Pulisci lo schermo
        system("cls");
        fflush(stdout);

        // Stampa il form principale
        printMainMenuForm(errorState, errorMessage, *logged, *userAccount);

        // Leggi carattere da tastiera
        char c = _getch();

        // Se il carattere è CTRL + X, esci dal programma
        if (c == KEY_CTRL_X) {
            break;
        }

        // In base al carattere letto
        switch (c) {
            case '1': {
                // Se l'utente non è autenticato, dai un errore
                if (*logged == 0) {
                    errorState = 1;
                    errorMessage = ERROR_MESSAGE_NOT_LOGGED;
                    continue;
                }
            }

            case '2': {
                // Se l'utente è già autenticato, dai un errore
                if (*logged == 1) {
                    errorState = 1;
                    errorMessage = ERROR_MESSAGE_ALREADY_LOGGED;
                    continue;
                }

                // Esegui il form di login
                int loginMenu = launchLoginMenu(&credentials);

                if (loginMenu == 1) {
                    goto mainMenuEnd;
                }
                else if (loginMenu == 2) {
                    continue;
                }
                else if (loginMenu == 0) {
                    // Impostazioni bools
                    errorState = 0;
                    *logged = 1; // Imposta lo stato di login

                    // Prendi le credenziali e salva l'account
                    strcpy(userAccount->name, credentials.username);
                    userAccount->admin = 1; // DEBUG: Imposta per ora admin

                    // Continua
                    continue;
                }
                else {
                    // Errore di comando non trovato
                    errorState = 1;
                    errorMessage = ERROR_MESSAGE_INTERNAL_ERROR;
                    continue;
                }

                // Non fare altro
                break;
            }

            case '3': {
                errorState = 1;
                errorMessage = ERROR_MESSAGE_NOT_IMPLEMENTED;
                continue;
            }

            case '4': {
                // Se l'utente non è autenticato, dai un errore
                if (*logged == 0) {
                    errorState = 1;
                    errorMessage = ERROR_MESSAGE_NOT_LOGGED;
                    continue;
                }

                // Effettua il logout
                *logged = 0;
                strcpy(userAccount->name, "");
                userAccount->admin = 0;
                credentials = (Credentials) { "", "" }; // Pulisci le credenziali

                // Continua
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
