#include "Cv8.h"
#include "Svobodova.h"


using namespace std;

int main()
{
	double zacatek1, konec1, zacatek2, konec2;
	double vysl_zacatek, vysl_konec;

	printf("Zadejte prvni interval oddeleny mezerou: \n");
	scanf_s("%lf %lf", &zacatek1, &konec1);

	printf("Zadejte druhy interval oddeleny mezerou: \n");
	scanf_s("%lf %lf", &zacatek2, &konec2);

	int vysl = prunik(zacatek1, konec1, zacatek2, konec2, &vysl_zacatek, &vysl_konec);

	if (vysl)
	{
		printf("Prunik intervalu je (%.3lf, %.3lf)\n", vysl_zacatek, vysl_konec);
	}
	else
	{
		printf("Intervaly se neprotinaji.\n");
	}

	return 0;
}
