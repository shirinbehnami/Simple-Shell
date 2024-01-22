#include<readline/readline.h> 
#include<readline/history.h> 

#include "parser.c"
#include "execFunc.c"
#include "builtInCmd.c"
 

int processString(char* str, char** parsed, char** parsedpipe, FILE* file) 
{ 

	char* strpiped[2], * strredir[2]; 
	int piped = 0, redir = 0; 
	char str1[MAXCOM]; 
	redir = parseRedirW(str, strredir); 
	printf("%d\n",redir);


	piped = parsePipe(strredir[0], strpiped); 

	if (piped) { 
		parseSpace(strpiped[0], parsed); 
		parseSpace(strpiped[1], parsedpipe); 

	} else { 
		parseSpace(strredir[0], parsed); 
	} 

	if(redir==2){
		printf("redir2");
		char* filename = strredir[1];
		file = freopen(filename, "w", stdout);
		if (file == NULL) {
			perror("Error opening file");
			return 1;
		}
	}
	else if(redir==4){
		printf("redir4");
		char* filename = strredir[1];
		file = freopen(filename, "a", stdout);
		if (file == NULL) {
			perror("Error opening file");
			return 1;
		}
	}

	if (ownCmdHandler(parsed)) 
		return 0; 
	else
		return 1 + piped + redir; 
} 

int main() 
{ 
	FILE *file;
	char inputString[MAXCOM], *parsedArgs[MAXLIST]; 
	char* parsedArgsPiped[MAXLIST]; 
	int execFlag = 0; 
	init_shell(); 

	while (1) { 
		printDir(); 
		if (takeInput(inputString)) 
			continue; 

		execFlag = processString(inputString, 
		parsedArgs, parsedArgsPiped, file);  

		// Execute 
		if (execFlag == 1) 
			execArgs(parsedArgs); 

		else if (execFlag == 2) 
			execArgsPiped(parsedArgs, parsedArgsPiped); 

		else if (execFlag == 3 | execFlag == 5){
			execArgs(parsedArgs); 
			freopen("/dev/tty", "w", stdout);
		}

		else if (execFlag == 4 | execFlag == 6){
			execArgsPiped(parsedArgs, parsedArgsPiped); 
			freopen("/dev/tty", "w", stdout);
		}

	} 
	return 0; 
} 
