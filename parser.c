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

// Function for finding redirect by overwriting
int parseRedirW(char* str, char** strredir){
	int flag = 1; 
	strredir[0] = strsep(&str, ">");
	strredir[1] = strsep(&str, ">"); 
	if(strredir[1] && strredir[1][0]=='\0'){
		strredir[1] = strsep(&str, ">"); 
		flag = 2;

	}
	//printf("%s\n%s\n",strredir[0],strredir[1]);
	if(strredir[1]){
		//remove space before and after it
		while(isspace(strredir[1][0]))
			strredir[1] = strredir[1]+1;
		int i = 0;
		while(!isspace(strredir[1][++i]));
		strredir[1][i]='\0';
		return 2 * flag;
	}
	return 0;
}

// Function for finding redirect by appending
int parseRedirA(char* str, char** strredir){
	int i; 
	strredir[0] = strtok(str, ">>"); 
	strredir[1] = strtok(NULL, ">>"); 
	printf("%s\n%s\n",strredir[0],strredir[1]);
	if(strredir[1]){
		//remove space before and after it
		while(isspace(strredir[1][0]))
			strredir[1] = strredir[1]+1;
		i = 0;
		while(!isspace(strredir[1][++i]));
		strredir[1][i]='\0';
		return 4;
	}
	return 0;
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

