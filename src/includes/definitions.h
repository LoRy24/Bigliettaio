//
// Autore: Lorenzo Rocca
//

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//
// Definizioni
//

#pragma region Definizioni

// Versione del programma
#define VERSION                             "1.0.0/DEV"

// Impostazioni dei form
#define FORM_WIDTH                          90

// Tasti
#define KEY_ENTER                           13
#define KEY_BACKSPACE                       8
#define KEY_ESCAPE                          27
#define KEY_UP_ARROW                        72
#define KEY_DOWN_ARROW                      80
#define KEY_CTRL_X                          24
#define KEY_ARROWS                          224

#pragma endregion

//
// Strutture
//

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

/**
 * Struttura per l'account utente
 */
typedef struct {
    char name[128];
    char surname[128];
    int age;
    int admin;
} Account;

#pragma endregion

#endif
