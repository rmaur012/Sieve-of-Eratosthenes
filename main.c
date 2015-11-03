/*
*Objective: Find all primes using the Sieve of Eratosthenes algorithm while having a user define the upper limit
*
*I hereby certify that this collective work is my own and none of it is the work of any other person or entity.
*- Ricardo Maury, 4174167
*/

#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

int main(){

	int upLimit;

	printf("Please give a number to find all primes up to that numner specified. (Enter a number from 2 through 10,000)\n");
	
	scanf("%d", &upLimit);

	upLimit = validate(upLimit);
	
	sieveOfEratosthenes(upLimit);
	
	return 0;
	
}
