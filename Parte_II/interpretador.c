/** ***************************************************************
 * @file   interpretador.c
 * @brief  Interpretador de comandos simples em batch para Linux
 * @details
 * Programa que lê comandos da linha de comandos, cria processos
 * filhos para executar cada comando usando execvp, e permite
 * terminar a execução com o comando "termina".
 * 
 * Funcionalidades principais:
 *  - Leitura de comandos da entrada standard
 *  - Execução sequencial dos comandos
 *  - Suporte ao comando "termina" para saída do programa
 *  - Apresentação do prompt "%"
 * 
 * @author Aluno31029, Aluno31103, Aluno31550
 * @date   Abril 2025
 ****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char buffer[100];

    while (1) { //ciclo infinito
        // Mostra o símbolo %
        printf("%% ");
        
        // Le do stdin
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break; // EOF (Ctrl+D)
        }

        // Remove o '\n' do fim da linha
        buffer[strcspn(buffer, "\n")] = '\0';

        // Sai se for "termina"
        if (strcasecmp(buffer, "termina") == 0) {
            break;
        }

        // Divide a linha em argumentos
        char *args[10];
        int i = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL && i < 10 - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Cria processo filho
        int pid = fork();

        if (pid == 0) {// Processo filho: executa comando
            execvp(args[0], args);
            perror("Erro ao executar comando"); //executa printf + erro
            exit(1); // termina o filho se execvp falhar
        } else if (pid > 0) { // Processo pai: espera pelo filho
            wait(NULL);
            printf("Comando terminado.\n");
        } else {
            perror("Erro ao criar processo"); //se der erro no fork
        }
    }

    printf("Terminado.\n");
    return 0;
}
