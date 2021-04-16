/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 1:			Warmup to C and Unix programming
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			16.4.2021
 * Yhteistyö ja lähteet:	<>
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512



struct Node
{
	char structChar[MAX];
	struct Node *ptrNext;
};
typedef struct Node Node;



void print_inputfile(char filename[])
{

	/* WITH ONLY USER INPUT TEXTFILE (1 cmdline argument) */

	FILE *file;							// taken straight from the getline() manual page
	char *line = NULL;						
	size_t len = 0;
	ssize_t nread;


	file = fopen(filename, "r");
	
	if (file == NULL)
	{
		fprintf(stderr, "ERROR: cannot open file '%s'\n\n", filename);
		exit(1);
	}

	while ((nread = getline(&line, &len, file)) != -1) 			// taken straight from the getline() manual page
	{       
               fwrite(line, nread, 1, stdout);
	}
	
	fprintf(stdout, "\n");
	fclose(file);
	return;
}


/*
void printReverse(Node* ptrStart, char filename[])
{

	/* USING RECURSION TO GO THROUGH THE LIST IN REVERSE ORDER */
	/* source: https://stackoverflow.com/questions/27047351/print-singly-linked-list-in-reverse-order */

/*
	if (ptrStart == NULL)
	{
		return;
	}
	
	printReverse(ptrStart->ptrNext, filename);
	fprintf(*filename, "%s\n", ptrStart->structChar);
	
	
}
*/


/*
void reverseList(Node* ptrStart)
{
	if (ptrStart == NULL || ptrStart->ptrNext == NULL)
	{
		return;
	}
	
	Node* prev = NULL;
	Node* curr = ptrStart;
	Node* ptrNext;
	
	while (curr)
	{
		ptrNext = curr->ptrNext;
		curr->ptrNext = prev;
		prev = curr;
		curr = ptrNext;
	}
	
	ptrStart = prev;
}
*/

/*
*/

int main(int argc, char *argv[])
{	
	char filename[MAX];
	
	Node *ptrStart = NULL;
	
	
	if (argc == 1)
	{
		//code;	// stdin -> stdout
		return 0;
	}
	
	
	if (argc == 2)
	{
		strcpy(filename, argv[1]);
		
		print_inputfile(filename);
	}
	
	
	if (argc == 3)
	{
		
		FILE *input;
		FILE *output;
	
		Node *slider;
		Node *ptrNew;
		char line[MAX];
	
	
		if (strcmp(argv[1], argv[2]) == 0)
		{
			fprintf(stderr, "ERROR: input and output file must differ\n\n");
			exit(1);
		}
		
		
		input = fopen(argv[1], "r");
		output = fopen(argv[2], "w");
		
		if (input == NULL)
		{
			fprintf(stderr, "ERROR: cannot open file '%s'\n\n", argv[1]);
			exit(1);
		}
		
		if (output == NULL)
		{
			fprintf(stderr, "ERROR: cannot open file '%s'\n\n", argv[2]);
			exit(1);
		}
		
		
		/* CREATING LINKED LIST FROM 'input' FILE */
		
		while(fscanf(input, "%[^\n]%*c", line) != EOF)
		{
			if ((ptrNew = (Node*)malloc(sizeof(Node))) == NULL)
			{
				fprintf(stdout, "malloc failed... \n\n");
				exit(1);
			}
			
			strcpy(ptrNew->structChar, line);
			ptrNew->ptrNext = NULL;
			
			if (ptrStart == NULL)
			{
				ptrStart = ptrNew;
			} else
			{
				slider = ptrStart;
				while(slider->ptrNext != NULL)
				{
					slider = slider->ptrNext;
				}
				slider->ptrNext = ptrNew;
			}
		}
		
		
		/* WRITING LINKED LIST IN REVERSE INTO 'output' FILE */
		
		
		
		/*
		reverseList(ptrStart);
		
		Node* curr = ptrStart;
		while(curr)
		{
			fprintf(output, "%s\n", curr->structChar);
			curr = curr->ptrNext;
		}
		fprintf(stdout, "\n");
		*/
		
		
		
		
		
		fclose(input);
		fclose(output);
	}
	
	if (argc > 3)
	{
		fprintf(stderr, "usage: ./reverse <input> <output>\n\n");
		exit(1);
	}
	

	fprintf(stdout, "DEBUG: end of program...\n\n");
	return 0;
}



