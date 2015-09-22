#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COMPUTATIONS 100000

int sd(int x){
	int sum = 0, Digit = 0;
	while (x > 0){
		Digit = x % 10;
		x /= 10;
		sum += Digit;

	}
	return sum;
}

int main(void){
	int i = 0, x = 0, y = 0, z = 0, sumfact = 0, smith = 0;
	long timesec = 0;
	timesec = time(NULL);
	srand((unsigned int)timesec);

	do{
		y = rand();
		z = rand();
		x = ((y % 32768) + 1)*((z % 32768) + 1) + 1;
		sumfact = 0;
		z = x;

		for (y = 2; y*y <= z;){
			if (z%y == 0){
				sumfact += sd(y);
				z /= y;
			}
			else{
				if (y > 2)
					y += 2;
				else
					y = 3;
			}
		}

		if (z == 1)
			z = 0;

		if (z != 0)
			sumfact += sd(z);

		if (z == x) 
			sumfact = 0;

		if (sumfact == sd(x)){
			smith++;
			printf("%10d is Smith number\n", x);
		}
		i++;
	} while (i <= COMPUTATIONS);

	printf("\n\n");
	printf("Found %4.2f%% Smith numbers \n", (100.0*smith) / i);
	printf("$ \n");

	return 0;
}

