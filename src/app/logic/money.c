//
// Autore: Lorenzo Rocca
//

//
// Inclusioni
//

#pragma region Inclusioni

#include "forms.h"

#pragma endregion

//
// Funzioni Utilitarie
//

#pragma region Funzioni Utilitarie

float calculateFullPrice(float basePrice) {
    return basePrice * 1.15;
}

float calculateO65Price(float basePrice) {
    return basePrice * 1.12;
}

float calculateU14Price(float basePrice) {
    return basePrice * 1.06;
}

#pragma endregion
