//
// Autore: Lorenzo Rocca
//

//
// Inclusioni
//

#pragma region Inclusioni

#include "forms.h"

#pragma endregion

#pragma region Buffers

#pragma endregion

//
// Login Form
//

#pragma region Form

void buildInputBox(char* buffer, char* text) {
    // Costruisci il box
    sprintf(buffer, "|> %s <|", text);
}

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

    // Stampa l'username con il box
    char usernameWithBox[38];
    usernameWithBox[0] = '\0';

    buildInputBox(usernameWithBox, username);
    printCenteredText(usernameWithBox);

    // Fine stampa username

    printWhiteSpace();
    printCenteredText(selected == 1 ? "-> Password:" : "Password:");

    // Stampa la password con degli asterischi

    char passwordHidden[32];
    passwordHidden[0] = '\0';

    for (int i = 0; i < strlen(password); i++) {
        passwordHidden[i] = '*';
        passwordHidden[i + 1] = '\0';
    }

    char passwordWithBox[38];
    passwordWithBox[0] = '\0';

    buildInputBox(passwordWithBox, passwordHidden);
    printCenteredText(passwordWithBox);

    // Fine stampa password

    printWhiteSpace();
    printCenteredText("< Usa le freccette su e giu' per cambiare valore >");
    printCenteredText("< Premi invio per effettuare il login >");

    printWhiteSpace();
    printCenteredText("< esc. Indietro >");
    printCenteredText("< ctrl + x. Esci >");
    printWhiteSpace();

    // Ultima Riga
    printLine();
}

//
// Stati:
// 0: Tutto ok continua dal menu principale
// 1: Esci dal programma
// 2: Torna al menu principale
//
int launchLoginMenu(Credentials* credentials) {
    // Definisci i campi
    char campi[2][32];

    // Pulisci i campi
    clearStringBuffer(campi[0], 32);
    clearStringBuffer(campi[1], 32);

    int cursors[2] = {0, 0};

    // Selezione di editing
    int selected = 0;

    // Errore
    int error = 0;
    char* errorMessage = NULL;

    // Loop per il menu
    do {
        // Pulisci lo schermo
        system("cls");
        fflush(stdout);

        // Stampa il form di login
        printLoginMenuForm(campi[0], campi[1], selected, error, errorMessage);

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
            if (cursors[selected] < 31) {
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
            // Per oraesce per ridare il controllo al menu principale
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
    strcpy(credentials->username, campi[0]);
    strcpy(credentials->password, campi[1]);

    // Torna al menu principale
    return 0;
}

#pragma endregion
