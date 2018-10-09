#include <stdio.h>
#include <math.h>
#include <stdlib.h>   
#include <sys/stat.h>    
#include <string.h>

	static int folderCounter = 0;
	static void generateTextandPatternSize();
	static void makeTextAndPatternFiles();
	static int printToFile();
	char characters[100000000] = {0};
	char patternCharacters[1000000000] = {0};


int main(int argc) {
	int textLength, patternLength;
	
	for (int i = 2; i < 12; i+=2) {
		generateTextandPatternSize(i);
	}
return 0;
}

void generateTextandPatternSize(int product) {
   switch(product) {
      case 2 : //10^2
         makeTextAndPatternFiles(50, 2);
         makeTextAndPatternFiles(25, 4);
         makeTextAndPatternFiles(20, 5);
         makeTextAndPatternFiles(10, 10);
     
         break;
      case 4 : //10^4
      	 makeTextAndPatternFiles(5000, 2);
         makeTextAndPatternFiles(2500, 4);
         makeTextAndPatternFiles(2000, 5);
         makeTextAndPatternFiles(1000, 10);
      	break;

      case 6 : //10^6
      	 makeTextAndPatternFiles(500000, 2);
         makeTextAndPatternFiles(250000, 4);
         makeTextAndPatternFiles(200000, 5);
         makeTextAndPatternFiles(100000, 10);
      	break;

  	 case 8 : //10^8
      	 makeTextAndPatternFiles(50000000, 2);
         makeTextAndPatternFiles(25000000, 4);
         makeTextAndPatternFiles(20000000, 5);
         makeTextAndPatternFiles(10000000, 10);
      	break;

      case 10 : //10^10
         makeTextAndPatternFiles(5000000, 2000);      
      	 makeTextAndPatternFiles(25000000, 400);
      	 makeTextAndPatternFiles(20000000, 500);
         makeTextAndPatternFiles(10000000, 1000);
      	break;
      default :
         printf("Invalid \n" );
   }
}
  
void makeTextAndPatternFiles(int textLength, int patternLength) {
	//make text files
	for (int i = 0; i < textLength-1; i++) {
		characters[i] = 'A';
	}
	characters[textLength-1] = 'B';

	for (int i = 0; i < patternLength-1; i++) {
		patternCharacters[i] = 'A';
	}
	patternCharacters[patternLength-1] = 'B';   
    printToFile(characters, patternCharacters, textLength, patternLength);
}



int printToFile(char* characters, char* patternCharacters, int textLength, int patternLength) {
	FILE *textFile;
	FILE *patternFile;
	folderCounter = folderCounter;

	char directoryName[50] = { }; 
	int random = sprintf(directoryName ,"inputs/test%d/", folderCounter);
    char* extension = "text.txt";
    char* directoryWithExtention;
    directoryWithExtention = malloc(strlen(directoryName)+1+4); //make space for the new string
    strcpy(directoryWithExtention, directoryName); // copy directory name to the new space
    strcat(directoryWithExtention, extension); 

    //create new directory folders for newly created textfiles
    mkdir(directoryName, 0777);
 	textFile=fopen(directoryWithExtention, "w+");
 	// print to text file
 	for(int i = 0; i < textLength; i++) {
      	fprintf(textFile, "%c", characters[i]);
 	}

	printf("%s\n", directoryWithExtention);
	//print to pattern file
	//change extention
	char* patternExtension = "pattern.txt";
    char *directoryWithPatternExtention = malloc(strlen(directoryName)+10+10); //make space for the new string
    strcpy(directoryWithPatternExtention, directoryName); // copy directory name to the new space
    strcat(directoryWithPatternExtention, patternExtension); 
	mkdir(directoryName, 0777);
 	
	patternFile=fopen(directoryWithPatternExtention, "w+");
 	
	for(int i = 0; i < patternLength; i++) {
		fprintf(patternFile, "%c", patternCharacters[i]);
	}
	printf("%s\n", directoryWithPatternExtention);
	
folderCounter++;
printf("\nFolder counter:%d ", folderCounter);

memset(&characters[0], 0, sizeof(characters));
memset(&patternCharacters[0], 0, sizeof(patternCharacters));

//close the file 
   fclose (textFile);
   fclose(patternFile);
return 0;
}