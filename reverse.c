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
#define MAX 512


/*
struct Node
{
	char structChar[MAX];
	struct Node *pointerNext;
};
typedef struct Node Node;
*/

/*
void print_inputfile(char filename[MAX])
{
	FILE *file;							// taken straight from the getline() manual page
	char *line = NULL;						
	size_t len = 0;
	ssize_t nread;


	file = fopen(filename, "r");
	
	if (file == NULL)
	{
		perror("Couldn't read from file...\n");			//CHANGE THIS!!!
		exit(1);
	}
	
	
	
	/* WITH ONLY USER INPUT TEXTFILE (1 cmdline argument) */

/*
	while ((nread = getline(&line, &len, file)) != -1) 			// taken straight from the getline() manual page
	{       
               fwrite(line, nread, 1, stdout);
	}
	
	printf("\n");
	
}
*/




/*
void write_into_outputfile(char inputfile[MAX], char outputfile[MAX])
{


}
*/






int main(int argc, char *argv[])
{
	printf("\n");
	
	/*
	FILE *file;							// taken straight from the getline() manual page
	char *line = NULL;						
	size_t len = 0;
	ssize_t nread;
	*/
	
	/*
	
	Node *pointerStart;
	Node *slider;
	Node *pointerNew;
	// char line[MAX];

	
	printf("== DEBUG: reading from a file ==\n");
	printf("\n");
	
	
	
	file = fopen("textfile.txt", "r");
	
	if (file == NULL)
	{
		perror("Couldn't read from file...\n");			//CHANGE THIS!!!
		exit(1);
	}
	
	
	/* WITH ONLY USER INPUT TEXTFILE (1 cmdline argument) */
	/*
	
		while ((nread = getline(&line, &len, file)) != -1) 			// taken straight from the getline() manual page
	{       
               fwrite(line, nread, 1, stdout);
	}
	
	printf("\n");
	*/
	
	
	/* ADDING TO LINKED LIST (2 cmdline arguments) */
	
	
	
	
	/*
	while ((nread = getline(&line, &len, file)) != -1) 			// taken straight from the getline() manual page
	{       
	
		if ((pointerNew = (Node*)malloc(sizeof(Node))) == NULL)
		{
			perror("Memory allocation failed...\n");		//CHANGE THIS!!!
			exit(1);
		}
		
               pointerNew->structChar = line;
               pointerNew->pointerNext = NULL;
               
               if (pointerStart == NULL)
               {
               	pointerStart = pointerNew;
               } else
               {
               	slider = pointerStart;
               	while (slider->pointerNext != NULL)
               	{
               		slider = slider->ponterNext;
               	}
               	slider->pointerNext = pointerNew;
               }
	}
	
	*/
	
	
	
	printf("\n");
	printf("== DEBUG: after reading every line from file ==\n");	
	
	
	/*
	fclose(file);
	*/
	
	
	printf("Kiitos ohjelman käytöstä :-D\n");
	exit(0);
}
