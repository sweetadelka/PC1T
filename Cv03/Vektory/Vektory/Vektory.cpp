// Vektory.cpp: Definuje vstupní bod pro aplikaci.
//

#include <vector>
#include <cstdio>
#include "Vektory.h"

using namespace std;

int main()
{
	/*int a, b, c, d;

	printf("Zadejte hodnoty prvniho vektoru: \n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("Zadejte hodnoty druheho vektoru: \n");
	scanf_s("%d", &c);
	scanf_s("%d", &d);

	int x = a - c;
	int y = b - d;
	printf("Vysledny vektor ma hodnoty: %d, %d\n", x, y);*/

	vector<double> v1(2), v2(2), v3(2);

	printf("Zadejte hodnoty prvniho vektoru: \n");
	scanf_s("%lf", &v1[0]);
	scanf_s("%lf", &v1[1]);

	printf("Zadejte hodnoty druheho vektoru: \n");
	scanf_s("%lf", &v2[0]);
	scanf_s("%lf", &v2[1]);

	v3[0] = v1[0] - v2[0];
	v3[1] = v1[1] - v2[1];
	printf("Vysledny vektor ma hodnoty: %lf, %lf\n", v3[0], v3[1]);

	
	return 0;
}
