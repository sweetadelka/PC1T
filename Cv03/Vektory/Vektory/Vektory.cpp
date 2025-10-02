// Vektory.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Vektory.h"

using namespace std;

int main()
{
	int a, b, c, d;

	printf("Zadejte hodnoty prvniho vektoru: \n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("Zadejte hodnoty druheho vektoru: \n");
	scanf_s("%d", &c);
	scanf_s("%d", &d);

	int x = a - c;
	int y = b - d;
	printf("Vysledny vektor ma hodnoty: %d, %d\n", x, y);

	return 0;
}
