#include<readline/readline.h> 
#include<readline/history.h> 
#include <string.h>

#include "alias.c"
#include "parser.c"
#include "execFunc.c"
#include "builtInCmd.c"
 

int processString(char* str, char** parsed, char** parsedpipe) 
{ 

	char* strpiped[2];
       	char* stralies[3];	
	int piped = 0;
	int alias = 0;

	piped = parsePipe(str, strpiped); 

	if (piped) { 
		parseSpace(strpiped[0], parsed); 
		parseSpace(strpiped[1], parsedpipe); 

	} else {
	        char *aliasSubstring = strstr(str, "alias");
		char *equalSign = strchr(str, '=');
		if(aliasSubstring!=NULL){
			if(equalSign!=NULL){
				alias = 1;
				parseEqualSign(str,parsed);
			}else{
				alias = 2;
				parseSpace(str,parsed);
			}
		}
		else{
			parseSpace(str, parsed); 
		}
	} 

	if (ownCmdHandler(parsed)) 
		return 0; 
	else if(alias){
		aliasCommand(parsed,alias);
		return 0;
	}
	else
		return 1 + piped; 
} 

int main() 
{ 
	char inputString[MAXCOM], *parsedArgs[MAXLIST]; 
	char* parsedArgsPiped[MAXLIST]; 
	int execFlag = 0; 
	Node** table = get_table();
	init_shell(); 
	
	insert(table, "ll","ls -l");

	while (1) { 
		printDir(); 
		if (takeInput(inputString)) 
			continue; 
		
		
		execFlag = processString(inputString,parsedArgs,parsedArgsPiped);

		char* aliasCommand = get(table,parsedArgs[0]);
		if(aliasCommand){
			memcpy(inputString, aliasCommand, sizeof(inputString));
		
			execFlag = processString(inputString, parsedArgs, parsedArgsPiped);  
	}
		

		// Execute 
		if (execFlag == 1) 
			execArgs(parsedArgs); 

		if (execFlag == 2) 
			execArgsPiped(parsedArgs, parsedArgsPiped); 
			
	} 
	return 0; 
} 
