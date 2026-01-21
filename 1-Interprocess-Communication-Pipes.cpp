#include <iostream>
#include <unistd.h>
using namespace std;



void pipeline(const char* process1,const char* process2){
    int fd[2];
    pipe(fd);

    if(fork() != 0){ // Parent Process
        close(fd[0]); // Close the read end of Pipe
        dup2(fd[1],STDOUT_FILENO); // Copy Standard output of file to write end
        close(fd[1]); // Close the write end of pipe

        // Running Parent Process
        execlp("/usr/bin/cat", "cat",process1 ,NULL);
        perror("exec cat"); //  Error at cat



    }
    else{ // Child Process
        close(fd[1]); // Close the write end of pipe
        dup2(fd[0],STDIN_FILENO); // Copy to Standard input from file read end
        close(fd[0]); // Close the read end of Pipe

        // Running Child Process
        execlp("/usr/bin/grep", "grep", process2, NULL);
        perror("exec grep"); // Error at grep

    }
    close(fd[0]);
    close(fd[1]);
    
}


int main(){
    pipeline("lorem-ipsum.txt", "Lorem");
}