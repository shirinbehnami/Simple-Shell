#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 

void executeCommand(char **parsed) {
    pid_t pid = fork();

    if (pid == -1) 
    {
        perror("fork");
        return;
    } else if (pid == 0) 
    {
        if (execvp(parsed[0], parsed) < 0) 
            perror("execvp");
        exit(EXIT_FAILURE);
    } 
    else 
    {
        wait(NULL);  
        return;
    }
}


void handleInput(char **parsedArgs) {
    char *sub_command[100];
    int i = 0, j = 0;

    while (parsedArgs[i] != NULL) {
        if (strcmp(parsedArgs[i], "&") == 0) {
            if (j != 0) {
                sub_command[j] = NULL;
                executeCommand(sub_command);
                j = 0;
            }
        } else {
            sub_command[j++] = parsedArgs[i];
        }
        i++;
    }

    if (j > 0) {
        sub_command[j] = NULL;
        executeCommand(sub_command);
    }
}

// Function where the system command is executed 
void execArgs(char** parsed) 
{ 
	handleInput(parsed); 
} 

// Function where the piped system commands is executed 
void execArgsPiped(char** parsed, char** parsedpipe) 
{ 
	int pipefd[2];
    if(pipe(pipefd) < 0){
        printf("failed.\n");
        return;
    }

    pid_t p1, p2;
    p1 = fork();
    if(p1 < 0){
        printf("Failed.\n");
    }
    else if(p1 == 0){ //child 1
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO); 
        close(pipefd[1]);

        execvp(parsed[0], parsed);
    }
    else{ //parent
        p2 = fork();
        if(p2 < 0){
            printf("Failed.\n");
        } 
        else if(p2 == 0){
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO); 
            close(pipefd[0]); 

            execvp(parsedpipe[0], parsedpipe);        
        } 
        else{
            wait(NULL);
            wait(NULL);
        }      
    }
} 
