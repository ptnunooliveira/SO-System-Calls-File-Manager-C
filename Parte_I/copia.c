/** ***************************************************************
 * @file   copia.c
 * @brief  Criação de uma cópia de um ficheiro em Linux
 * @details Lê o conteúdo de um ficheiro e escreve-o num novo ficheiro,
 *          cujo nome é o original acrescido do sufixo ".copia".
 *          Utiliza exclusivamente chamadas de sistema.
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

    int fd1, fd2;
    char buffer[2000];
    char nomefinal[30];
    char sufixo[] = ".copia";
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

    //abrir ficheiro para leitura
    fd1 = open(argv[1], O_RDONLY);
    //testar se o ficheiro existe
    if (fd1 == -1) {
        myerror("Ficheiro ");
        myerror(argv[1]);
        myerror(" nao existe.\n");
        exit(1);
    }

    // carregar conteudo do ficheiro para o buffer
    bytes_read = read(fd1, buffer, sizeof(buffer));
    close (fd1);
	
    // adicionar o sufixo ".copia" ao nome original
    int i = 0;
    for(i=0; argv[1][i] != '\0'; i++){
        nomefinal[i] = argv[1][i];
    }

    for(int j=0; sufixo[j] != '\0'; j++, i++){
        nomefinal[i] = sufixo[j];
    }

    nomefinal[i] = '\0';
    
    // abrir ficheiro para escrita
    fd2 = open(nomefinal, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write (fd2, buffer, bytes_read);
    close (fd2);
    return 0;

}
