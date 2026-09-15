/** ***************************************************************
 * @file   funcoes.c
 * @brief  Implementação de funções auxiliares para operações com strings,
 *         escrita no terminal e verificação de ficheiros
 * @details Este ficheiro contém implementações de funções utilitárias que 
 *          substituem funções da biblioteca padrão, usando apenas chamadas de sistema.
 * 
 * @authors
 *   - Aluno31029  
 *   - Aluno31103  
 *   - Aluno31550
 *
 * @date   Abril 2025
 ******************************************************************/

#include "funcoes.h"

void myitoa(int numero, char *buf){
    
    char temp[10];
    char tmp;
    int i = 0, j = 0;

    if(numero == 0){
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }

    for(i = 0; numero > 0; i++){
        temp[i] = '0' + (numero % 10);
        numero = numero / 10;
    }

    i--;

    for(j = 0; i >= 0;j++, i--){
        buf[j] = temp[i];
    }

    buf[j] = '\0';
}

void mywrite(const char *s){
    int len = 0;
    while(s[len])
        len++;
    write(1, s, len);
}

void myerror(char *s){
    int len = 0;
    while(s[len])
        len++;
    write(2, s, len);
}

int is_dir(char *c){
    struct stat st;
    if(stat(c, &st) == -1)
        return 0;
    return S_ISDIR(st.st_mode);
}

int my_len (const char* s){
    int len =0;
    while(s[len] != '\0'){
        len++;}
return len;
}


