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
// Login Form
//

#pragma region Form

void printLoginMenuForm(char* username, char* password, int selected, int error, const char* errorMessage) {
    // Head
    printHead();

    // Prima parte
    printLine();
    printWhiteSpace();
    printCenteredText("Effettua il login");

    // Errore ove presente
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
    printCenteredText(selected == 0 ? "-> Username:" : "Username:");
    printCenteredText(username);

    printWhiteSpace();
    printCenteredText(selected == 1 ? "-> Password:" : "Password:");
    printCenteredText(password);

    printWhiteSpace();
    printCenteredText("< Usa le freccette su e giu' per cambiare valore >");
    printCenteredText("< Premi invio per effettuare il login >");

    printWhiteSpace();
    printCenteredText("< esc. Indietro >");
    printCenteredText("< q. Esci >");
    printWhiteSpace();

    // Ultima Riga
    printLine();
}

// Stati:
// 0: Tutto ok continua dal menu principale
// 1: Esci dal programma
// 2: Torna al menu principale
int launchLoginMenu() {
    // Definisci i campi
    char campi[2][32] = {"\0", "\0"};

    // Definisco il cursore username
    int usernameCursor = 0;

    // Definisco il cursore password
    int passwordCursor = 0;

    // Selezione di editing
    int selected = 0;

    // Errore
    int error = 0;
    char* errorMessage = NULL;

    do {
        // Pulisci lo schermo
        system("cls");
        fflush(stdout);

        // Stampa il form di login
        printLoginMenuForm(campi[0], campi[1], selected, error, errorMessage);

        // Leggi carattere da tastiera
        char c = _getch();

        // Se il carattere è la q, esci dal programma
        if (c == 'q') {
            return 1;
        }

        // Se il carattere è esc, torna al menu principale
        if (c == KEY_ESCAPE) {
            return 2;
        }

        // Se il carattere è invio, esegui il login
        if (c == KEY_ENTER) {
            // Per ora da sempre un errore
            error = 1;
            errorMessage = "Login non disponibile!";
            continue;
        }

        // Se il carattere è un tasto freccia, cambia lo stato di selected
        if (c == KEY_UP_ARROW || c == KEY_DOWN_ARROW) {
            selected = selected == 0 ? 1 : 0;
            continue;
        }
    } while (1);
}

#pragma endregion
