// PrestupnyRok.cpp: Definuje vstupní bod pro aplikaci.
//

#include "PrestupnyRok.h"

using namespace std;

int jePrestupny(int rok) 
{
	return (rok % 400 == 0) || (rok % 4 == 0 && rok % 100 != 0);
}

int main()
{
	int rok;
	while (true)
	{
		printf("Zadejte rok: ");
		scanf("%d", &rok);
		printf("%d\n", jePrestupny(rok));
	}
}
