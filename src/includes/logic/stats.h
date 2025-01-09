//
// Autore: Lorenzo Rocca
//

#ifndef STATS_H
#define STATS_H

//
// Inclusioni
//

#pragma region Inclusioni

// Librerie interne al progetto
#include "globals.h"

#pragma endregion

//
// Prototipi funzioni
//

#pragma region Prototipi Funzioni

/**
 * Crea il file delle statistiche se non esiste.
 * 
 * @return 1 se si verifica un errore, 0 altrimenti.
 */
int createStatsFile();

/**
 * Ottiene le statistiche delle vendite dal file.
 * 
 * @return Le statistiche delle vendite.
 */
SellsStats getSellsStats();

/**
 * Salva le statistiche delle vendite nel file.
 * 
 * @param stats Le statistiche da salvare.
 */
void saveSellStats(SellsStats stats);

/**
 * Aggiunge i biglietti venduti e i guadagni al file delle statistiche.
 * 
 * @param tickets Il numero di biglietti venduti.
 * @param earningsFromSold I guadagni dalla vendita dei biglietti.
 * @param profits I profitti ottenuti.
 * @param taxes Le tasse pagate.
 */
void addSoldTickets(int tickets, float earningsFromSold, float profits, float taxes);

#pragma endregion

#endif