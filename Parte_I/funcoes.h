/** ***************************************************************
 * @file   funcoes.h
 * @brief  Cabeçalho com declarações de funções auxiliares
 * @details Declaração de funções utilitárias que substituem funcionalidades
 *          básicas da biblioteca padrão, recorrendo apenas a chamadas de sistema.
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