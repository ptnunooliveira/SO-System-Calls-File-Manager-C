/** ***************************************************************
 * @file   funcoes.h
 * @brief  Declarações das funções auxiliares usadas no projeto.
 * 
 * Contém as assinaturas para funções de conversão de inteiro para string,
 * escrita em stdout e stderr, verificação de diretórios e cálculo do comprimento
 * de strings.
 * 
 * @authors
 *   - Aluno31029
 *   - Aluno31103
 *   - Aluno31550
 * 
 * @date   Abril 2025
 ******************************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

void myitoa(int numero, char *buf);

void mywrite(const char *s);

void myerror(char *s);

int is_dir(char *c);

int my_len (const char* s);