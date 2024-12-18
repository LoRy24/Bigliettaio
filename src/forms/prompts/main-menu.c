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

void printUserAccount(int logged, Account userAccount) {
    // Scrivi l'account
    if (logged == 1) {
        // Prepara la stringa dell'account
        char* text = malloc(strlen(userAccount.name) + strlen(userAccount.surname) + 32); // Grazie per il 32 che mi ha fatto perdere una settimana a smattare
        sprintf(text, "%s%s %s", userAccount.admin == 1 ? ADMIN_PREFIX : "", userAccount.name, userAccount.surname);

        // Stampa a schermo
        moveCursor(0, 19);
        printCenteredText(text);

        // Pulisci la memoria
        free(text);
    }
    else {
        // Stampa a schermo
        moveCursor(0, 19);
        printCenteredText("Non autenticato");
    }

    // Azzera il cursore
    moveCursor(0, 0);
}

void printErrorMessage(const char* errorMessage) {
    // Prepara il messaggio di errore
    char* text = malloc(strlen(errorMessage) + 16);
    sprintf(text, "-> Errore! %s <-", errorMessage);

    // Stampa il messaggio di errore
    moveCursor(0, 9);
    printCenteredText(text);

    // Pulisci la memoria
    free(text);

    // Azzera il cursore
    moveCursor(0, 0);
}

void printMainMenuForm(int logged, Account userAccount) {
    // Pulisci lo schermo
    system("cls");

    // Head
    printHead();

    // Prima parte
    printLine();
    printWhiteSpace();
    printCenteredText("Scegli un operazione da svolgere");

    // Messaggio sotto-titolo
    printCenteredText("-> Attesa Input <-");

    // Pulsanti
    printWhiteSpace();
    printCenteredText("< 1. Lista Biglietti >");
    printCenteredText("< 2. Effettua Login  >");
    printCenteredText("< 3. Crea Account    >");
    printCenteredText("< 4. Effettua Logout >");

    printWhiteSpace();
    printCenteredText("< ctrl + x. Esci >");
    printWhiteSpace();
    printCenteredText("Account: ");

    // Scrivi l'account
    printUserAccount(logged, userAccount);

    moveCursor(0, 20);
    printWhiteSpace();
    printLine();

    // Azzera il cursore
    moveCursor(0, 0);
}

void launchMainMenu(int* logged, Account* userAccount) {
    // Credenziali temporanee
    Credentials* credentials = malloc(sizeof(Credentials));
    clearStringBuffer(credentials->username, 33);
    clearStringBuffer(credentials->password, 33);

    // Stampa il form principale
    printMainMenuForm(*logged, *userAccount);

    // Inizia il ciclo di richiesta
    do {
        // Leggi carattere da tastiera
        int c = _getch();

        // Se il carattere è CTRL + X, esci dal programma
        if (c == KEY_CTRL_X) {
            // Pulisci lo schermo
            system("cls");
            break;
        }

        // In base al carattere letto
        switch (c) {
            case '1': {
                // Se l'utente non è autenticato, dai un errore
                if (*logged == 0) {
                    printErrorMessage(ERROR_MESSAGE_NOT_LOGGED);
                    break;
                }

                break;
            }

            case '2': {
                // Se l'utente è già autenticato, dai un errore
                if (*logged == 1) {
                    printErrorMessage(ERROR_MESSAGE_ALREADY_LOGGED);
                    break;
                }

                // Esegui il form di login
                int loginMenu = launchLoginMenu(credentials);

                // Ristampa il form principale
                printMainMenuForm(*logged, *userAccount);

                if (loginMenu == 1) {
                    goto mainMenuEnd;
                }
                else if (loginMenu == 2) {
                    break;
                }
                else if (loginMenu == 0) {
                    // Impostazioni bools
                    *logged = 1; // Imposta lo stato di login

                    // Prendi le credenziali e salva l'account
                    sprintf(userAccount->name, "%s", credentials->username);
                    userAccount->admin = 1; // DEBUG: Imposta per ora admin

                    // Scrivi l'account
                    printUserAccount(*logged, *userAccount);

                    // Esci dallo switch
                    break;
                }
                else {
                    // Errore di comando non trovato
                    printErrorMessage(ERROR_MESSAGE_INTERNAL_ERROR);
                    break;
                }

                // Non fare altro
                break;
            }

            case '3': {
                printErrorMessage(ERROR_MESSAGE_NOT_IMPLEMENTED);
                break;
            }

            case '4': {
                // Se l'utente non è autenticato, dai un errore
                if (*logged == 0) {
                    printErrorMessage(ERROR_MESSAGE_NOT_LOGGED);
                    break;
                }

                // Effettua il logout
                *logged = 0;

                // Pulisci le credenziali
                clearStringBuffer(credentials->username, 32);
                clearStringBuffer(credentials->password, 32);

                // Pulisci l'account
                clearStringBuffer(userAccount->name, 32);
                clearStringBuffer(userAccount->surname, 32);
                userAccount->admin = 0;
                userAccount->age = 0;

                printUserAccount(*logged, *userAccount);

                // Continua
                break;
            }
        
            default: {
                // Errore di comando non trovato
                printErrorMessage(ERROR_MESSAGE_INVALID_COMMAND);
                break;
            }
        }
    } while(1);

    mainMenuEnd:

    // Pulisci la memoria
    free(credentials);

    return;
}

#pragma endregion
