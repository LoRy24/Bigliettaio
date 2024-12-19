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

void buildInputBox(char* buffer, char* text) {
    // Costruisci il box
    sprintf(buffer, "|> %s <|", text);
}

void printErrorMessageLogin(const char* errorMessage) {
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

void printUsernamePrompt(char* username) {
    // Alloca la memoria
    char* usernameWithBox = malloc(38);
    usernameWithBox[0] = '\0';

    // Costruisci il box
    buildInputBox(usernameWithBox, username);

    // Stampalo a schermo
    moveCursor(0, 12);
    printCenteredText(usernameWithBox);

    // Libera la memoria
    free(usernameWithBox);

    // Azzera il cursore
    moveCursor(0, 0);
}

void printPasswordPrompt(char* password) {
    // Alloca la memoria
    char* passwordHidden = malloc(33);
    passwordHidden[0] = '\0';

    // Costruisci la password nascosta
    for (int i = 0; i < strlen(password); i++) {
        passwordHidden[i] = '*';
        passwordHidden[i + 1] = '\0';
    }

    // Allocare la memoria
    char* passwordWithBox = malloc(38);
    passwordWithBox[0] = '\0';

    // Costruisci il box
    buildInputBox(passwordWithBox, passwordHidden);

    // Stampalo a schermo
    moveCursor(0, 15);
    printCenteredText(passwordWithBox);

    // Libera la memoria
    free(passwordHidden);
    free(passwordWithBox);
}

void updatePrompt(int selected, char* content) {
    // Titolo campo username
    moveCursor(0, 11);
    printCenteredText(selected == 0 ? "-> Username:" : "Username:");

    // Titolo campo password
    moveCursor(0, 14);
    printCenteredText(selected == 1 ? "-> Password:" : "Password:");

    // Seleziona il campo
    if (selected == 0) {
        printUsernamePrompt(content);
    } else {
        printPasswordPrompt(content);
    }

    // Azzera il cursore
    moveCursor(0, 0);
}

void printLoginMenuForm(int selected) {
    // Head
    printHead();

    // Prima parte
    printLine();
    printWhiteSpace();
    printCenteredText("Effettua il login");

    // Stampa prompt attesa input
    printCenteredText("-> Attesa Input <-");

    // Pulsanti
    printWhiteSpace();
    printCenteredText(selected == 0 ? "-> Username:" : "Username:");

    // Stampa l'username con il box
    printUsernamePrompt("");
    moveCursor(0, 13);

    printWhiteSpace();
    printCenteredText(selected == 1 ? "-> Password:" : "Password:");

    // Stampa la password con degli asterischi
    printPasswordPrompt("");
    moveCursor(0, 16);

    printWhiteSpace();
    printCenteredText("< Usa le freccette su e giu' per cambiare valore >");
    printCenteredText("< Premi invio per effettuare il login >");

    printWhiteSpace();
    printCenteredText("< esc. Indietro >");
    printCenteredText("< ctrl + x. Esci >");
    printWhiteSpace();

    // Ultima Riga
    printLine();

    // Azzera il cursore
    moveCursor(0, 0);
}

//
// Stati:
// 0: Tutto ok continua dal menu principale
// 1: Esci dal programma
// 2: Torna al menu principale
//
int launchLoginMenu(Credentials* credentials) {
    // Definisci i campi
    char campi[2][33];

    // Pulisci i campi
    clearStringBuffer(campi[0], 33);
    clearStringBuffer(campi[1], 33);

    int cursors[2] = {0, 0};

    // Selezione di editing
    int selected = 0;

    // Stampa il form di login
    system("cls");
    printLoginMenuForm(selected);

    // Loop per il menu
    do {
        // Aggiorna il prompt
        updatePrompt(selected, campi[selected]);

        // Leggi carattere da tastiera
        int c = _getch();

        // Se il carattere è 224, allora è una freccia
        if (c == KEY_ARROWS) {
            // Legge il secondo carattere, che identifica la freccietta
            c = _getch();

            // Cambia lo stato
            selected = selected == 0 ? 1 : 0;
            continue;
        }

        // Se il carattere è una lettera o un numero fra 0 e 9
        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57)) {
            if (cursors[selected] < 32) {
                campi[selected][cursors[selected]++] = c;
            }
            continue;
        }

        // Se il carattere è CTRL_X, esci dal programma
        if (c == KEY_CTRL_X) {
            return 1;
        }

        // Se il carattere è esc, torna al menu principale
        if (c == KEY_ESCAPE) {
            return 2;
        }

        // Se il carattere è invio, esegui il login
        if (c == KEY_ENTER) {
            // Controlla che l'username non sia vuoto
            if (strlen(campi[0]) == 0) {
                printErrorMessageLogin(ERROR_MESSAGE_EMPTY_USERNAME);
                continue;
            }

            // Controlla che la password non sia vuota
            if (strlen(campi[1]) == 0) {
                printErrorMessageLogin(ERROR_MESSAGE_EMPTY_PASSWORD);
                continue;
            }

            // Per ora tutto ok
            break;
        }

        // Se il carattere è backspace, cancella l'ultimo carattere
        if (c == KEY_BACKSPACE) {
            if (cursors[selected] > 0) {
                campi[selected][--cursors[selected]] = '\0';
            }
            continue;
        }
    } while (1);

    // Copia i campi nella struttura delle credenziali
    sprintf(credentials->username, "%s", campi[0]);
    sprintf(credentials->password, "%s", campi[1]);

    // Torna al menu principale
    return 0;
}

#pragma endregion
