#include <stdio.h>
#include <float.h>

int main(void)
{
	float max = FLT_MAX;
	float min = FLT_MIN;

	double dmax = LDBL_MAX;
	double dmin = LDBL_MIN;

	printf("%-20f %-5e %-5E\n", max, max, max);
	printf("%-20f %-5e %-5E\n", min, min, min);

	printf("%20f %-5e %-5E\n", dmax, dmax, dmax);
	printf("%-20f %-5e %-5E\n", dmin, dmin, dmin);

	return 0;


}