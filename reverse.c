/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 1:			Warmup to C and Unix programming
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			24.4.2021
 * Yhteistyö ja lähteet:	
 *
 * - https://technotip.com/8770/c-program-to-print-elements-of-array-in-reverse-order/
 * - https://www.youtube.com/watch?v=sYcOK51hl-A
 * 
 */
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128



struct Node
{
	char structChar[MAX];
	struct Node *ptrNext;
};
typedef struct Node Node;



void print_inputfile(char filename[])
{	
	/* this function opens and prints out the contents of the supplied 
	 * file line by line in reverse */
	 
	
	FILE *file;				// taken straight from the getline() manual page
	char *line = NULL;						
	size_t len = 0;
	ssize_t nread;
	char array[MAX][MAX];
	int h = 0;
	int count = 0;


	file = fopen(filename, "r");
	
	if (file == NULL)
	{
		fprintf(stderr, "ERROR: cannot open file '%s'\n\n", filename);
		exit(1);
	}

	while ((nread = getline(&line, &len, file)) != -1) 		// taken straight from the getline() manual page
	{       
               //fwrite(line, nread, 1, stdout);
               
               strcpy(array[h], line);		/* adding every read line into the array */
               h++;
               count++;
	}
	free(line);
	
	fprintf(stdout, "\n");
	
	fprintf(stdout, "-- Contents of the file '%s' in reverse order: \n\n", filename);
	
	for (h = count-1; h >= 0; h--)
	{
		fprintf(stdout, "%s", array[h]);	/* printing the array in reverse order */
							/* source: https://technotip.com/8770/c-program-to-print-elements-of-array-in-reverse-order/ */
	}
	
	fprintf(stdout, "\n");
	
	fclose(file);
	return;
}



Node* reverseList(Node* ptrStart)
{
	/* reverses the linked list, takes the 'head' of 
	 * the linked list as an argument, and after reversing 
	 * returns the 'head' */

	/* source for function:  https://www.youtube.com/watch?v=sYcOK51hl-A */


	Node *prev = NULL;
	Node *curr = ptrStart;		/* starting with the current node being the head of the list */
	Node *ptrNext;
	
	while (curr != NULL)		/* looping through all the nodes until there's none left */
	{
		ptrNext = curr->ptrNext;
		curr->ptrNext = prev;
		prev = curr;
		curr = ptrNext;
	}
	ptrStart = prev;		/* returning the original list's last node as the new first node */
	return ptrStart;
}



int main(int argc, char *argv[])
{	
	char filename[MAX];
	Node *ptrStart = NULL;
	
	
	if (argc == 1)
	{
	
	/* TAKING USER INPUT FROM STDIN AND REVERSING INTO STDOUT */
	
	
		char *line = NULL;
		size_t len;
		char array[MAX][MAX];
		int y;
		int d;
		int count = 0;
		
		fprintf(stdout, "Give some inputs, type 'STOP' to stop: \n\n");
		
		while(getline(&line, &len, stdin) != -1)
		{
			if (strcmp(line, "\n") == 0)			/* exiting if the user doesn't give a word */
			{
				fprintf(stdout, "ERROR: Input needs to be words, not empty lines!\n\n");
				exit(1);
			}
			
			if (strcmp(line, "STOP\n") == 0)		/* breaking the loop if the user types 'STOP' */
			{
				break;
			}
			
			strcpy(array[y], line);			/* adding the user's typed lines into an array */
			count++;					/* incrementing count to keep up with how many words are typed */
			y++;
		}
		free(line);
		
		fprintf(stdout, "\n");
		
		
		/* PRINTING THE ARRAY IN REVERSE ORDER */
		/* source used for function: https://technotip.com/8770/c-program-to-print-elements-of-array-in-reverse-order/ */
		
		
		fprintf(stdout, "-- Your inputs in reverse order: \n\n");
		
		for (d = count-1; d >= 0; d--)
		{
			fprintf(stdout, "%s", array[d]);
		}
		fprintf(stdout, "\n");

		return 0;
	}
	
	
	
	if (argc == 2)
	{
	
	/* PRINTING OUT THE CONTENTS OF THE FILE IN REVERSE*/
	
	
		strcpy(filename, argv[1]);
		print_inputfile(filename);
	}
	
	
	
	if (argc == 3)
	{
	
	/* REVERSING THE CONTENTS OF THE INPUT FILE INTO OUTPUT FILE */
	
	
		FILE *input;
		FILE *output;
	
		Node *slider;
		Node *ptrNew;
		char line[MAX];
	
	
		if (strcmp(argv[1], argv[2]) == 0)		/* input and output files can't be same */
		{
			fprintf(stderr, "ERROR: input and output file must differ\n\n");
			exit(1);
		}
		
		
		input = fopen(argv[1], "r");
		output = fopen(argv[2], "w");
		
		if (input == NULL)			/* error checking for both files */
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
		
		
		while(fscanf(input, "%[^\n]%*c", line) != EOF)	/* looping until all lines are checked */
		{
			if ((ptrNew = (Node*)malloc(sizeof(Node))) == NULL)
			{
				fprintf(stdout, "ERROR: malloc failed!\n\n");
				exit(1);
			}
			
			strcpy(ptrNew->structChar, line);
			ptrNew->ptrNext = NULL;
			
			if (ptrStart == NULL)
			{
				ptrStart = ptrNew;		/* the actual creation of the linked list */
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
		
		
		ptrStart = reverseList(ptrStart);		/* reversing the list */

		Node* curr = ptrStart;				/* going through the now-reversed list */
		while(curr)					/* one node at a time */
		{
			fprintf(output, "%s\n", curr->structChar);
			curr = curr->ptrNext;
		}
		fprintf(stdout, "\n");
		
		fprintf(stdout, "-- The reversed contents of file '%s' can be found in file '%s'\n\n", argv[1], argv[2]);
		
		fclose(input);
		fclose(output);
	}
	
	
	if (argc > 3)
	{
		fprintf(stderr, "INCORRECT USAGE, try: ./reverse <input> <output>\n\n");
		exit(1);
	}
	
	
	return 0;
}



