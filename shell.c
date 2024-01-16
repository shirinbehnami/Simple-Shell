#include<readline/readline.h> 
#include<readline/history.h> 

#include "parser.c"
#include "execFunc.c"
#include "builtInCmd.c"


int processString(char* str, char** parsed, char** parsedpipe) 
{ 

	char* strpiped[2]; 
	int piped = 0; 

	piped = parsePipe(str, strpiped); 

	if (piped) { 
		parseSpace(strpiped[0], parsed); 
		parseSpace(strpiped[1], parsedpipe); 

	} else { 
		parseSpace(str, parsed); 
	} 
	printf("24\n");
	if (ownCmdHandler(parsed)) 
		return 0; 
	else
		return 1 + piped; 
} 

int main() 
{ 
	char inputString[MAXCOM], *parsedArgs[MAXLIST]; 
	char* parsedArgsPiped[MAXLIST]; 
	int execFlag = 0; 
	init_shell(); 
	printf("37\n");
	while (1) { 
		printDir(); 
		printf("40\n");
		if (takeInput(inputString)) 
			continue; 
		execFlag = processString(inputString, 
		parsedArgs, parsedArgsPiped);  
		printf("45\n");
 

		// Execute 
		if (execFlag == 1) {
			execArgs(parsedArgs); 
		}

		if (execFlag == 2) 
			execArgsPiped(parsedArgs, parsedArgsPiped); 
	} 
	return 0; 
} 
