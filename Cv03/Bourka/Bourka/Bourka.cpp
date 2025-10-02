// Bourka.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Bourka.h"

using namespace std;

int main()
{
	double t, s, c = 340.0;

	printf("Zadejte cas: ");
	scanf_s("%lf", &t);

	s = c * t;

	printf("Blesk uhodil ve vzdalenosti %lf m", s);

	return 0;
}
