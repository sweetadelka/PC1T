#include "3dVektory.h"
#include "VectorMath.h"

using namespace std;

int main()
{
	/*Napište kód do funkce main, který vyzve uživatele k zadání všech tří složek(oddělených
	čárkou) obou vektorů, pak se zeptá na požadovanou operaci(1 = soucet, 2 =
	vektorovySoucin), zavolá funkci operace z VectorMath a zobrazí výsledky pomocí funkce tisk.*/

	struct vector3d u, v, vysledek;
	enum typOperace op;
	printf("Zadejte slozky vektoru 'u' (oddeleno carkou): ");
	scanf_s("%lf,%lf,%lf", &u.x, &u.y, &u.z);

	printf("Zadejte slozky vektoru 'v' (oddeleno carkou): ");
	scanf_s("%lf,%lf,%lf", &v.x, &v.y, &v.z);

	printf("Zadejte typ operace (1 = soucet, 2 = skalarniSoucin, 3 = vektorovySoucin): ");
	scanf_s("%d", &op);

	vysledek = operace(u, v, op);

	tisk(vysledek);

	printf("Porovnani velikosti vektoru 'u' a 'v': \n");
	switch (vect_cmp(u, v))
	{
	case 1:
		printf("Vektor 'u' je vetsi nez vektor 'v'");
		break;

	case -1:
		printf("Vektor 'v' je vetsi nez vektor 'u'");
		break;

	case 0:
		printf("Vektory jsou stejne velke");
		break;
	}
	return 0;
}
