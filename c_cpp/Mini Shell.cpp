/*
	Made by ChipCookiesAndMilk
	Based on Abelardo Lopez slide's code from the Advanced Programming Class
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAXLINE 4096 

/*	Displays intro */
void intro()
{
	puts("\n\n\t\t\t\t WELCOME TO MINT");
	puts("\t\tThe nicest minishell project of the class");
	puts("\t\t\t[write help whenever you need]\n\n");
}
/*	Displays menu */
void printHelp(){
	puts("\n\t\t\t\tGet to Know MINT");
	puts("The commands you can use are pretty much the same as other shells, but we recomend you to try the next ones");
	puts("\tmkdir 	: Create a directory in current directory ");
	puts("\trmdir 	: Remove a directory in current directory ");
	puts("\tls 	: Show files in directory");
	puts("\ttouch 	: Create a file");
	puts("\topen 	: Open a file ");
	puts("\tclear 	: Clears the window ");
	puts("\tdate 	: Clears the window ");
	puts("\tpwd 	: Display the pathname for the current directory ");
	puts("\tabout 	: Credits ");
	puts("\thelp 	: Show this beatuful info");
	puts("\texit 	: Terminate the program\n");
}

/*	Displays credits */
void credits(){
	puts("\n Developed for the Advanced Programming Class\nCredits to Fabiola Hernandez (the coder),\nalso the code of profesor Abelardo Lopez and his slides :)\n");
}

int main(void){
	char   buf[MAXLINE];
	pid_t  pid;
	int    status;
	
	char *commandLine[5];							/* contains the entire commandLine */
	char *argument;
	unsigned int args = 0;							/* counter of arguments */
	unsigned int out  = 99;							/* just a diferente value of zero */
	intro();										/*  WLECOME */
    printf("MINT> ");								/* print prompt */ 
    
    for (int i = 0;i<5;i++) commandLine[i] = NULL;	/* Before use commandLine initialize it */
	while (fgets(buf,MAXLINE,stdin) != NULL){		/* reads from terminal */
		if(buf[strlen(buf)-1]=='\n')				/* end of line */
			buf[strlen(buf) - 1] = '\0';			/* replace newline with null */
		
		argument = strtok(buf, " \t");				/*	keep the space before \t */
		while (argument!= NULL && args<5){			/* only if there's Something in arguments && only 4 arguments **/        
			commandLine[args] = argument;			/* add the argument to complete the command */
			args++;	
			argument = strtok(NULL, " \t");			/* add an space to continue with next argument */
		}
		
		if(args == 0)
			out = 1;
		if(args == 1){
			if(strcmp(buf,"exit")==0)
				out = 2;
			else if(strcmp(buf,"help")==0)
				out = 3; 
			else if(strcmp(buf,"about")==0)
				out = 4;
			else{
				out = 6;
			} 
		}else out = 6;

		if((pid = fork())<0 ){						/* error handiling */
			printf("fork error");
			exit(1);
		}else if(pid == 0){							/* child process */ 
			//printf("Args in child: %d",args);
			if(out == 1){
				printf("Add some commands to the shell\n");
				exit(0);
			}
			else if(out == 2){
				puts("\n[You've logout]\n\tThanks for using MINT minishell :)\n\n");
				static char *argv[ ]={"kill","0"};
				execv("/bin/kill",argv);
			}
			else if(out == 3){
				printHelp();
				exit(0);
			}
			else if(out == 4){
				credits();
				exit(0);
			}
			else if(out > 5){						/* file, list of arguments */
									/* execlp, list of arguments must be followed by a null pointer*/
				execlp(commandLine[0],commandLine[0],commandLine[1],commandLine[2],commandLine[3],commandLine[4],(char *)0);
				printf("\n\tWe're sorry. Couldn’t execute: %s\n\n",buf);  
				exit(127);				/* Only if it does not exit */
			}
		}
													/* parent process*/   
		if((pid = waitpid(pid,&status,0))< 0){
			printf("\n Waitpid error\n");
			exit(1);
		}	
		args = 0;									/*	'resets' all */
		out  = 0;									
		for (int i = 0;i<5;i++) commandLine[i] = NULL;
		printf("MINT> ");
	}
	exit(0);
}