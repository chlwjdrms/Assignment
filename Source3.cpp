#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRandomNumber(const double min, const double max) {
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min)*temp;

	return temp;
}

bool isInsideEllipsoid(const double x, const double y) {

	const double rowx = 1.0;
	const double coly = 0.5;
	const double f = ((x - 1.0)*(x - 1.0) / (rowx*rowx)) + ((y - 0.5)*(y - 0.5) / (coly*coly));


	if (f <= 1) return true;
	else return false;
}


void main() {
	FILE *of = fopen("Ellipsoid.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++) {
		double x = getRandomNumber(0.0, 2.0);
		double y = getRandomNumber(0.0, 1.0);

		if (isInsideEllipsoid(x, y) == true)
			fprintf(of, "%f, %f\n", x, y);
	}

	fclose(of);
}