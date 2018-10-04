#include <stdio.h>
#include <math.h>
#include <stdlib.h>       

static int generateTextLength();
static int generateLengths();
static int generateTextData();
static int printToFile();

int main(int argc) {

	double product_array[5] = {100, 10000, 1000000, 100000000, 10000000000};	
	double product = product_array[0];
	char *characters[26] = {0};
	char *patternCharacters[26] = {0};
	double textLength, patternLength;
	double randomNumber;


	generateTextLength(characters, product, textLength, patternLength);


   return 0;
}


int generateTextLength(char* characters, char* patternCharacters, double product, double textLength,
 double patternLength) {

	textLength = product;
	patternLength = 1;

    printf("\nTEXT LENGTH: %f PATTERN LENGTH: %f\n", textLength, patternLength);

    generateTextData(characters, patternCharacters, textLength, patternLength);
    printToFile(characters, patternCharacters, textLength, patternLength);
   // generateLengths(characters, textLength, patternLength);
	return 0;
}

int generateLengths(char* characters, char*patternCharacters, double textLength, double patternLength) {

	if(patternLength < textLength) {
	textLength = textLength / 10;
	patternLength = patternLength * 10;

    printf("\nTEXT LENGTH: %f PATTERN LENGTH: %f\n", textLength, patternLength);

    generateTextData(characters, patternCharacters, textLength, patternLength);
    generateLengths(characters, patternCharacters, textLength, patternLength);

}
	return 0;
}


int generateTextData(char* characters, char* patternCharacters, double textLength, double patternLength) {

double randomNumber; 
int random = 0;



	printf("TEXT: ");
	for(int i = 0; i < textLength; i++) {
	  	characters[i] = 'A' + rand() % 26;
	 //  	printf("%c", characters[i]);
	  //	fprintf(fptr, "%c", characters[i]);
    	}
//printf("\n ");
    	//create spaces randomly through the text
    	for(int i = 0; i <  textLength / 3 ; i++) {
			randomNumber = 1 + rand() % (int) textLength; 
			random = randomNumber;
		
			printf("%d  ",random);
			//Ensures two spaces are not formed side by side
			if((characters[random+1] != 32)  && (characters[random-1] != 32) 
				&& (characters[random+2] != 32) ){
			characters[random] =  32; //32 is ASCII code for a space
			}
    	}
printf("\nNEW: \nTExt: ");
    	//for(int i = 0; i < textLength; i++) {
	  //	printf("%c", characters[i]);
	  //	fprintf(fptr, "%c", characters[i]);
    //	}

    	printf("\nPATTERN: ");

//create pattern file to match 
    for(int i = 0; i < patternLength; i++) {
	  patternCharacters[i] = 'A' + rand() % 26;
  	//  printf("%c", characters[i]);
  	//  fprintf(fptr, "%c", characters[i]);
  	  }

		printf("\n");
	return 0;
}

int printToFile(char* characters, char* patternCharacters, double textLength, double patternLength) {
	FILE *file;

/* open the file for writing*/
    file = fopen ("output.txt","w");

	for(int i = 0; i < textLength; i++) {
		fprintf(file, "%c", characters[i]);
	}

	/* close the file*/  
   fclose (file);
return 0;
}