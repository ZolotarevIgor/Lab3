#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

int main(int argc, char **argv) 
{
	pid_t pid = fork();

	if ( pid >= 0 ) {
	    if(pid==0){
    		int ret = execvp( "./minmax",argv);
    		if(ret == -1)
    		{
    		    printf("Exec error\n");
    		    return 1;
    		}
	   }
	}
	else {
	    printf("Fork fault\n");
	    return 1;
	}
    int status;
	waitpid(pid,&status,0);
    if(!WIFEXITED(status)){
        printf("Error exiting child process\n");
        return 1;
    }
	return 0;
}