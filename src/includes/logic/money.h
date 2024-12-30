//
// Autore: Lorenzo Rocca
//

#ifndef MONEY_H
#define MONEY_H

//
// Prototipi Funzioni
//

#pragma region Prototipi Funzioni

/**
 * Calcola il prezzo pieno
 * 
 * @param basePrice Prezzo base
 */
float calculateFullPrice(float basePrice);

/**
 * Calcola il prezzo per gli over 65
 * 
 * @param basePrice Prezzo base
 */
float calculateO65Price(float basePrice);

/**
 * Calcola il prezzo per gli under 14
 * 
 * @param basePrice Prezzo base
 */
float calculateU14Price(float basePrice);

#pragma endregion

#endif