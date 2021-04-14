/*Programa Fatorial utilizando o fork()*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int turn;
    int fd[2];
    pid_t ipid;

    //Criacao do Pipe
    if (pipe(fd) < 0)
    {
        perror("pipe");
        return -1;
    }

    //Criacao do processo pai/filho
    ipid = fork();

    if (ipid == 1)
    {
        perror("fork");
        return -1;
    }

    if (ipid > 0)
    {
        int num[1];

        close(fd[0]);

        printf("Enter the number: ");
        scanf("%d", &num[0]);
        write(fd[1], num, sizeof(num));
        close(fd[1]);
    }
    else
    {
        int numero[1];
        close(fd[1]);
        // Lê a mensagem do pipe.
        read(fd[0], numero, sizeof(numero));
        int i; 
        int j=1;
        for (i = 1; i < numero[0]; i++)
        {
        j = j* i;
        printf("%d\n",j);
      
        };
    wait(NULL);
     printf("The factorial of %d is %d\n", numero[0], j);
    }
    return 0;
}