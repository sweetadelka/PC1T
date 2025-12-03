// StatistickeUdaje.cpp: Definuje vstupní bod pro aplikaci.
//

#include "StatistickeUdaje.h"
#include <ctype.h>

using namespace std;

int pocetPismen(char* text) 
{
	int pocet = 0;
	for (int i = 0; text[i]; i++) 
	{
		if (isalpha(text[i])) 
		{
			pocet++;
		}
	}
	return pocet;
}

int pocetCislic(char* text) 
{
	int pocet = 0;
	for (int i = 0; text[i]; i++) 
	{
		if (isdigit(text[i])) 
		{
			pocet++;
		}
	}
	return pocet;
}

int pocetSlov(char* text) 
{
	int pocet = 0;
	bool inWord = false;
	for (int i = 0; text[i]; i++) 
	{
		if (isalpha(text[i])) 
		{
			if (!inWord) 
			{
				inWord = true;
				pocet++;
			}
		} 
		else 
		{
			inWord = false;
		}
	}
	return pocet;
}

int main()
{
	char text[] = "Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi. Auto Hyundai ix35 ma pres 120 konskych sil.";
	
	printf("Pocet pismen: %d\n", pocetPismen(text));
	printf("Pocet cislic: %d\n", pocetCislic(text));
	printf("Pocet slov: %d\n", pocetSlov(text));

	return 0;
}
