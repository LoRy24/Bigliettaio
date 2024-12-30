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

#pragma endregion
