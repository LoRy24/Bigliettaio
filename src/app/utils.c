//
// Autore: Lorenzo Rocca
//

#pragma region Inclusioni

#include "globals.h"

#pragma endregion

//
// Utils
//

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

float calculateCommission(float price, float percentage) {
    // Calcola la commissione
    return price * (percentage / 100);
}

void clearStringBuffer(char* buffer, int length) {
    for (int i = 0; i < length; i++) {
        buffer[i] = '\0';
    }
}

int isDateValid(char* date) {
    // Definisco le stringhe per il mese e l'anno
    char month[3] = {date[0], date[1], '\0'};
    char year[5] = {date[2], date[3], date[4], date[5], '\0'};

    // Converto il mese e l'anno in interi
    int monthInt = atoi(month);
    int yearInt = atoi(year);

    // Controllo se il mese è valido
    if (monthInt < 1 || monthInt > 12) {
        return -1;
    }

    // Ottengo l'anno corrente e il mese corrente
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;
    int currentMonth = tm.tm_mon + 1;

    // Controllo se l'anno è valido
    if (yearInt < currentYear) {
        return -2;
    }

    // Se l'anno è uguale all'anno corrente, controllo il mese
    if (yearInt == currentYear && monthInt < currentMonth) {
        return -2;
    }

    // Tutto ok
    return 0;
}

#pragma endregion
