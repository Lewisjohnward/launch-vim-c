#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
    pid_t pid;
    int w = 0;
    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
    {
        wait(&w);
    }
    if (pid == 0)
    {
        char *args[] = {"vim", "test_file.txt", NULL};
        execvp(args[0], args);
    }
    return 0;
}
