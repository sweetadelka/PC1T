// Soubory.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Soubory.h"

using namespace std;

int main()
{
	const char* cesta_vstup = "C:\\VUT\\PC1T\\Cv10\\vstup.txt";
	const char* cesta_vystup = "C:\\VUT\\PC1T\\Cv10\\vystup.txt";
	char akt_znak;
	int pocet_pismen = 0;
	int pocet_velkych_pismen = 0;
	int pocet_cislic = 0;
	int pocet_vet = 0;
	int pocet_slov = 0;

	FILE* vstup;
	FILE* vystup;

	if (fopen_s(&vstup, cesta_vstup, "r") != 0)
	{
		printf("Nelze otevrit vstupni soubor");
		return -1;
	}

	while ((akt_znak = fgetc(vstup)) != EOF)
	{
		if (akt_znak >= 'a' && akt_znak <= 'z')
		{
			pocet_pismen++;
		}
		else if (akt_znak >= 'A' && akt_znak <= 'Z')
		{
			pocet_pismen++;
			pocet_velkych_pismen++;
		}
		else if (akt_znak >= '0' && akt_znak <= '9')
		{
			pocet_cislic++;
		}
		else if (akt_znak == '.' || akt_znak == '!' || akt_znak == '?')
		{
			pocet_vet++;
		}
		else if (akt_znak == ' ' || akt_znak == '\n' || akt_znak == '\t')
		{
			pocet_slov++;
		}
	}

	fclose(vstup);

	printf("Pocet pismen: %d\n", pocet_pismen);
	printf("Pocet cislic: %d\n", pocet_cislic);
	printf("Pocet velkych pismen: %d\n", pocet_velkych_pismen);
	printf("Pocet vet: %d\n", pocet_vet);
	printf("Pocet slov: %d\n", pocet_slov);

	if (fopen_s(&vystup, cesta_vystup, "w") != 0)
	{
		printf("Nelze otevrit vystupni soubor");
		return -1;
	}

	fprintf(vystup, "Pocet pismen: %d\n", pocet_pismen);
	fprintf(vystup, "Pocet cislic: %d\n", pocet_cislic);
	fprintf(vystup, "Pocet velkych pismen: %d\n", pocet_velkych_pismen);
	fprintf(vystup, "Pocet vet: %d\n", pocet_vet);
	fprintf(vystup, "Pocet slov: %d\n", pocet_slov);

	fclose(vystup);


}
