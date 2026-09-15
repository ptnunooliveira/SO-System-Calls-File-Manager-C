/** ***************************************************************
 * @file   lista.c
 * @brief  Lista o conteúdo de um diretório
 * @details Lista todos os ficheiros e subdiretórios contidos no caminho indicado,
 *          identificando cada entrada como ficheiro ou diretório. Se não for
 *          especificado nenhum caminho, lista o diretório atual.
 *
 * @authors
 *   - Aluno31029  
 *   - Aluno31103  
 *   - Aluno31550
 *
 * @date   Abril 2025
 ******************************************************************/

#include "funcoes.h"

int main(int argc, char* argv[]){

    char *caminho = ".";

    // Se houver mais do que um caminho
    if(argc > 2){
        myerror("Demasiados argumentos.");
    }

    // Se houver um caminho especifico
    if(argc > 1){
        caminho = argv[1];
    }
    
    // Cria uma variavel tipo DIR e abre o diretorio
    DIR *diretorio = opendir(caminho);

    if(diretorio == NULL){
        myerror("O diretorio nao existe.\n");
        return 0;
    }

    // Cria uma variavel tipo dirent
    struct dirent *entrada;

    char caminhoabsoluto[500];

    while((entrada = readdir(diretorio)) != NULL){

        // Para ignorar o "." e o ".."
        if((entrada->d_name[0] == '.' && entrada->d_name[1] == '\0') || (entrada->d_name[0] == '.' && entrada->d_name[1] == '.' && entrada->d_name[2] == '\0'))
            continue;     

        int i = 0, j = 0;

        // Copiar o caminho para caminhoabsoluto
        while(caminho[i] != '\0'){
            caminhoabsoluto[i] = caminho[i];
            i++;
        }

        // Adicionar a '/' no final do caminho absoluto
        if(caminhoabsoluto[i-1] != '/')
            caminhoabsoluto[i++] = '/';

        // Adicionar o nome do diretorio ou ficheiro ao caminho absoluto
        while(entrada->d_name[j] != '\0')
            caminhoabsoluto[i++] = entrada->d_name[j++];
        caminhoabsoluto[i] = '\0';
        
        // Se for diretorio...
        if(is_dir(caminhoabsoluto)){
            mywrite("[DIR]" );
            mywrite(entrada->d_name);
            mywrite("\n");
        }
        // Se for ficheiro...
        else {
            mywrite("[FILE]");
            mywrite(entrada->d_name);
            mywrite("\n");
        }
    }

    closedir(diretorio);
    return 0;
}