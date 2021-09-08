#include <stdio.h>
#include <float.h>

int main(void)
{
	float max = FLT_MAX;
	float min = FLT_MIN;

	double dmax = DBL_MAX;
	double dmin = DBL_MIN;

	printf("%5f %-5e %-5E\n", max, max, max);
	printf("%5f %-5e %-5E\n", min, min, min);

	printf("%5f %-5e %-5E\n", dmax, dmax, dmax);
	printf("%5f %-5e %-5E\n", dmin, dmin, dmin);

	return 0;


}