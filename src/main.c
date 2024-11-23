//
// Autore: Lorenzo Rocca
//

#pragma region Inclusioni

// Librerie standard
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#pragma endregion

#pragma region Definizioni

// Versione del programma
#define VERSION                             "1.0.0/DEV"

// Impostazioni dei form
#define FORM_WIDTH                          50

#pragma endregion

#pragma region Strutture

typedef struct {
    uint64_t ticketId;
    uint32_t eventId;
    uint32_t seat;
    uint16_t price;
    char name[50];
    char surname[50];
    char email[50];
    char phone[20];
} Ticket;

#pragma endregion

#pragma region Prototipi

/**
 * Stampa una linea composta da '#' ai lati e '-' al centro. La lunghezza della linea è 
 * definita dalla costante FORM_WIDTH.
 */
void printLine();

/**
 * Stampa un testo centrato all'interno di una cornice composta da '#'. Il testo è centrato
 * rispetto alla larghezza definita dalla costante FORM_WIDTH. Se il testo è più lungo della
 * larghezza, verrà troncato.
 * 
 * @param text Il testo da centrare.
 */
void printCenteredText(const char* text);

/**
 * Stampa una riga composta da '#' ai lati e ' ' al centro. La lunghezza della riga è definita
 * dalla costante FORM_WIDTH.
 */
void printWhiteSpace();

/**
 * Stampa un messaggio di benvenuto contenente la versione del programma. Il messaggio è 
 * racchiuso in una cornice composta da '#'.
 */
void printWelcomeMessage();

/**
 * Stampa un testo allineato a sinistra all'interno di una cornice composta da '#'.
 */
void printLeftAlignedText(const char* text);

#pragma endregion

#pragma region Routine principale

int main() {
    // Pulisci lo schermo per sicurezza
    system("cls");

    // Stampa il messaggio di benvenuto
    printWelcomeMessage();
    return 0;
}

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

#pragma endregion

#pragma region Definizioni funzioni generali

void printWelcomeMessage() {
    // Stampa il messaggio di benvenuto
    printLine();
    printWhiteSpace();
    printCenteredText("Benvenuto in Bigliettaio V1!");
    printCenteredText("Versione: " VERSION);
    printWhiteSpace();
    printWhiteSpace();
    printCenteredText("Made by Lorenzo Rocca");
    printWhiteSpace();
    printLine();
}

#pragma endregion
