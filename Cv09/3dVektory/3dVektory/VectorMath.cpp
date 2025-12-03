#include "VectorMath.h"

struct vector3d operace(struct vector3d u, struct vector3d v, enum typOperace typ)
{
	// Implementujte funkci operace tak aby vracela odpovídající hodnotu výsledku pøíslušné operace s vektory u a v.

	struct vector3d vysledek;
	vysledek.x = 0;
	vysledek.y = 0;
	vysledek.z = 0;

	switch (typ)
	{
	case soucet:
		vysledek.x = u.x + v.x;
		vysledek.y = u.y + v.y;
		vysledek.z = u.z + v.z;
		break;
	
	case skalarniSoucin:
		vysledek.x = u.x * v.x;
		vysledek.y = u.y * v.y;
		vysledek.z = u.z * v.z;
		break;

	case vektorovySoucin:
		vysledek.x = u.y * v.z - u.z * v.y;
		vysledek.y = u.z * v.x - u.x * v.z;
		vysledek.z = u.x * v.y - u.y * v.x;
		break;
	}
	return vysledek;
}


void tisk(struct vector3d w)
{
	// Implementujte funkci tisk tak aby tiskla vektor ve formátu „w = (x, y, z)“ a jeho velikost ve formátu „ | w | = velikost“
	printf("w = (%.2f, %.2f, %.2f)\n", w.x, w.y, w.z);
	printf("| w | = %.2f\n", sqrt(w.x * w.x + w.y * w.y + w.z * w.z));
}

int vect_cmp(struct vector3d u, struct vector3d v)
{
	double velikost_u = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
	double velikost_v = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (velikost_u > velikost_v)
		return 1;
	else if (velikost_u < velikost_v)
		return -1;
	else
		return 0;
}
