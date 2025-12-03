// 2d.cpp: Definuje vstupní bod pro aplikaci.
//

#include "2d.h"
#include "Body2d.h"
#define POCET_BODU 10

using namespace std;

int main()
{
	int body[POCET_BODU][2] =
	{
	5, 10,
	-14, 2,
	45, 4,
	-9, 8,
	58, -3,
	47, 5,
	-18, -86,
	75, 7,
	-25, 51,
	17, 98
	};

	

	int x, y, i_nejblizsi, r, i_bodu;
	int vystup[POCET_BODU][2];

	printf("Zadejte X a Y souradnice ref. boduu oddelene carkou: \n");
	scanf_s("%d,%d", &x, &y);
	printf("Zadejte vzdalenost r: \n");
	scanf_s("%d", &r);

	i_nejblizsi = indexNejblizsi(POCET_BODU, body, x, y);	

	printf("\n Nejblizsi bod: (%d,%d)\n", 
		body[i_nejblizsi][0], body[i_nejblizsi][1]);

	printf("\n Prumerna vzdalenost od ref. bodu: %lf\n\n", 
		prumernaVzdalenost(POCET_BODU, body, x, y));

	i_bodu = indexBodu(POCET_BODU, body, x, y, r, vystup);

	printf("Body v dosahu %d od ref. bodu:\n", r);
	for (int i = 0; i < i_bodu; i++) {
		printf("(%d,%d)\n", vystup[i][0], vystup[i][1]);
	}

	return 0;

	

}


