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
// Valori globali
//

#pragma region Globali

#pragma endregion

//
// Selezione Card
//

#pragma region Selezione Card

void writeArrowsShape(int cardIndex, char c1, char c2) {
    // Calcola l'offset
    int offset = 10 + (12 + 1) * cardIndex;

    // Calcola l'offset laterale
    int offsetLeft = (((FORM_WIDTH - 4) - 62) / 2) + 4;

    for (int i = 0; i < 2; i++, offset++) {
        moveCursor(offsetLeft + 0, offset);
        printf("%c", c1);
        moveCursor(offsetLeft + 60, offset);
        printf("%c", c1);
    }

    for (int i = 0; i < 3; i++, offset++) {
        moveCursor(offsetLeft + 1, offset);
        printf("%c", c2);
        moveCursor(offsetLeft + 59, offset);
        printf("%c", c2);
    }

    for (int i = 0; i < 2; i++, offset++) {
        moveCursor(offsetLeft + 2, offset);
        printf("%c", c1);
        moveCursor(offsetLeft + 58, offset);
        printf("%c", c1);
    }

    for (int i = 0; i < 3; i++, offset++) {
        moveCursor(offsetLeft + 1, offset);
        printf("%c", c2);
        moveCursor(offsetLeft + 59, offset);
        printf("%c", c2);
    }

    for (int i = 0; i < 2; i++, offset++) {
        moveCursor(offsetLeft + 0, offset);
        printf("%c", c1);
        moveCursor(offsetLeft + 60, offset);
        printf("%c", c1);
    }
}

void writeSelectionArrows(int cardIndex) {
    writeArrowsShape(cardIndex, '#', '|');
}

#pragma endregion

//
// Scrittura Card
//

#pragma region Scrittura Card

/*

#   +---------------------------------------------------+   #
#   |                                                   |   #
 |  |                   Evento: Nome                    |  |
 |  |         -> Location - DD/MM/YYYY ~ HH:MM          |  |
 |  |             Posti Disponibili: X su Y             |  |
  # |                                                   | #
  # |                      Prezzi                       | #
 |  |      ---------------------------------------      |  |
 |  |        INTERO      U14         O65                |  |
 |  |        0000000.00€ 0000000.00€ 0000000.00€        |  |
#   |                                                   |   #
#   +---------------------------------------------------+   #

*/

char* formatMoney(float amount) {
    // Alloca la memoria
    char* text = malloc(11);

    // Formatta il testo
    sprintf(text, "%.2f$", amount);

    // Riempi con degli spazi
    for (int i = strlen(text); i < 10; i++) {
        text[i] = ' ';
    }

    // Termina la stringa
    text[10] = '\0';

    // Ritorna il testo
    return text;
}

void printCardStraightLine() {
    printCenteredText("    +---------------------------------------------------+    ");
}

void printCardEmptyLine() {
    printCenteredText("    |                                                   |    ");
}

void printCardCenteredText(const char* text) {
    char* formattedText = malloc(62);
    sprintf(formattedText, "    |                                                   |    ");

    // Calcola l'alfa
    int alpha = (61 - strlen(text)) / 2;

    // Scrivi il testo
    for (int i = 0; i < strlen(text); i++) {
        formattedText[alpha + i] = text[i];
    }

    // Stampa il testo
    printCenteredText(formattedText);
}

void printCardPrices(float basePrice) {
    // Scrivi l'intestazione
    printCenteredText("    |                      Prezzi                       |    ");
    printCenteredText("    |      ---------------------------------------      |    ");
    printCenteredText("    |        INTERO      O65          U14               |    ");

    // Formatta i soldi
    char* fullPrice = formatMoney(calculateFullPrice(basePrice));
    char* over65Price = formatMoney(calculateO65Price(basePrice));
    char* under14Price = formatMoney(calculateU14Price(basePrice));

    // Stampa i soldi
    char* priceString = malloc(62);
    sprintf(priceString, "    |        %s  %s   %s        |    ", fullPrice, over65Price, under14Price);
    printCenteredText(priceString);
}

void printTicketCard(Event event, int row) {
    // Stampa il biglietto
    moveCursor(0, row);

    // Inizio card
    printCardStraightLine();
    printCardEmptyLine();

    // Scrivi nome evento
    char* eventName = malloc(65);
    sprintf(eventName, "Evento: %s", event.name);
    printCardCenteredText(eventName);

    // Altri dettagli
    char* eventDetails = malloc(65);
    sprintf(eventDetails, "-> %s - %s ~ %s", event.location, event.date, event.time);
    printCardCenteredText(eventDetails);

    // Posti disponibili
    char* seats = malloc(65);
    sprintf(seats, "Posti disponibili: %d su %d", event.freeSeats, event.totalSeats);
    printCardCenteredText(seats);

    // Prezzi
    printCardEmptyLine();
    printCardPrices(event.price);

    // Fine card
    printCardEmptyLine();
    printCardStraightLine();
    
    // Separa la card
    printWhiteSpace();
}

#pragma endregion

//
// Tickets Form
//

#pragma region Form

void displayEventCard(Event event, int selected, int eventsCount, int updateCursor) {
    // Stampa l'evento
    printTicketCard(event, 10);
    writeSelectionArrows(0);

    if (updateCursor) {
        // Cambia la riga del cursore
        moveCursor(0, 23);

        // Scrivi la riga della selezione
        char* text = malloc(128);
        sprintf(text, "-> %d/%d Eventi Visualizzati <-", selected + 1, eventsCount);
        printCenteredText(text);
    }

    // Azzera il cursore
    moveCursor(0, 0);
}

void printTicketsMenuForm(Event displayEvent, int eventsCount, int selected) {
    // Head
    printHead();
    printLine();

    // Intestazione
    printWhiteSpace();
    printCenteredText("-> Evento (usa le freccette d. e s. per navigare) <-");
    printWhiteSpace();

    // Mostra l'evento
    displayEventCard(displayEvent, selected, eventsCount, 0);
    
    // Azzera il cursore
    moveCursor(0, 22);

    // Evento mostrato
    printWhiteSpace();

    // Alloca la memoria
    char* text = malloc(128);
    sprintf(text, "-> %d/%d Eventi Visualizzati <-", selected + 1, eventsCount);
    printCenteredText(text);

    // Pulsanti
    printWhiteSpace();
    printCenteredText("< invio. Seleziona >");
    printCenteredText("< esc. Indietro >");
    printCenteredText("< ctrl + x. Esci >");

    // Fine menu
    printWhiteSpace();
    printLine();

    // Azzera cursore
    moveCursor(0, 0);
}

int launchTicketsMenu(Account buyer) {
    // Valori funzionali
    int selectedTicket = 0;

    // Stampa il form
    system("cls");

    // Eventi
    int tickets;
    Event* events = loadEvents(&tickets);

    // Se i tickets caricati sono 0, esci
    if (tickets == 0) {
        return MENU_NO_TICKETS_FOUND_ERROR;
    }

    // Mostra il form
    printTicketsMenuForm(events[selectedTicket], tickets, selectedTicket);

    // Loop operazioni
    while (1) {
        // Leggi carattere da tastiera
        int c = _getch();

        // Verifica se è una freccia (destra o sinistra)
        if (c == KEY_ARROWS) {
            // Legge il secondo carattere, che identifica la freccietta
            c = _getch();

            // Se non è nessuna delle due freccie, continua
            if (c != KEY_LEFT_ARROW && c != KEY_RIGHT_ARROW) {
                continue;
            }

            // Se è freccia destra ma ci si trova alla fine o freccia sinistra ma ci si trova all'inizio, continua
            if ((c == KEY_RIGHT_ARROW && selectedTicket == tickets - 1) || (c == KEY_LEFT_ARROW && selectedTicket == 0)) {
                continue;
            }

            // Modifica la selezione
            selectedTicket += (c == KEY_RIGHT_ARROW) ? 1 : -1;

            // Mostra il biglietto
            displayEventCard(events[selectedTicket], selectedTicket, tickets, 1);

            // Continua
            continue;
        }

        // Se equivale a CTRL + X, esci
        if (c == KEY_CTRL_X) {
            system("cls");
            return MENU_PROGRAM_EXIT;
        }

        // Se il carattere è esc, torna al menu principale
        if (c == KEY_ESCAPE) {
            system("cls");
            return MENU_GO_BACK;
        }

        // Se il carattere è invio, seleziona l'evento
        if (c == KEY_ENTER) {
            // Lancia il menu di acquisto
            int purchaseMenuExitStatus = launchTicketPurchaseMenu(events[selectedTicket], buyer);

            // Casi di uscita
            if (purchaseMenuExitStatus == MENU_GO_BACK) { // Torna a questo menu
                // Pulisci lo schermo (per sicurezza)
                system("cls");

                // Mostra il form
                printTicketsMenuForm(events[selectedTicket], tickets, selectedTicket);

                // Continua
                continue;
            }
            else if (purchaseMenuExitStatus == MENU_GOTO_MAIN_MENU) { // Torna a menu principale post acquisto
                system("cls");
                return MENU_GO_BACK; // Menu principale
            }
            else if (purchaseMenuExitStatus == MENU_PROGRAM_EXIT) { // Uscita dal programma
                system("cls");
                return MENU_PROGRAM_EXIT; // Uscita
            }
            else {
                // Errore interno
                system("cls");
                return MENU_INTERNAL_ERROR;
            }
        }
    }

    // Torna endre
    return MENU_GO_BACK;
}

#pragma endregion
