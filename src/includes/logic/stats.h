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

int createStatsFile();

SellsStats getSellsStats();

void saveSellStats(SellsStats stats);

void addSoldTickets(int tickets, float earningsFromSold, float profits, float taxes);

#pragma endregion

#endif