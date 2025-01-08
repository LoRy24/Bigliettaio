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

void printErrorMessageCheckout(char* message) {
    // Prepara il messaggio di errore
    char* text = malloc(strlen(message) + 16);
    sprintf(text, "-> Errore! %s <-", message);

    // Sposta il cursore
    moveCursor(0, 12);

    // Stampa il messaggio
    printCenteredText(text);

    // Resetta il cursore
    moveCursor(0, 0);
}

//
//                 Dettagli Carta
// ----------------------- ----------- ---------
// Numero Carta            Scadenza    CVV      
// ____ ____ ____ ____     __/____     ___      
//
// Nome sulla carta
// _____________________________________________
//

// Dettagli in details:
// numerocarta scadenza cvv nome sulla carta
// ES:
// NUMERO----------SCAD--CVVNome-----------------
// 0000111122223333122025123Lorenzo Rocca
// Massimo 70 caratteri
void printDebitCardDetails(char* details) {
    // Sposta il cursore
    moveCursor(0, 17);

    // Intestazione
    printCenteredText("Dettagli Carta");
    printCenteredText("----------------------- ----------- ---------");
    printCenteredText("Numero Carta            Scadenza    CVV      ");

    // Parsa la stringa dei dettagli (dimensione 1 + 46 + 3 + 6 + 16)
    char* detailsRow = malloc(71);
    sprintf(detailsRow, "%s", details);
    
    // Riempi con trattini bassi
    for (int i = strlen(detailsRow); i < 70; i++) {
        detailsRow[i] = '_';
    }

    // Termina la stringa
    detailsRow[70] = '\0';

    // Stampa la prima riga dei dettagli
    char* firstRow = malloc(46);
    for (int i = 0, j = 0; i < 45; ++i) {
        if ((i >= 0 && i < 4) || (i >= 5 && i < 9) || (i >= 10 && i < 14) || (i >= 15 && i < 19) || (i >= 24 && i < 26) || (i >= 27 && i < 31) || (i >= 36 && i < 39)) {
            firstRow[i] = detailsRow[j];
            j++;
        } else if (i == 4 || i == 9 || i == 14 || (i >= 19 && i < 24) || (i >= 31 && i < 36) || i >= 39) {
            firstRow[i] = ' ';
        } else {
            firstRow[i] = '/';
        }
    } 
    // j = 25 /> NOME

    // Termina la stringa
    firstRow[45] = '\0';

    // Stampa la prima riga
    printCenteredText(firstRow);

    // Pulisci la memoria della prima riga
    free(firstRow);

    // Spaziatura
    printWhiteSpace();

    // Intestazione seconda riga
    printCenteredText("Nome sulla carta");

    // Prepara la riga del nome
    char* nameRow = malloc(46);

    // Riempi la riga del nome
    for (int i = 0, j = 25; i < 45; ++i) {
        nameRow[i] = detailsRow[j];
        j++;
    }

    // Termina la stringa
    nameRow[45] = '\0';

    // Stampa la riga del nome
    printCenteredText(nameRow);

    // Pulisci la memoria
    free(nameRow);
    free(detailsRow);

    // Resetta il cursore
    moveCursor(0, 0);
}

void printCheckoutMenu(char* eventName, float totalPrice) {
    // Head
    printHead();
    printLine();

    // Spaziatura
    printWhiteSpace();

    // Menu pagamento
    printCenteredText("Checkout");

    // Stampa il nome dell'evento
    char* eventNameText = malloc(256);
    sprintf(eventNameText, "Evento ~ %s", eventName);
    printCenteredText(eventNameText);
    free(eventNameText);

    // Spaziatura
    printWhiteSpace();

    // Info
    printCenteredText("! Per ora sono supportati solo pagamenti via carte. !");
    printCenteredText("-> Inserisci i dati della carta consecutivamente <-"); // Riga 12

    // Spaziatura
    printWhiteSpace();

    // Stampa il prezzo totale
    printCenteredText("@ Prezzo Totale @");
    char* priceText = malloc(128);
    sprintf(priceText, "-> %.2f$ <-", totalPrice);
    printCenteredText(priceText);
    free(priceText);

    // Spaziatura
    printWhiteSpace();

    // Riga 17 fino alla riga 23
    printDebitCardDetails("");
    moveCursor(0, 24);

    // Spaziatura
    printWhiteSpace();

    // Pulsanti
    printCenteredText("< invio. Coferma pagamento >");
    printCenteredText("< esc. Annulla pagamento >");

    // Spaziatura
    printWhiteSpace();

    // Linea
    printLine();
}

void printCheckoutSuccessMenu(int orderId, char* eventName, int tickets, float paidAmount) {
    // Head
    printHead();
    printLine();

    // Spaziatura
    printWhiteSpace();

    // Menu pagamento
    printCenteredText("Ben fatto!");

    // Scrivi l'ID dell'ordine
    char* orderIdText = malloc(256);
    sprintf(orderIdText, "ID Ordine: %d", orderId);
    printCenteredText(orderIdText);
    free(orderIdText);

    // Spaziatura
    printWhiteSpace();

    // Spaziatura
    printWhiteSpace();

    // Notifica
    printCenteredText("-> Pagamento Effettuato <-");

    // Info
    printCenteredText("Il pagamento e' stato effettuato con successo!");

    // Spaziatura
    printWhiteSpace();
    printWhiteSpace();

    // Pulsanti
    printCenteredText("< invio. Torna al menu principale >");

    // Spaziatura
    printWhiteSpace();

    // Linea
    printLine();

    // Spaziatura
    printWhiteSpace();

    // Scrivi i dati dell'acquisto
    char* text = malloc(256);
    sprintf(text, "Hai acquistato %d biglietti per l'evento '%s'.", tickets, eventName);
    printCenteredText(text);
    free(text);

    // Scrivi il prezzo pagato
    char* priceText = malloc(128);
    sprintf(priceText, "Hai pagato %.2f$.", paidAmount);
    printCenteredText(priceText);
    free(priceText);

    // Spaziatura
    printWhiteSpace();

    // Linea
    printLine();

    // Resetta il cursore
    moveCursor(0, 0);
}

int launchCheckoutMenu(Event event, Account buyer, int sFullPrice, int sO65, int sU14) {
    // Valori
    char* debitCardDetails = malloc(71);
    int cursor = 0;

    // Inizializza la stringa
    clearStringBuffer(debitCardDetails, 71);

    // Pulisci lo schermo
    system("cls");

    // Prezzo evento
    float eventPrice = event.price;
    float totalPrice = calculateFullPrice(eventPrice) * sFullPrice + calculateO65Price(eventPrice) * sO65 + calculateU14Price(eventPrice) * sU14;
    float taxes = totalPrice * IVA / 100;

    // Aggiungi iva al prezzo
    totalPrice += taxes;

    // Calcola le tre provvigioni
    float profitFullPrice = calculateFullPrice(eventPrice) * sFullPrice - eventPrice * sFullPrice;
    float profitO65 = calculateO65Price(eventPrice) * sO65 - eventPrice * sO65;
    float profitU14 = calculateU14Price(eventPrice) * sU14 - eventPrice * sU14;

    // Stampa il menu
    printCheckoutMenu(event.name, totalPrice);

    // Leggi
    while (1) {
        // Leggi carattere da tastiera
        int c = _getch();

        // Se il carattere è una freccetta, leggi il secondo e continua
        if (c == KEY_ARROWS) {
            // Leggi e continua
            c = _getch();
            continue;
        }

        // Se uguale a esc, torna al menu precedente
        if (c == KEY_ESCAPE) {
            // Turna endre
            system("cls");
            return MENU_GO_BACK;
        }

        // Per ora, se preme invio torna al menu principale
        if (c == KEY_ENTER) {
            // Se la dimensione della stringa dei dettagli è minore di 26, non è completa
            if (strlen(debitCardDetails) < 26) {
                // Stampa errore
                printErrorMessageCheckout(ERROR_CARD_DETAILS_TOO_SHORT);

                // Continua
                continue;
            }

            // Controllo validità data
            char* date = malloc(7);
            for (int i = 0; i < 6; i++) {
                date[i] = debitCardDetails[i + 16];
            }
            date[6] = '\0';

            // Controllo
            int dateValid = isDateValid(date);

            // Mese non valido
            if (dateValid == -1) {
                // Stampa errore
                printErrorMessageCheckout(ERROR_CARD_DETAILS_INVALID_DATE);

                // Continua
                continue;
            }
            else if (dateValid == -2) {
                // Stampa errore
                printErrorMessageCheckout(ERROR_CARD_EXPIRED);

                // Continua
                continue;
            }

            // TODO controllo esistenza carta

            // Notifica del pagamento avvenuto
            system("cls");

            // Annota i soldi
            addSoldTickets(sFullPrice + sO65 + sU14, totalPrice, profitFullPrice + profitO65 + profitU14, taxes);

            // TODO processa l'ordine

            // Stampa il menu
            srand(time(NULL));
            printCheckoutSuccessMenu(rand(), event.name, sFullPrice + sO65 + sU14, totalPrice);

            // Attendi per un invio
            int exitChar = -1;
            while (exitChar != KEY_ENTER) {
                exitChar = _getch();
            }

            // Torna al menu principale
            return MENU_GOTO_MAIN_MENU;
        }

        // Se preme backspace, cancella l'ultimo carattere
        if (cursor > 0 && c == KEY_BACKSPACE) {
            // Cancella l'ultimo carattere
            debitCardDetails[--cursor] = '\0';

            // Stampa i dettagli
            printDebitCardDetails(debitCardDetails);

            // Continua
            continue;
        }

        // Parametri numerici (dati carta)
        if (cursor >= 0 && cursor < 25) {
            // Se la key non è un numero fra 0 e 9, ignora
            if (c < 48 || c > 57) {
                continue;
            }

            // Aggiungi il carattere alla stringa
            debitCardDetails[cursor] = (char) c;
            debitCardDetails[cursor + 1] = '\0';
            cursor++;

            // Stampa i dettagli
            printDebitCardDetails(debitCardDetails);

            // Continua
            continue;
        }

        // Parametri testuali (nome)
        if (cursor >= 25 && cursor < 70) {
            // Verifica che sia un carattere di testo
            if ((c < 65 || c > 90) && (c < 97 || c > 122) && c != 32) {
                continue;
            }

            // Aggiungi il carattere alla stringa
            debitCardDetails[cursor] = (char) c;
            debitCardDetails[cursor + 1] = '\0';
            cursor++;

            // Stampa i dettagli
            printDebitCardDetails(debitCardDetails);

            // Continua
            continue;
        }
    }

    return MENU_GO_BACK;
}

#pragma endregion