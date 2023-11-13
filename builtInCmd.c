// Clearing the shell 
#define clear() printf("\033[H\033[J") 

// Greeting shell during startup 
void init_shell() 
{ 
	clear(); 
	printf("\n\n\n\n******************************************"); 
	printf("\n\n\n\t**** OS::1402 SHELL ****"); 
	printf("\n\n\n\n******************************************"); 
	char* username = getenv("USER"); 
	printf("\n\n\nHello @%s", username); 
	printf("\n"); 
	sleep(1); 
	clear(); 
} 

// Take Input 
int takeInput(char* str) 
{ 
	char* buf; 

	buf = readline("\n$  "); 
	if (strlen(buf) != 0) { 
		add_history(buf); 
		strcpy(str, buf); 
		return 0; 
	} else { 
		return 1; 
	} 
} 

// Print Current Directory. 
void printDir() 
{ 
	char cwd[1024]; 
	getcwd(cwd, sizeof(cwd)); 
	printf("\nDir: %s", cwd); 
} 


// Help command builtin 
void openHelp() 
{ 
	puts("\n...Use the shell at your own risk..."
		"\nList of Commands supported:"
		"\n> cd"
		"\n> ls"
		"\n> exit"
		"\n> All other general commands available in UNIX shell"
		"\n> Pipe handling"
		"\n> Improper space handling"); 

	return; 
} 

// Function to execute builtin commands 
int ownCmdHandler(char** parsed) 
{ 
	int NoOfOwnCmds = 4, i, switchOwnArg = 0; 
	char* ListOfOwnCmds[NoOfOwnCmds]; 
	char* username; 

	ListOfOwnCmds[0] = "exit"; 
	ListOfOwnCmds[1] = "cd"; 
	ListOfOwnCmds[2] = "help"; 
	ListOfOwnCmds[3] = "meow"; 

	for (i = 0; i < NoOfOwnCmds; i++) { 
		if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) { 
			switchOwnArg = i + 1; 
			break; 
		} 
	} 

	switch (switchOwnArg) { 
	case 1: 
		printf("\nGoodbye\n"); 
		exit(0); 
	case 2: 
		chdir(parsed[1]); 
		return 1; 
	case 3: 
		openHelp(); 
		return 1; 
	case 4: 
		username = getenv("USER"); 
		printf("\nMeow %s.\nMind that this is not a place to play around."
			"\nUse help to know more..\n", 
			username); 
		return 1; 
	default: 
		break; 
	} 

	return 0; 
} 
