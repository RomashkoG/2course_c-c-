#include<stdio.h>

int main() {
	double a, t, v, distance, targettime;
	printf("Pleace enter the acceleration: ");
	scanf_s("%lf", &a);
	printf("Pleace enter the time: ");
	scanf_s("%lf", &t);
	printf("Pleace enter max velosity: ");
	scanf_s("%lf", &v);

	printf("Distance = %f\n", (a * t * t) / 2);
	printf("Target time = %f\n", (v) / a);
}