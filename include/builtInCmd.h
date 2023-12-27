#ifndef BUILTINCMD_H
#define BUILTINCMD_H

#include <stdio.h>

// Clearing the shell 
#define clear() printf("\033[H\033[J") 


// Greeting shell during startup 
void init_shell();

// Take Input 
int takeInput(char*);

// Print Current Directory. 
void printDir();

// Help command builtin 
void openHelp();

// Function to execute builtin commands 
int ownCmdHandler(char**);

#endif // BUILTINCMD_H