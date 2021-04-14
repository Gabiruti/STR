#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <string.h>
#define BUFFER 256

int
   main(void)
   {
       char mensagem[BUFFER];
       int fd[2];
       pid_t ipid;

       //Criacao do pipe
       if(pipe(fd)<0){
           perror("pipe");
           return -1;
       }

       //Criacao do processo pai/filho
       ipid = fork();

       if(ipid == 1){
           perror("fork");
           return -1;
       }

       //processo filho
       if(ipid > 0){
           char *msg = "Isso e uma mensagem";
        
        //fechar a leitura do pipe
            close(fd[0]);

        //Escrever a mensagem
            write(fd[1], msg, strlen(msg)+1);

            close(fd[1]);
            printf("\nMensagem Enviada pelo filho: %s\n\n",msg);
       } else//processo pai
       { 
        //fechar a escrita do pipe
            close(fd[1]);

        // Lê a mensagem do pipe.
        read(fd[0], mensagem, sizeof mensagem) ;

        printf("\nMensagem recebida: %s\n", mensagem) ;

        close(fd[0]) ;

        wait(NULL);
    }
         
        return 0;
   }
