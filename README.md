# STR

Exercício 1:
Código básico em C.

Exercício 2:
Comunicação entre as tarefas usando pipe, o trecho:

if(pipe(fd)<0){
perror("pipe");
return -1;
}


cria o pipe e as funções write() e read() são usadas para escrever e retornar a mensagem.

Exercício 3:
A variável N é compartilhada com o Children.

Exercício 4:
O arquivo exercíciopc é o exemplo multiprocessado usando fork() e o exercíciopc1 é o exemplo utilizando o clone().
