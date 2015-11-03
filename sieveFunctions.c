#include <stdio.h>
#include <math.h>

#define MIN 2		//Minimum of the range of possible values
#define MAX 10000	//Maximum of the range of possible values

void printAllPrimes(int *pa, int highLimit);
void sieveOfEratosthenes(int upperLimit);
int validate(int inputin);

int validate(int inputin){ //Validates the input the user provided, recursively
	
	int correctInput;
	
	if(inputin>=MIN && inputin<=MAX){ //If in the range...
		
		return inputin;
		
	} else {
		
		printf("Error: Incorrect Value. Please Enter A Correct Value. (Enter a number from 2 through 10,000)\n");
		scanf("%d", &correctInput);
		correctInput = validate(correctInput);
		return correctInput;

	}
}

void sieveOfEratosthenes(int upperLimit){

	int startingpoint;
	int wholeArray[upperLimit-1];
	int ai = 0; // ai = array index

	for(startingpoint = MIN; startingpoint <= upperLimit; startingpoint++){ //This will add all the numbers in the array, starting from to the limit the user gave. Generates entire array up to "upperLimit"

		wholeArray[ai] = startingpoint;
		ai++;

	}
	
	int currentIndex = 0; //This will point to the index where we will take the number in the index and mark off the multiples based on that number
	int markOffMultiples; //This will go through the array and mark off the multiples of the number that "currectIndex" points to	
	int checkForMultiples; // This will hold the result of checking whether a number is a multiple of another, it will be a 0 if it is

	while(wholeArray[currentIndex]<sqrt(upperLimit)){
	
		if(wholeArray[currentIndex] != 0){

		 	for(markOffMultiples = currentIndex+1; markOffMultiples < upperLimit; markOffMultiples++){

				if((checkForMultiples = wholeArray[markOffMultiples] % wholeArray[currentIndex]) == 0){				
					wholeArray[markOffMultiples] = 0; //We equal the value to 0 as way to mark off the value since it is a multiple.			
				}
			}
		}	

		currentIndex++;		
	}

	int *pa;
	pa = wholeArray;
	printAllPrimes(pa, upperLimit);
}


void printAllPrimes(int *parray, int highLimit){
	
	int holdColumnOne = 0; //Will hold the integer that will be displayed in the first column
	int goThrough=MIN; //Will be used as criteria to go through array in the while loop
	
	printf("All primes from %d through %d are:\n",MIN , highLimit);
	
	while(goThrough <= highLimit){//This loop will stop when we get to the end of the array, by pointer
		
		if(*parray != 0 && holdColumnOne == 0){

			holdColumnOne = *parray;
			parray++;

		} else if(*parray != 0){

			printf(" %5d   %5d\n", holdColumnOne, *parray);
			holdColumnOne = 0;
			parray++;

		} else { //When *parray = 0

			parray++;

		}
		goThrough++;
	}
	
	if(holdColumnOne != 0){ //This is in case there was a number left that was not printed, if there are an odd number of primes
		printf(" %5d\n", holdColumnOne);
	}
}
