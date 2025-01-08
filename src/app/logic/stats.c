//
// Autore: Lorenzo Rocca
//

//
// Inclusioni
//

#pragma region Inclusioni

#include "globals.h"

#pragma endregion

//
// Funzioni
//

#pragma region Funzioni

int createStatsFile() {
    // Verifica se il file esiste
    if (access(STATS_FILE, F_OK) == 0) {
        // Ritorna 0
        return 0;
    }

    // Crea il file
    FILE* file = fopen(STATS_FILE, "wb");

    // Controlla se il file è stato creato
    if (file == NULL) {
        // Ritorna 1
        return 1;
    }

    // Inizializza le statistiche
    SellsStats defaultSellStats = {
        .0f,
        .0f,
        .0f
    };

    // Scrive le statistiche
    fwrite(&defaultSellStats, sizeof(SellsStats), 1, file);

    // Chiudi il file
    fclose(file);
}

SellsStats getSellsStats() {
    // Apre il file
    FILE* file = fopen(STATS_FILE, "rb");

    // Controlla se il file è stato aperto
    if (file == NULL) {
        // Crea il file
        createStatsFile();

        // Ritorna le statistiche di default
        return (SellsStats) {
            .0f,
            .0f,
            .0f
        };
    }

    // Legge le statistiche
    SellsStats stats;
    fread(&stats, sizeof(SellsStats), 1, file);

    // Chiudi il file
    fclose(file);

    // Ritorna le statistiche
    return stats;
}

void saveSellStats(SellsStats stats) {
    // Apre il file
    FILE* file = fopen(STATS_FILE, "wb");

    // Controlla se il file è stato aperto
    if (file == NULL) {
        // Crea il file
        createStatsFile();

        // Esci dalla funzione
        return;
    }

    // Scrive le statistiche
    fwrite(&stats, sizeof(SellsStats), 1, file);

    // Chiudi il file
    fclose(file);
}

void addSoldTickets(int tickets, float earningsFromSold, float profits, float taxes) {
    // Ottieni le statistiche
    SellsStats stats = getSellsStats();

    // Aggiorna le statistiche
    stats.soldTickets += (long int) tickets;
    stats.totalEarnings += (double) earningsFromSold;
    stats.profits += (double) profits;
    stats.taxes += (double) taxes;

    // Salva le statistiche
    saveSellStats(stats);
}

#pragma endregion
