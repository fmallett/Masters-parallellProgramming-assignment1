#include <stdio.h>
#include <math.h>
#include <stdlib.h>       

static int generateTextLength();
static int generateLengths();
static int generateTextData();

int main(int argc) {

	double product_array[5] = {100, 10000, 1000000, 100000000, 10000000000};	
	double product = product_array[0];
	char *characters[26] = {0};
	double textLength, patternLength;

	generateTextLength(characters, product, textLength, patternLength);

}

int generateTextLength(char* characters, double product, double textLength, double patternLength) {

	textLength = product;
	patternLength = 1;

    printf("\nTEXT LENGTH: %f PATTERN LENGTH: %f\n", textLength, patternLength);

    generateTextData(characters, textLength, patternLength);
    generateLengths(characters, textLength, patternLength);
	return 0;
}

int generateLengths(char* characters, double textLength, double patternLength) {

	if(patternLength < textLength) {
	textLength = textLength / 10;
	patternLength = patternLength * 10;

    printf("\nTEXT LENGTH: %f PATTERN LENGTH: %f\n", textLength, patternLength);

    generateTextData(characters, textLength, patternLength);
    generateLengths(characters, textLength, patternLength);

}
	return 0;
}


int generateTextData(char* characters, double textLength, double patternLength) {


//create text file
	printf("TEXT: ");
	for(int i = 0; i < textLength; i++) {
	  	characters[i] = 'A' + rand() % 26;
	   	printf("%c", characters[i]);
    	}
printf("\nPATTERN: ");

//create pattern file to match 
    for(int i = 0; i < patternLength; i++) {
	  characters[i] = 'A' + rand() % 26;
  	  printf("%c", characters[i]);
    }
printf("\n");
return 0;
}