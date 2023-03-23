#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{
    pid_t pid1, pid2;
    int status1, status2;

    printf("Running parent process PID: %d\n\n", getpid());

    pid1 = fork();
    if (pid1 == 0) {
        // Child 1
        printf("Running child process PID: %d\n", getpid());
        execle("./echoall", "echoall", "Bandicoot", "Pacman", NULL, custom_env);
    } else if (pid1 > 0) {
        // Parent
        waitpid(pid1, &status1, 0);

        pid2 = fork();
        if (pid2 == 0) {
            // Child 2
            printf("Running child process PID: %d\n", getpid());
            //! This only works if the executable is in $PATH. If not, change first argument to "./echoall"
            execlp("echoall", "echoall", "Spyro", NULL);
        } else if (pid2 > 0) {
            // Parent
            waitpid(pid2, &status2, 0);
        } else {
            perror("fork error");
            exit(1);
        }
    } else {
        perror("fork error");
        exit(1);
    }
    
}