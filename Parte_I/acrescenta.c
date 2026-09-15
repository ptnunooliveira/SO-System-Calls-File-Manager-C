/** ***************************************************************
* @file   acrescenta.c
* @brief  Programa que lê o conteúdo de um ficheiro e acrescenta-o ao final de outro ficheiro.
* 
* O programa recebe dois argumentos na linha de comando: o nome do ficheiro de origem e o nome do ficheiro de destino.
* O conteúdo do ficheiro de origem é lido e, de forma sequencial, é adicionado ao final do ficheiro de destino.
* Caso algum dos argumentos falte ou seja inválido, o programa mostra mensagens de erro.
*
* @author $Aluno31029, $Aluno31103, $Aluno31550
* @date   Abril 2025
****************************************************************/


#include "funcoes.h"

int main(int argc, char *argv[]){

    int fd1, fd2;
    int len1 = 0, len2 = 0;
    ssize_t bytes_read;
    char buffer[5];

    if(argc == 1 || argc == 2){
        myerror("Falta argumentos.\n");
        exit(1);
    }

    if(argc > 3){
        myerror("Demasiados argumentos.\n");
        exit(2);
    }
    //Calcular o tamanho do nome do primeiro ficheiro
    len1 = my_len(argv[1]);

    //Calcular o tamanho do nome do segundo ficheiro
    len2 = my_len(argv[2]);

    fd1 = open(argv[1], O_RDONLY);
    
    if(fd1 == -1){
        myerror("Ficheiro ");
        myerror(argv[1]);
        myerror(" nao existe.\n");
        exit(3);
    }

    fd2 = open(argv[2], O_WRONLY | O_APPEND);

    if(fd2 == -1){
        myerror("Ficheiro ");
        myerror(argv[2]);
        myerror(" nao existe.\n");
        exit(4);
    }

    while((bytes_read = read(fd1, buffer, sizeof(buffer))) > 0){
        write(fd2, buffer, bytes_read);
    }

    close(fd1);
    close(fd2);

    return 0;
}
