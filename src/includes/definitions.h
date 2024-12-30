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

// Testi vari
#define APP_NAME                            "Bigliettaio V1"
#define APP_NAME_SHORT                      "Bigliettaio"
#define ADMIN_PREFIX                        "[ADMIN] "

// Messaggi di errore
#define ERROR_MESSAGE_INVALID_COMMAND       "Comando non valido!"
#define ERROR_MESSAGE_INTERNAL_ERROR        "Errore interno!"
#define ERROR_MESSAGE_NOT_LOGGED            "Non hai eseguito l'accesso!"
#define ERROR_MESSAGE_ALREADY_LOGGED        "Sei già autenticato!"
#define ERROR_MESSAGE_NOT_ADMIN             "Non sei un amministratore!"
#define ERROR_MESSAGE_NOT_FOUND             "Elemento non trovato!"
#define ERROR_MESSAGE_NOT_IMPLEMENTED       "Funzionalità non implementata!"
#define ERROR_MESSAGE_INVALID_CREDENTIALS   "Credenziali non valide!"
#define ERROR_MESSAGE_EMPTY_PASSWORD        "La password non può essere vuota!"
#define ERROR_MESSAGE_EMPTY_USERNAME        "L'username non può essere vuoto!"

// Tasti
#define KEY_ENTER                           13
#define KEY_BACKSPACE                       8
#define KEY_ESCAPE                          27
#define KEY_UP_ARROW                        72
#define KEY_DOWN_ARROW                      80
#define KEY_LEFT_ARROW                      75
#define KEY_RIGHT_ARROW                     77
#define KEY_CTRL_X                          24
#define KEY_ARROWS                          224

// Files
#define DATA_FOLDER                         "data"

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
} Ticket;

/**
 * Struttura per gestire un evento
 */
typedef struct {
    uint32_t eventId;
    char name[33]; // Max 32 caratteri
    char location[33]; // Max 32 caratteri
    char date[11]; // Formato: DD/MM/YYYY
    char time[6]; // Formato: HH:MM
    float price;
    uint16_t freeSeats;
    uint16_t totalSeats;
} Event;

/**
 * Struttura per l'account utente
 */
typedef struct {
    char name[33]; // Max 32 caratteri
    char surname[33]; // Max 32 caratteri
    char username[33]; // Max 32 caratteri
    char hashedPassword[65]; // Max 64 caratteri
    int age;
    int admin;
} Account;

/**
 * Struttura per le credenziali
 */
typedef struct {
    char username[33]; // Max 32 caratteri
    char password[33]; // Max 32 caratteri
} Credentials;

#pragma endregion

#endif
