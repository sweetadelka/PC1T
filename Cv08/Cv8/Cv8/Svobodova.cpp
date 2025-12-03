#include "Svobodova.h"

int prunik(double zacatek1, double konec1, double zacatek2, double konec2, double* vysl_zacatek, double* vysl_konec){	if (konec1 < zacatek2 || konec2 < zacatek1)	{		return 0; 	}	*vysl_zacatek = (zacatek1 > zacatek2) ? zacatek1 : zacatek2;	*vysl_konec = (konec1 < konec2) ? konec1 : konec2;	return 1;}