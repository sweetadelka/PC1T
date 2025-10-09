// SudaCisla.cpp: Definuje vstupní bod pro aplikaci.
//

#include "SudaCisla.h"

using namespace std;

int jeSude(int cislo)
{
	return cislo % 2 == 0;
}

int main()
{
	int cislo;
	while (true)
	{
		printf("Zadejte cislo: "),
		scanf("%d", &cislo);
		printf("%s\n", jeSude(cislo) ? "Cislo je sude" : "Cislo je liche");		
	}
	return 0;
}
