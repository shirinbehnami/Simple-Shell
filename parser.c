#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

#define MAXCOM 1000 // Max number of letters to be supported 
#define MAXLIST 100 // Max number of commands to be supported 

// Function for finding pipe 
int parsePipe(char* str, char** strpiped) 
{ 
	int i; 
	for (i = 0; i < 2; i++) { 
		strpiped[i] = strsep(&str, "|"); 
		if (strpiped[i] == NULL) 
			break; 
	} 

	if (strpiped[1] == NULL) 
		return 0; 
	else { 
		return 1; 
	} 
} 

// Function for finding redirect 
int parseRedir(char* str, char** strredir){
	int i; 
	for (i = 0; i < 2; i++) { 
		strredir[i] = strsep(&str, ">"); 

		if (strredir[i] == NULL) 
			break; 
	} 
	if(strredir[1]){
		strredir[1] = strredir[1]+1;
	}

	if (strredir[1] == NULL) 
		return 0; 
	else { 
		return 2; 
	} 
}

// Function for parsing command words 
void parseSpace(char* str, char** parsed) 
{ 
	int i; 

	for (i = 0; i < MAXLIST; i++) { 
		parsed[i] = strsep(&str, " "); 

		if (parsed[i] == NULL) 
			break; 
		if (strlen(parsed[i]) == 0) 
			i--; 
	} 
}

