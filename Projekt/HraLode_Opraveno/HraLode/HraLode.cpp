#include "HraLode.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // pro rand()
#include <windows.h> // pro Sleep()

using namespace std;

int mojePole[5][5]; // pole hráče
int aiPole[5][5]; // pole AI
int hrac2Pole[5][5]; // pole druhého hráče (pro 2 hráče)

void odpocet3s() { // Odpočet 3 sekund před dalším krokem
	for (int i = 3; i > 0; i--) { // od 3 do 1
		printf("%d...\n", i); // vypíše číslo
		Sleep(1000); // pauza 1 sekunda
	}
}

void vynulujPole(int pole[5][5]) { //Vynuluje pole abychom mohli začít novou hru
	int i, j; // iterátory
	for (i = 0; i < 5; i++) { // pro každý řádek
		for (j = 0; j < 5; j++) { // pro každý sloupec
			pole[i][j] = 0; // nastaví hodnotu na 0
		}
	}
}
void vypisMojePole(int pole[5][5]) { //Vypíše pole hráče
	int i, j; // iterátory
	printf("\n   1 2 3 4 5\n"); // hlavička sloupců
	for (i = 0; i < 5; i++) { // pro každý řádek
		printf("%c ", 'A' + i); // hlavička řádků
		for (j = 0; j < 5; j++) { // pro každý sloupec
			if (pole[i][j] == 0) printf(" ."); // prázdné pole
			if (pole[i][j] == 1) printf(" L"); // loď
			if (pole[i][j] == 2) printf(" X"); // zásah
			if (pole[i][j] == 3) printf(" O"); // voda
		}
		printf("\n"); // nový řádek po každém řádku
	}
}
void vypisAIPoleProHrace(int pole[5][5]) { //Vypíše pole AI pro hráče
	int i, j; // iterátory
	printf("\n   1 2 3 4 5\n"); // hlavička sloupců
	for (i = 0; i < 5; i++) { // pro každý řádek
		printf("%c ", 'A' + i); // hlavička řádků
		for (j = 0; j < 5; j++) { // pro každý sloupec
			if (pole[i][j] == 2) printf(" X"); // zásah
			else if (pole[i][j] == 3) printf(" O"); // voda
			else printf(" ."); // nikdy neukazujeme lodě 1
		}
		printf("\n"); // nový řádek po každém řádku
	}
}

void automatickeLode(int pole[5][5]) { // Automatické rozmístění lodí
	int k = 0; // počet umístěných lodí
	int r, c; // náhodné řádky a sloupce
	while (k < 5) { // dokud není umístěno 5 lodí
		r = rand() % 5; // náhodný řádek
		c = rand() % 5; // náhodný sloupec

		if (pole[r][c] == 0) { // pokud je pole prázdné
			pole[r][c] = 1; // umístí loď
			k++; // zvýší počet umístěných lodí
		}
	}
}
void rucniLode(int pole[5][5]) { // Ruční rozmístění lodí
	int k = 0; // počet umístěných lodí
	char pismeno; // řádek jako písmeno
	int cislo; // sloupec jako číslo
	int r, s; // převedené řádky a sloupce

	while (k < 5) { // dokud není umístěno 5 lodí
		printf("Zadejte pozici pro lod #%d (např. A1): ", k + 1); // výzva pro hráče
		scanf(" %c%d", &pismeno, 1, &cislo); // načtení vstupu

		r = pismeno - 'A'; // převod písmena na řádek
		s = cislo - 1; // převod čísla na sloupec

		// kontrola platnosti
		if (r < 0 || r >= 5 || s < 0 || s >= 5) { // mimo rozsah
			printf("Neplatna pozice!\n"); // chyba
			continue; // znovu požádat o vstup
		}

		// kontrola, zda už tam není loď
		if (pole[r][s] == 1) { // už je tam loď
			printf("Tady už je loď!\n"); // chyba
			continue;	// znovu požádat o vstup
		}

		pole[r][s] = 1; // umístí loď
		k++; // zvýší počet umístěných lodí
	}
}
void rozmistiLode(int pole[5][5]) { // Rozmístění lodí (automatické nebo ruční)
	int volba; // volba hráče

	printf("1) Automaticke rozmisteni lodi\n");	// nabídka
	printf("2) Rucni rozmisteni lodi\n"); // nabídka
	printf("Vyber: "); // výzva pro hráče
	scanf("%d", &volba); // načtení volby

	if (volba == 1) { // automatické rozmístění
		automatickeLode(pole); // zavolá funkci pro automatické rozmístění
	}
	else if (volba == 2) { // ruční rozmístění
		rucniLode(pole); // zavolá funkci pro ruční rozmístění
	}
	else {
		printf("Neplatna volba, pouzije se automaticke rozmisteni.\n"); // chyba
		automatickeLode(pole); // zavolá funkci pro automatické rozmístění
	}
}
int zbyvajiLode(int pole[5][5]) { // Počet zbývajících lodí na poli
	int i, j; // iterátory
	int pocet = 0; // počet lodí

	for (i = 0; i < 5; i++) { // pro každý řádek
		for (j = 0; j < 5; j++) { // pro každý sloupec
			if (pole[i][j] == 1) { // pokud je tam loď
				pocet++;    // zvýší počet lodí
			}
		}
	}
	return pocet; // vrátí počet zbývajících lodí
}

void strelbaDoAIPole() { // Střelba do pole AI
	char pismeno; // řádek jako písmeno
	int cislo; // sloupec jako číslo
	int r, c; // převedené řádky a sloupce
	int zasah = 0; // zda hráč trefil loď

	do { // hráč může střílet znovu, pokud trefil
		printf("Kam chces strilet (napr. B5): "); // výzva pro hráče
		scanf(" %c%d", &pismeno, &cislo); // načtení vstupu

		r = pismeno - 'A'; // převod písmena na řádek
		c = cislo - 1; // převod čísla na sloupec

		while (r < 0 || r > 4 || c < 0 || c > 4) { // kontrola platnosti pozice
			printf("Spatna pozice!\n"); // chyba

			printf("Kam chces strilet (napr. B5): ");
			scanf(" %c%d", &pismeno, &cislo); // načtení vstupu

			r = pismeno - 'A'; // převod písmena na řádek
			c = cislo - 1; // převod čísla na sloupec
		}

		if (aiPole[r][c] == 1) { // pokud je tam loď
			printf("Trefa! Muzes strilet znovu!\n"); // hlásí trefu
			aiPole[r][c] = 2; // označí zásah
			zasah = 1; // hráč může střílet znovu
			vypisAIPoleProHrace(aiPole); // vypíše pole AI pro hráče

		}
		else if (aiPole[r][c] == 0) { // pokud je tam voda
			printf("Mimo!\n"); // hlásí minutí
			aiPole[r][c] = 3; // označí vodu
			zasah = 0; // hráč nemůže střílet znovu
		}
		else {
			printf("Uz jsi tady strilel.\n"); // pokud už tam hráč střílel
		}
	} while (zasah); // pokud hráč trefil, může střílet znovu
}
void strelbaDoPole(int pole[5][5]) { // Střelba do zadaného pole
	char pismeno; // řádek jako písmeno
	int cislo; // sloupec jako číslo
	int r, c; // převedené řádky a sloupce
	int zasah = 0; // zda hráč trefil loď

	do {
		printf("Kam chces strilet (napr. B5): "); // výzva pro hráče
		scanf(" %c%d", &pismeno, &cislo); // načtení vstupu

		r = pismeno - 'A'; // převod písmena na řádek
		c = cislo - 1; // převod čísla na sloupec

		if (r < 0 || r > 4 || c < 0 || c > 4) { // kontrola platnosti pozice
			printf("Spatna pozice!\n"); // chyba

			printf("Kam chces strilet (napr. B5): "); // výzva pro hráče
			scanf(" %c%d", &pismeno, &cislo); // načtení vstupu

			r = pismeno - 'A'; // převod písmena na řádek
			c = cislo - 1; // převod čísla na sloupec
		}

		if (pole[r][c] == 1) { // pokud je tam loď
			printf("Trefa! Muzes strilet znovu!\n"); // hlásí trefu
			pole[r][c] = 2; // označí zásah
			zasah = 1; // hráč může střílet znovu
			vypisAIPoleProHrace(pole); // vypíše pole pro hráče
		}
		else if (pole[r][c] == 0) { // pokud je tam voda
			printf("Mimo!\n"); // hlásí minutí
			pole[r][c] = 3; // označí vodu
			zasah = 0; // hráč nemůže střílet znovu
		}
		else {
			printf("Uz jsi tady strilel.\n"); // pokud už tam hráč střílel
		}
	} while (zasah); // pokud hráč trefil, může střílet znovu
}
void aiStrelba() { // Tah AI
	int r, s; // řádky a sloupce
	int zasah = 0; // zda AI trefila loď

	do { // AI může střílet znovu, pokud trefila
		while (1) { // opakuj, dokud nenajde nepoužité pole
			r = rand() % 5; // náhodný řádek (0-9)
			s = rand() % 5; // náhodný sloupec (0-9)

			// kontrola, zda už AI nestřílela na toto pole
			if (mojePole[r][s] != 2 && mojePole[r][s] != 3) {
				break; // našla nepoužité pole → vystřel
			}
		}

		printf("AI strili na %c%d\n", 'A' + r, s + 1); // oznámení tahu AI

		if (mojePole[r][s] == 1) { // pokud je tam loď
			printf("AI te trefila!\n"); // hlásí trefu
			mojePole[r][s] = 2; // označí zásah
			zasah = 1; // AI může střílet znovu
		}
		else if (mojePole[r][s] == 0) { // pokud je tam voda
			printf("AI minula.\n"); // hlásí minutí
			mojePole[r][s] = 3; // označí vodu
			zasah = 0; // AI nemůže střílet znovu
		}
	} while (zasah); // pokud AI trefila, může střílet znovu
}

void hraSingle() {
	vynulujPole(mojePole); // Vynuluje pole hráče
	vynulujPole(aiPole); // Vynuluje pole AI

	rozmistiLode(mojePole); // Automaticky rozmístí lodě hráče
	automatickeLode(aiPole);   // Automaticky rozmístí lodě AI

	while (1) { // hlavní smyčka hry

		// hráčův tah
		printf("\n--- Tvuj pohled na AI pole ---\n"); // zobrazení pole AI pro hráče
		vypisAIPoleProHrace(aiPole); // vypíše pole AI pro hráče

		printf("\n--- Tvoje pole (AI na tebe strili) ---\n"); // zobrazení hráčova pole
		vypisMojePole(mojePole); // vypíše hráčovo pole

		printf("\n--- Tvuj tah ---\n"); // hráčův tah
		strelbaDoAIPole(); // střelba do pole AI

		if (zbyvajiLode(aiPole) == 0) { // kontrola výhry
			printf("\n--- Vyhral jsi! ---\n"); // hráč vyhrál
			break; // ukončení hry
		}

		// AI tah
		printf("\n--- Tah AI ---\n"); // AI tah
		aiStrelba(); // AI střílí do hráčova pole

		if (zbyvajiLode(mojePole) == 0) { // kontrola výhry AI
			printf("\n--- Prohral jsi! ---\n"); // AI vyhrála
			break; // ukončení hry
		}
	}
}
void hraMultiplayer() { // Hra pro dva hráče
	vynulujPole(mojePole);   // Vynuluje pole hráče 1
	vynulujPole(hrac2Pole);  // Vynuluje pole hráče 2

	printf("--- Hrac 1 rozmisti lode ---\n"); // hráč 1 rozmístí lodě
	odpocet3s(); // odpočet 
	system("cls"); // vyčistí obrazovku
	rozmistiLode(mojePole); // rozmístí lodě hráče 1
	printf("\n--- Tvoje pole (Hrac 1) ---\n"); // zobrazí pole hráče 1
	vypisMojePole(mojePole); // vypíše pole hráče 1
	Sleep(5000); // pauza
	system("cls"); // vyčistí obrazovku

	printf("--- Hrac 2 rozmisti lode ---\n"); // hráč 2 rozmístí lodě
	odpocet3s(); // odpočet 
	system("cls"); // vyčistí obrazovku
	rozmistiLode(hrac2Pole); // rozmístí lodě hráče 2
	printf("\n--- Tvoje pole (Hrac 2) ---\n"); // zobrazí pole hráče 2
	vypisMojePole(hrac2Pole); // vypíše pole hráče 2
	Sleep(5000); // pauza
	system("cls"); // vyčistí obrazovku

	while (1) { // hlavní smyčka hry

		// --- Tah hráče 1 ---
		printf("--- Hrac 1 je na tahu ---\n"); // oznámení tahu hráče 1
		odpocet3s(); // odpočet 
		system("cls"); // vyčistí obrazovku

		printf("--- Hrac 1 ---\n"); // hráč 1
		printf("\n--- Tvoje pole ---\n"); // zobrazení hráčova pole
		vypisMojePole(mojePole);         // hráč 1 vidí své lodě
		printf("\n--- Pole protihrace (jen zasahy a minule pokusy) ---\n");
		vypisAIPoleProHrace(hrac2Pole);  // vidí jen zásahy a minulé střely

		printf("\n--- Tvuj tah ---\n"); // hráč 1 střelba
		strelbaDoPole(hrac2Pole); // střelba do pole hráče 2

		if (zbyvajiLode(hrac2Pole) == 0) { // kontrola výhry hráče 1
			printf("--- Hrac 1 vyhral!--- \n"); // hráč 1 vyhrál
			break;
		}

		Sleep(3000); // pauza mezi tahy
		system("cls"); // vyčistí obrazovku

		// --- Tah hráče 2 ---
		printf("--- Hrac 2 je na tahu ---\n"); // oznámení tahu hráče 2
		odpocet3s(); // odpočet 
		system("cls"); // vyčistí obrazovku

		printf("--- Hrac 2 ---\n"); // hráč 2
		printf("\n--- Tvoje pole ---\n"); // zobrazení hráčova pole
		vypisMojePole(hrac2Pole);        // hráč 2 vidí své lodě
		printf("\n--- Pole protihrace (jen zasahy a minule pokusy) ---\n");
		vypisAIPoleProHrace(mojePole);   // vidí jen zásahy a minulé střely

		printf("\n --- Tvuj tah ---\n"); // hráč 2 střelba
		strelbaDoPole(mojePole); // střelba do pole hráče 1

		if (zbyvajiLode(mojePole) == 0) { // kontrola výhry hráče 2
			printf("Hrac 2 vyhral!\n"); // hráč 2 vyhrál
			break; // ukončení hry
		}

		Sleep(3000); // pauza mezi tahy
		system("cls"); // vyčistí obrazovku
	}
}

int main() {
	int volba; // volba režimu hry

	srand(time(NULL)); // inicializace generátoru náhodných čísel

	printf("===== LODE =====\n"); // název hry
	printf("1) Pro jednoho hrace\n"); // nabídka režimů
	printf("2) Pro dva hrace\n"); // nabídka režimů
	printf("Vyber: "); // výzva k volbě režimu
	scanf("%d", &volba); // načtení volby

	system("cls"); // vyčistí obrazovku

	if (volba == 1) { // pokud je volba 1
		hraSingle(); // spustí hru pro jednoho hráče
	}
	else if (volba == 2) { // pokud je volba 2
		hraMultiplayer(); // spustí hru pro dva hráče
	}
	else { // neplatná volba
		printf("Neplatna volba.\n");
	}

	return 0; // ukončení programu
}

