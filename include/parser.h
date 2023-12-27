#ifndef PARSER_H
#define PARSER_H

#define MAXCOM 1000 // Max number of letters to be supported 
#define MAXLIST 100 // Max number of commands to be supported 


// Function for finding pipe 
int parsePipe(char*, char**); 

// Function for parsing command words 
void parseSpace(char*, char**);

#endif //PARSER_H