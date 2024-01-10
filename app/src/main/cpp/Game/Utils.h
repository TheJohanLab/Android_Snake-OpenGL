#pragma once
#include <iostream>
#include <random>       /* time */
#include <vector>
#include <algorithm>


enum class direction {
	UP, DOWN, LEFT, RIGHT
};

static vec2 generateRandomCoords(int min, int max, std::vector<vec2>& excludedValues)
{

	std::random_device rd; // Utilisé une seule fois pour initialiser le moteur
	std::mt19937 rng(rd()); // Moteur de nombres aléatoires (Mersenne-Twister dans ce cas)
	std::uniform_int_distribution<int> uni(min, max); // Distribution uniforme garantie
	vec2 coords;

	do {
		coords = { (uint8_t)uni(rng), (uint8_t)uni(rng) };
	} while (std::find(excludedValues.begin(), excludedValues.end(), coords) != excludedValues.end());


	return coords;
}

