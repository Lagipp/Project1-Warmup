/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 1:			Warmup to C and Unix programming
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			7.4.2021
 * Yhteistyö ja lähteet:	<>
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	printf("\n");
	
	
	FILE *file;							// taken straight from the getline() manual page
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	
	
	//FILE *file;
	//char line[255];
	
	
	printf("== DEBUG: reading from a file ==\n");
	printf("\n");
	
	
	
	file = fopen("textfile.txt", "r");
	
	if (file == NULL)
	{
		perror("Couldn't read from file...\n");
		exit(1);
	}
	
	while ((nread = getline(&line, &len, file)) != -1) 			// taken straight from the getline() manual page
	{
	
	
               //printf("Retrieved line of length %zu:\n", nread);
               
               
               fwrite(line, nread, 1, stdout);
	}
	printf("\n");
	printf("== DEBUG: after reading every line from file ==\n");	
	
	
	
	/*
	while(fscanf(file, "%[^\n]", line) != EOF)				// https://www.programiz.com/c-programming/examples/read-file
	{
		printf("%s\n", line);
	}
	
	printf("== DEBUG: after reading every line ==\n");
	printf("\n");
	*/

	
	
	fclose(file);
	
	printf("Kiitos ohjelman käytöstä :-D\n");
	exit(0);
}
