#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 

void executeCommand(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        execlp(command, command, (char *) NULL);
        exit(0);
    }
    
}

int getLength(char **array) {
    int len = 0;
    while (array[len] != NULL) {
        len++;
    }
    return len;
}

// Function where the system command is executed 
void execArgs(char** parsed) 
{ 
	int length = getLength(parsed);
    	if (length > 2 && strcmp(parsed[1], "&") == 0) {

		for (int i = 0; i < length; i++) {
		    if(parsed[i]!="&") {
		    	executeCommand(parsed[i]);
		    }
		}
		while(wait(NULL)>0);

	}
	else {
		pid_t pid = fork(); 

		if (pid == -1) { 
			printf("\nFailed forking child.."); 
			return; 
		} else if (pid == 0) { 
			if (execvp(parsed[0], parsed) < 0) { 
				printf("\nCould not execute command.."); 
			} 
			exit(0); 
		} else {
			wait(NULL); 
			return; 
		} 
	}
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
