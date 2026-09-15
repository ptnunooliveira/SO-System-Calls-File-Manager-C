/** ***************************************************************
 * @file   apaga.c
 * @brief  Programa que elimina um ficheiro em Linux
 * @details Utiliza exclusivamente chamadas de sistema. Solicita ao utilizador
 *          confirmação antes de eliminar o ficheiro indicado por argumento.
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
    int len=0;
    //char buffer[100];
    //ssize_t bytes_read; //guarda tamanho do buffer lido. -1 se erro

    //verificar se foi escrito o nome do ficheiro, ou nomes a mais
    if (argc == 1){ 
        myerror("Falta nome do ficheiro.\n");
        exit(1);
     }
    if (argc > 2){ 
        myerror("Argumentos a mais.\n");
        exit(2); //exit(1) termina o programa com erro
    }

    //Calcular o tamanho do nome do ficheiro
    len = my_len(argv[1]);

    // confirmação que quer mesmo apagar
    char c[1]; // ler S ou N

    mywrite("Confirma a eliminação do ficheiro \n");
    mywrite(argv[1]);
    mywrite(" ? (S/N):\n");

    read(0, c, 1); //resposta do utilizador (S ou s

    char lixo;
    while (read(0, &lixo, 1) == 1  && lixo != '\n'); //limpar o resto do buffer

    if (c[0] != 'S' && c[0] != 's'){
        mywrite("Eliminação cancelada.\n");
        exit(3); 
    }

    // verificar se existe e apagar o ficheiro
    fd1 = open(argv[1], O_RDONLY); //abre o ficheiro para leitura
    if (fd1 == -1){ //se o ficheiro nao existe
        myerror("Ficheiro nao existe\n"); 
        exit(4);
    }

    //se o ficheiro existe, apaga-o
    if (unlink(argv[1]) == -1){ //unlink apaga o ficheiro
        myerror("Erro ao apagar o ficheiro\n");
        exit(1); //termina com erro (1) se não conseguir apagar o ficheiro ou for uma pasta
    }

    //se chegou aqui o ficheiro foi apagado com sucesso
    mywrite("Ficheiro ");
    mywrite(argv[1]); //escreve o nome do ficheiro apagado
    mywrite(" apagado com sucesso.\n"); 
    
    close(fd1); //fecha o ficheiro

    return 0;
}
