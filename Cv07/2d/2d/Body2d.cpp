#include "Body2d.h"
#include <math.h>
#include <limits.h>

int indexNejblizsi(int velikost, int (*poleBodu)[2], int referencniX, int referencniY)
{
	int index;
	int minVzdalenost = INT_MAX;
	int vysledek = -1;

	for (index = 0; index < velikost; index++)
	{
		int dx = poleBodu[index][0] - referencniX;
		int dy = poleBodu[index][1] - referencniY;
		int aktVzdalenost = dx * dx + dy * dy;

		if (minVzdalenost > aktVzdalenost)
		{
			minVzdalenost = aktVzdalenost;
			vysledek = index;
		}
	}
	return vysledek;
}

double prumernaVzdalenost(int velikost, int (*poleBodu)[2], int referencniX, int referencniY)
{
	int index;
	double suma = 0;

	for (index = 0; index < velikost; index++)
	{
		int dx = poleBodu[index][0] - referencniX;
		int dy = poleBodu[index][1] - referencniY;
		suma += sqrt((double)dx * dx + dy * dy);
	}	
	double prumernaVzdalenost = suma / velikost;

	return prumernaVzdalenost;
	
}
int indexBodu(int velikost, int (*poleBodu)[2], int referencniX, int referencniY, int r, int (*vystupniPole)[2])
{
	int pocet = 0;
	for (int i = 0; i < velikost; i++) {
		int dx = poleBodu[i][0] - referencniX;
		int dy = poleBodu[i][1] - referencniY;

		double vzd = sqrt(dx * dx + dy * dy);
		if (vzd <= r) {
			vystupniPole[pocet][0] = poleBodu[i][0];
			vystupniPole[pocet][1] = poleBodu[i][1];
			pocet++;
		}
	}
	return pocet;
}