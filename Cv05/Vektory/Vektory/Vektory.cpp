// Vektory.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Vektory.h"

using namespace std;

void soucet(double a[3], double b[3], double c[3])
{
	for (int i = 0; i < 3; i++) 
	{
		c[i] = a[i] + b[i];
	}
}

double velikost(double a[3]) 
{
	return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

double skalarniSoucin(double a[3], double b[3]) 
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void vektorovySoucin(double a[3], double b[3], double c[3])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

int main()
{
	double a[3], b[3], c[3];
	printf("Vektor A (3 hodnoty oddelene carkou): ");
	scanf_s("%lf,%lf,%lf",&a[0], &a[1], &a[2]);
	printf("\n");

	printf("Vektor B (3 hodnoty oddelene carkou): ");
	scanf_s("%lf,%lf,%lf", &b[0], &b[1], &b[2]);
	printf("\n");

	soucet(a, b, c);
	printf("Soucet A + B: (%.2lf, %.2lf, %.2lf)\n", c[0], c[1], c[2]);
	printf("\n");

	printf("velikost A: %.2lf\n", velikost(a));
	printf("\n");

	printf("skalarni soucin AB: %.2lf\n", skalarniSoucin(a, b));
	printf("\n");

	vektorovySoucin(a, b, c);
	printf("vektorovy soucin AB: (%.2lf, %.2lf, %.2lf)\n", c[0], c[1], c[2]);
	return 0;
}
