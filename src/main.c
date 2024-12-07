//
// Autore: Lorenzo Rocca
//

#pragma region Inclusioni

// Librerie Progetto
#include "globals.h"
#include "forms.h"

#pragma endregion

#pragma region Definizioni

// Spinner caricamento 
char SPINNER_STATES[8] = {'|', '/', '-', '\\', '|', '/', '-', '\\'};

#pragma endregion

#pragma region Strutture

/**
 * Struttura per gestire un biglietto
 */
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
 * Questa funzione permette di attendere un numero definito di millisecondi. Utilizza
 * nanosleep
 * 
 * @param msec Il numero di millisecondi da attendere
 */
int msleep(long msec);

/**
 * Stampa un messaggio di benvenuto contenente la versione del programma. Il messaggio è 
 * racchiuso in una cornice composta da '#'.
 */
void printWelcomeMessage();

void launchLoginMenu();

#pragma endregion

#pragma region Routine principale

int main() {
    // Pulisci lo schermo per sicurezza
    system("cls");

    // Stampa il messaggio di benvenuto
    printWelcomeMessage();

    // Spazio bianco
    printf("\n");

    // Piccolo caricamento
    for (int i = 0; i < 20; ++i) {
        printf("\rCaricamento in corso %c", SPINNER_STATES[i % 8]);
        msleep(125);
    }

    // Scrivi che il caricamento è stato completato
    printf("\rCaricamento completato!");

    // Attendi 1s
    sleep(1);

    // Pulisci lo schermo
    system("cls");

    launchLoginMenu();

    return 0;
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

void printMainMenuForm() {

}

#pragma endregion

#pragma region Forms

void launchLoginMenu() {
    while(1) {
        char c = _getch();
        if (c == 'c') {
            break;
        }
    }
}

#pragma endregion

#pragma region Utils

int msleep(long msec) {
    // Definisco alcune variabili locali
    struct timespec ts;
    int res;

    // Solo numeri di millisecondi positivi
    if (msec < 0) {
        errno = EINVAL;
        return -1;
    }

    // Ricavo il tempo di attesa
    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    // Tento l'esecuzione finchè non viene svolta
    do {
        res = nanosleep(&ts, NULL);
    } while (res && errno == EINTR);

    // Ritorno lo stato di uscita
    return res;
}

#pragma endregion
