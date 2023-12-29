#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 


#define MAXCOM 1000 // Max number of letters to be supported 
#define MAXLIST 100 // Max number of commands to be supported 


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

void parseEquelSign(char* str, char** parsed){
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
//	strcpy(parsed[2],sign[1]);
}





int main(){

	char str[] = "alias ll=\"ls -al\"";
	char * parsed[MAXCOM];
	printf("%s\n",str);
	
	parseEquelSign(str,parsed);
	printf("%s\n",str);
	printf("%s\t\t%s\t\t%s\n",parsed[0],parsed[1],parsed[2]);




	return 0;
}




