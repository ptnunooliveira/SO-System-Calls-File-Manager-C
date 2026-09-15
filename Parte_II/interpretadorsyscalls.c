/** ***************************************************************
 * @file   interpretador.c
 * @brief  Interpretador simples em batch para Linux
 * @details
 * Programa que lê comandos do terminal, executa-os criando
 * processos filhos, e permite terminar com o comando "termina".
 *
 * Utiliza funções auxiliares definidas em "funcoes.h" para escrita,
 * leitura e manipulação de strings.
 *
 * O interpretador:
 *  - apresenta um prompt '%'
 *  - lê uma linha do stdin
 *  - separa os argumentos pelo espaço
 *  - cria um processo filho para executar o comando
 *  - espera pelo término do comando
 *  - termina ao receber o comando "termina"
 * 
 * @author Aluno31029, Aluno31103, Aluno31550
 * @date   Abril de 2025
 ****************************************************************/

 #include "funcoes.h"

 int main (){

    // Ciclo infinito para o interpretador
    while(1){
        mywrite ("\n% ");
       
        char buffer[100];
        int aux = -1, pid = -1;

        buffer[0] = '\0';
        buffer[1] = '\0';
    
        aux = read (0, buffer, sizeof(buffer));

        // Tirar o '\n' do buffer e colocar o '\0' para nao apanhar lixo
        buffer[aux-1] = '\0';

        // Verificar se é para terminar
        char termina[] = "termina";
        int len = my_len(buffer);
        int contador = 0;
        for(int j = 0; j < len; j++){
            if(buffer[j] == termina[j]){
            contador++;
                if(contador == 7 && len == 7){
                    return 0;
            }
        }
    }

        pid = fork();
        if (pid != 0) { //pai
            wait(NULL);
            continue;
        }   
    
#pragma region SEPARAR ARRAY

    char* argumentos[10];
    int arg = 0;
    int i = 0;

    argumentos[arg++] = &buffer[i];

    while(buffer[i] != '\0'){
        if(buffer[i] == ' '){
            buffer[i] = '\0';
            argumentos[arg++] = &buffer[i+1];
        }
        i++;
    }

    argumentos[arg] = NULL;
  


#pragma endregion
    
    execvp(argumentos[0], argumentos);
    
    
    mywrite("Erro.\n");

    }
 }