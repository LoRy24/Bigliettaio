//
// Autore: Lorenzo Rocca
//

#pragma region Inclusioni

// Librerie progetto
#include "forms.h"

#pragma endregion

#pragma region Definizioni funzioni form

void printLine() {
    // Calcola alfa
    int alfa = FORM_WIDTH - 4;

    // Stampa i primi due caratteri
    printf("# ");

    // Stampa i caratteri centrali
    for (int i = 0; i < alfa; i++) {
        printf("-");
    }

    // Stampa i caratteri finali
    printf(" #\n");
}

void printWhiteSpace() {
    // Calcola alfa
    int alfa = FORM_WIDTH - 4;

    // Stampa i primi due caratteri
    printf("# ");

    // Stampa i caratteri centrali
    for (int i = 0; i < alfa; i++) {
        printf(" ");
    }

    // Stampa i caratteri finali
    printf(" #\n");
}

void printCenteredText(const char* text) {
    // Calcola alfa
    int alfa = FORM_WIDTH - 4;

    // Scrivi i primi due caratteri
    printf("# ");

    // Se il testo è più lungo di alfa, stampa solo i primi alfa caratteri
    if (strlen(text) > alfa) {
        for (int i = 0; i < alfa; i++) {
            printf("%c", text[i]);
        }
    } else {
        // Calcola il numero di spazi bianchi da inserire prima del testo
        int spaces = (alfa - strlen(text)) / 2;

        // Stampa gli spazi bianchi
        for (int i = 0; i < spaces; i++) {
            printf(" ");
        }

        // Stampa il testo
        printf("%s", text);

        // Stampa gli spazi bianchi rimanenti
        for (int i = 0; i < spaces; i++) {
            printf(" ");
        }

        // Se la lunghezza del testo ha il % 2 diverso da quello di alfa, stampa uno spazio bianco
        if (strlen(text) % 2 != alfa % 2) {
            printf(" ");
        }
    }

    // Stampa i caratteri finali
    printf(" #\n");
}

void printLeftAlignedText(const char* text) {
    // Calcola alfa
    int alfa = FORM_WIDTH - 4;

    // Scrivi i primi due caratteri
    printf("# ");

    // Se il testo è più lungo di alfa, stampa solo i primi alfa caratteri
    if (strlen(text) > alfa) {
        for (int i = 0; i < alfa; i++) {
            printf("%c", text[i]);
        }
    } else {
        // Stampa il testo
        printf("%s", text);

        // Calcola il numero di spazi bianchi da inserire dopo il testo
        int spaces = alfa - strlen(text);

        // Stampa gli spazi bianchi rimanenti
        for (int i = 0; i < spaces; i++) {
            printf(" ");
        }
    }

    // Stampa i caratteri finali
    printf(" #\n");
}

void printRightAlignedText(const char* text) {
    // Calcola alfa
    int alfa = FORM_WIDTH - 4;

    // Scrivi i primi due caratteri
    printf("# ");

    // Se il testo è più lungo di alfa, stampa solo i primi alfa caratteri
    if (strlen(text) > alfa) {
        for (int i = 0; i < alfa; i++) {
            printf("%c", text[i]);
        }
    } else {
        // Calcola il numero di spazi bianchi da inserire prima
        int spaces = alfa - strlen(text);

        // Stampa gli spazi bianchi
        for (int i = 0; i < spaces; i++) {
            printf(" ");
        }

        // Stampa il testo
        printf("%s", text);
    }

    // Stampa i caratteri finali
    printf(" #\n");
}

#pragma endregion
