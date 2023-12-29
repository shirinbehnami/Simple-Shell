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

/*
void parseEquilSign(char* str, char** parsed){
	
	for(int i=0;i<MAXLIST;i++){
		parsed[i] = strsep(&str, "=");
		
		if(parsed[i] == NULL)
			break;
		if(strlen(parsed[i]) == 0)
			i--;
	}
	
}
*/

void parseEqualSign(char* str, char** parsed){
        char * sign[MAXCOM];

        for(int i=0;i<MAXLIST;i++){
                sign[i] = strsep(&str, "=");

                if(sign[i] == NULL)
                        break;
                if(strlen(sign[i]) == 0)
                        i--;
        }
        parseSpace(sign[0],parsed);
        parsed[2] = sign[1];
//      strcpy(parsed[2],sign[1]);
}

