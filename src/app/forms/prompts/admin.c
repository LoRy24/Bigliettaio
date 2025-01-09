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
// Checkout Form
//

#pragma region Form

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

    // Attendi un input
    int c = _getch();

    // Ritorna al menu principale
    return MENU_GO_BACK;
}

#pragma endregion