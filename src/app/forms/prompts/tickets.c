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

void displayEventCard(Event event) {
    // Stampa l'evento
    printTicketCard(event, 10);
    writeSelectionArrows(0);
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
    displayEventCard(displayEvent);
    
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
}

int launchTicketsMenu() {
    // Stampa il form
    system("cls");

    Event event;
    strcpy(event.name, "Gli scrocconi");
    strcpy(event.location, "Magi");
    strcpy(event.date, "25/02/2025");
    strcpy(event.time, "20:30");
    event.totalSeats = 100;
    event.freeSeats = 32;
    event.price = 69.69;

    printTicketsMenuForm(event, 1, 0);

    while (1) {
        
    }

    return 2;
}

#pragma endregion
