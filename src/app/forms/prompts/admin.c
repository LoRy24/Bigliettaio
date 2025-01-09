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
// Admin form
//

#pragma region Form

void printErrorMessageAdminMenu(char* message) {
    // Prepara il messaggio di errore
    char* text = malloc(strlen(message) + 16);
    sprintf(text, "-> Errore! %s <-", message);

    // Stampa il messaggio di errore
    moveCursor(0, 10);
    printCenteredText(text);

    // Pulisci la memoria
    free(text);

    // Azzera il cursore
    moveCursor(0, 0);
}

void printAdminMenu(Account account) {
    // Intestazione
    printHead();
    printLine();

    // Spaziatura
    printWhiteSpace();

    // Titolo
    printCenteredText("Pannello di Amministrazione");

    // Scrivi l'account utilizzato per il login
    char* accountText = malloc(256);
    sprintf(accountText, "Account: %s %s", account.name, account.surname);
    printCenteredText(accountText);
    free(accountText);

    // Indicazioni uso menu
    printCenteredText("-> Usa i tasti esposti per navigare <-"); // Riga 10

    // Spaziatura
    printWhiteSpace();

    // Pulsanti
    printCenteredText("Operazioni Admin");
    printCenteredText("< 1. Gestione eventi  >");
    printCenteredText("< 2. Gestione account >");

    // Spaziatura
    printWhiteSpace();

    // Pulsanti generali
    printCenteredText("Pulsanti Generali");
    printCenteredText("< esc. Torna indietro >");
    printCenteredText("< ctrl + x. Esci >");

    // Spaziatura
    printWhiteSpace();

    // Linea
    printLine();

    // Spaziatura
    printWhiteSpace();

    // Titolo statistiche
    printCenteredText("Statistiche");

    // Ottieni le statistiche
    SellsStats stats = getSellsStats();

    // Scrivi le statistiche

    // Biglietti venduti
    char* statsText = malloc(128);
    sprintf(statsText, "Biglietti venduti: %d", stats.soldTickets);
    printCenteredText(statsText);
    
    // Incassi totali
    sprintf(statsText, "Incassi totali: %.2f$", stats.totalEarnings);
    printCenteredText(statsText);

    // Profitto
    sprintf(statsText, "Profitto ~ reseller: %.2f$", stats.profits);
    printCenteredText(statsText);

    // Tasse
    sprintf(statsText, "Tasse (IVA): %.2f$", stats.taxes);
    printCenteredText(statsText);

    // Libera la memoria
    free(statsText);

    // Spaziatura
    printWhiteSpace();

    // Linea
    printLine();

    // Azzera il cursore
    moveCursor(0, 0);
}

int launchAdminMenu(Account account) {
    // Pulisci lo schermo
    system("cls");

    // Stampa il menu
    printAdminMenu(account);

    // Gestione input
    while (1) {
        // Input
        int c = _getch();

        // Se uguale a esc, torna al menu precedente
        if (c == KEY_ESCAPE) {
            // Turna endre
            system("cls");
            return MENU_GO_BACK;
        }

        // Se equivale a CTRL + X, esci
        if (c == KEY_CTRL_X) {
            system("cls");
            return MENU_PROGRAM_EXIT;
        }

        // Gestisci altri input
        switch (c) {
            case '1':
            case '2': {
                // Non implementato
                printErrorMessageAdminMenu(ERROR_MESSAGE_NOT_IMPLEMENTED);
                break;
            }

            default: {
                // Errore di comando non trovato
                printErrorMessageAdminMenu(ERROR_MESSAGE_INVALID_COMMAND);
                break;
            }
        }
    }

    // Ritorna al menu principale
    return MENU_GO_BACK;
}

#pragma endregion