/** ***************************************************************
 * @file   conta.c
 * @brief  Conta o número de linhas de um ficheiro
 * @details Utiliza chamadas de sistema para ler um ficheiro linha a linha
 *          e contabiliza o número total de quebras de linha ('\n').
 *
 * @authors
 *   - Aluno31029  
 *   - Aluno31103  
 *   - Aluno31550
 *
 * @date   Abril 2025
 ******************************************************************/

#include "funcoes.h"

int main (int argc, char* argv[]){

    int fd1;
    int linhas = 0, len=0;
    char buffer[100];
    ssize_t bytes_read; //guarda tamanho do buffer lido. -1 se erro

    //verificar se for escrito algum nome de ficheiros
    if (argc == 1){ 
        myerror("Falta nome do ficheiro\n");
        exit(1);
    }

    if (argc > 2){ 
        myerror("Argumentos a mais \n");
        exit(2);
    }

    //Calcular o tamanho do nome do ficheiro
    len = my_len(argv[1]);

    //abrir ficheiro para leitura
    fd1 = open(argv[1], O_RDONLY);

    //testar se o ficheiro existe
    if (fd1 == -1) {
        myerror("Ficheiro ");
        myerror(argv[1]);
        myerror(" nao existe\n");
        exit(3);
    }

    // carregar conteudo do ficheiro para o buffer
    while((bytes_read = read(fd1, buffer, sizeof(buffer))) > 0){
        write(fd1, buffer, bytes_read);

        for(int i=0; i<bytes_read; i++){
            if(buffer[i] == '\n'){
                linhas++;
            }
        }
    }

    close (fd1);

    //converter o numero de linhas para string
    char stringlinhas[10];
    myitoa(linhas, stringlinhas);


    //escrever o numero de linhas
    mywrite("Numero de linhas: ");  
    mywrite(stringlinhas);
    mywrite("\n");
    return 0;

}