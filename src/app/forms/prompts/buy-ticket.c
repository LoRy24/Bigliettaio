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
// Tickets Form
//

#pragma region Form

int launchTicketPurchaseMenu(Event selectedEvent, Account buyer) {
    // Pulisci lo schermo
    system("cls");

    // Head
    printf("Biglietto selezionato: %s\n", selectedEvent.name);
    printf("Acquirente: %s %s\n", buyer.name);

    int c = getch();

    return MENU_GOTO_MAIN_MENU;
}

#pragma endregion