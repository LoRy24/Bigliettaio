//
// Autore: Lorenzo Rocca
//

//
// Inclusioni e Definizioni
//

#pragma region Inclusioni e Definizioni

#include "forms.h"

// Definizioni a scopo locale
#define ERROR_ROW                       9
#define FULL_PRICE_TICKETS_NAME_ROW     11
#define FULL_PRICE_TICKETS_ROW          12
#define O65_TICKETS_NAME_ROW            14
#define O65_TICKETS_ROW                 15
#define U14_TICKETS_NAME_ROW            17
#define U14_TICKETS_ROW                 18
#define PRICES_TITLES_ROW               25
#define PRICES_VALUES_ROW               27

#pragma endregion

//
// Tickets Form
//

#pragma region Form

void buildNumericInputBox(char* buffer, int number) {
    // Costruisci il box
    sprintf(buffer, "|> %d <|", number);
}

void printErrorMessageTicketCheckout(const char* errorMessage) {
    // Prepara il messaggio di errore
    char* text = malloc(strlen(errorMessage) + 16);
    sprintf(text, "-> Errore! %s <-", errorMessage);

    // Stampa il messaggio di errore
    moveCursor(0, ERROR_ROW);
    printCenteredText(text);

    // Pulisci la memoria
    free(text);

    // Azzera il cursore
    moveCursor(0, 0);
}

void printPadding(char* buffer, int size) {
    // Metti gli spazi 
    for (int i = strlen(buffer); i < size - 1; i++) {
        buffer[i] = ' ';
    }

    // Termina la stringa
    buffer[size - 1] = '\0';
}

void updateBuySelection(int selection) {
    // Togli la selezione da tutte e tre le righe
    moveCursor(0, FULL_PRICE_TICKETS_NAME_ROW);
    printCenteredText("Biglietti interi");

    moveCursor(0, O65_TICKETS_NAME_ROW);
    printCenteredText("Biglietti over 65");

    moveCursor(0, U14_TICKETS_NAME_ROW);
    printCenteredText("Biglietti under 14");

    // In base alla selezione
    switch (selection) {
        // Selezione biglietti interi
        case 0: {
            moveCursor(0, FULL_PRICE_TICKETS_NAME_ROW);
            printCenteredText("-> Biglietti interi <-");
            break;
        }

        // Selezione biglietti over 65
        case 1: {
            moveCursor(0, O65_TICKETS_NAME_ROW);
            printCenteredText("-> Biglietti over 65 <-");
            break;
        }

        // Selezione biglietti under 14
        case 2: {
            moveCursor(0, U14_TICKETS_NAME_ROW);
            printCenteredText("-> Biglietti under 14 <-");
            break;
        }
    }

    // Resetta il cursore
    moveCursor(0, 0);
}

void printPricesRows(float ticketsTotalPrice, float ivaPercentage) {
    // Sposta il cursore alla riga dei titoli
    moveCursor(0, PRICES_TITLES_ROW);

    // Stampa i titoli
    printCenteredText("PREZZO               IVA       TOTALE            ");

    // Riga
    moveCursor(0, PRICES_TITLES_ROW + 1);
    printCenteredText("-------------------- --------- ------------------");

    // Sposta il cursore alla riga dei valori
    moveCursor(0, PRICES_VALUES_ROW);

    // Contenitori prezzi
    char priceBox[22];
    char ivaBox[11];
    char totalPriceBox[19];

    // Scrivi i prezzi
    sprintf(priceBox, "%.2f$", ticketsTotalPrice);
    sprintf(ivaBox, "%.1f%%", ivaPercentage);
    sprintf(totalPriceBox, "%.2f$", ticketsTotalPrice + (ticketsTotalPrice * ivaPercentage / 100));

    // Riempi gli spazi
    printPadding(priceBox, 22);
    printPadding(ivaBox, 11);
    printPadding(totalPriceBox, 19);

    // Stampa i prezzi
    char* text = malloc(64);
    sprintf(text, "%s%s%s", priceBox, ivaBox, totalPriceBox);
    printCenteredText(text);
    free(text);

    // Resetta il cursore
    moveCursor(0, 0);
}

void updateSelectedValue(int selected, int newValue) {
    char* box = malloc(128);
    buildNumericInputBox(box, newValue);
    
    // Sposta il cursore alla riga giusta
    moveCursor(0, selected == 0 ? FULL_PRICE_TICKETS_ROW : selected == 1 ? O65_TICKETS_ROW : U14_TICKETS_ROW);

    // Stampa il box
    printCenteredText(box);

    // Pulisci la memoria
    free(box);
}

void updateFormByValueUpdate(float price, int* selectedTickets, int editingParameter) {
    // Aggiorna i valori
    updateSelectedValue(editingParameter, selectedTickets[editingParameter]);

    // Scrivi i prezzi
    float totalPrice = calculateFullPrice(price) * selectedTickets[0] + calculateO65Price(price) * selectedTickets[1] + calculateU14Price(price) * selectedTickets[2];
    printPricesRows(totalPrice, IVA);
}

void printTicketsPurchaseMenu(char* eventName, float price, int* selectedTickets) {
    // Head
    printHead();
    printLine();

    // Dettagli biglietto selezionato
    printWhiteSpace();

    // Stampa il nome dell'evento
    char* eventNameText = malloc(256);
    sprintf(eventNameText, "-> Evento ~ %s <-", eventName);
    printCenteredText(eventNameText);
    free(eventNameText);

    // Info movimenti
    printCenteredText("-> Usa le freccette su e giu' per cambiare valore <-");

    // Spaziatura
    printWhiteSpace();

    // Biglietti full price
    printCenteredText("-> Biglietti interi <-");

    // Box biglietti full price scelti
    char* fullPriceTicketsBox = malloc(128);
    buildNumericInputBox(fullPriceTicketsBox, selectedTickets[0]);
    printCenteredText(fullPriceTicketsBox);
    free(fullPriceTicketsBox);

    // Spaziatura
    printWhiteSpace();

    // Biglietti over 65
    printCenteredText("Biglietti over 65");

    // Box biglietti over 65 scelti
    char* o65TicketsBox = malloc(128);
    buildNumericInputBox(o65TicketsBox, selectedTickets[1]);
    printCenteredText(o65TicketsBox);
    free(o65TicketsBox);

    // Spaziatura
    printWhiteSpace();

    // Biglietti under 14
    printCenteredText("Biglietti under 14");

    // Box biglietti under 14 scelti
    char* u14TicketsBox = malloc(128);
    buildNumericInputBox(u14TicketsBox, selectedTickets[2]);
    printCenteredText(u14TicketsBox);
    free(u14TicketsBox);

    // Spaziatura
    printWhiteSpace();

    // Pulsanti
    printCenteredText("< invio. Conferma acquisto >");
    printCenteredText("< esc. Annulla acquisto >");

    // Spaziatura
    printWhiteSpace();

    // Riga di separazione
    printLine();

    // Spaziatura
    printWhiteSpace();

    // Righe dei prezzi (rows 24, 25 e 26)
    float totalPrice = calculateFullPrice(price) * selectedTickets[0] + calculateO65Price(price) * selectedTickets[1] + calculateU14Price(price) * selectedTickets[2];
    printPricesRows(totalPrice, IVA);
    moveCursor(0, PRICES_VALUES_ROW + 1);

    // Spaziatura
    printWhiteSpace();

    // Riga di separazione
    printLine();

    // Resetta il cursore
    moveCursor(0, 0);
}

int launchTicketPurchaseMenu(Event selectedEvent, Account buyer) {
    // Variabili form
    int selectedTickets[3] = {1, 0, 0}; // Full, O65, U14
    int editingParameter = 0;

    // Pulisci lo schermo
    system("cls");

    // Stampa il menu
    printTicketsPurchaseMenu(selectedEvent.name, selectedEvent.price, selectedTickets);

    // Loop di input
    while (1) {
        // Leggi carattere da tastiera
        int c = _getch();

        // Se il carattere è esc, torna al menu principale
        if (c == KEY_ESCAPE) {
            system("cls");
            return MENU_GO_BACK;
        }

        // Se il carattere è invio, seleziona l'evento
        if (c == KEY_ENTER) {
            // Se non ci sono biglietti selezionati, errore
            if (selectedTickets[0] == 0 && selectedTickets[1] == 0 && selectedTickets[2] == 0) {
                // Stampa l'errore
                printErrorMessageTicketCheckout(ERROR_MESSAGE_NO_TICKET_SELECTED);

                // Continua
                continue;
            }

            // Lancia il menu di checkout
            int checkoutMenuExitStatus = launchCheckoutMenu(selectedEvent, buyer, selectedTickets[0], selectedTickets[1], selectedTickets[2]);

            // Casi di uscita
            if (checkoutMenuExitStatus == MENU_GO_BACK) { // Torna a questo menu
                // Pulisci lo schermo (per sicurezza)
                system("cls");

                // Stampa il menu
                printTicketsPurchaseMenu(selectedEvent.name, selectedEvent.price, selectedTickets);

                // Continua
                continue;
            }
            else if (checkoutMenuExitStatus == MENU_GOTO_MAIN_MENU) { // Torna al menu principale
                return MENU_GOTO_MAIN_MENU;
            }
            else if (checkoutMenuExitStatus == MENU_PROGRAM_EXIT) { // Esci dal programma
                return MENU_PROGRAM_EXIT;
            }
            else {
                // Errore interno
                return MENU_INTERNAL_ERROR;
            }

            // Continua
            continue;
        }

        // Verifica se è una freccia (su o giu)
        if (c == KEY_ARROWS) {
            // Legge il secondo carattere, che identifica la freccietta
            c = _getch();

            // Se è freccia su o giu, aggiorna il valore selezionato
            if (c == KEY_UP_ARROW || c == KEY_DOWN_ARROW) {
                // Modifica la selezione
                editingParameter = (c == KEY_UP_ARROW) ? editingParameter - 1 : editingParameter + 1;

                // Limiti selezione
                editingParameter = (editingParameter < 0) ? 2 : (editingParameter > 2) ? 0 : editingParameter;

                // Aggiorna la selezione
                updateBuySelection(editingParameter);

                // Continua
                continue;
            }

            // Se è una freccia destra o sinistra, aggiorna i valori
            if (c == KEY_LEFT_ARROW || c == KEY_RIGHT_ARROW) {
                // Gestisci l'update del valore
                if ((c == KEY_RIGHT_ARROW && selectedTickets[editingParameter] != 20) || (c == KEY_LEFT_ARROW && selectedTickets[editingParameter] != 0)) {
                    // Aumenta il valore
                    selectedTickets[editingParameter] += c == KEY_RIGHT_ARROW && selectedTickets[editingParameter] != 20 ? 1 : -1;

                    // Aggiorna i valori
                    updateFormByValueUpdate(selectedEvent.price, selectedTickets, editingParameter);
                }

                // Continua
                continue;
            }
        }
    }

    return MENU_GOTO_MAIN_MENU;
}

#pragma endregion