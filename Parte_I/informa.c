/** ***************************************************************
 * @file   informa.c
 * @brief  Apresenta informação sobre um ficheiro no sistema Linux.
 * @details Este programa recorre exclusivamente a chamadas de sistema
 *          para mostrar detalhes de um ficheiro, nomeadamente o tipo,
 *          número do i-node, identificador do utilizador proprietário (UID),
 *          e datas de criação, modificação e último acesso.
 *
 * @author Aluno31029, Aluno31103, Aluno31550
 * @date   Abril de 2025
 ****************************************************************/

#include "funcoes.h"


const char *nomes_meses[] = {
    "janeiro", "fevereiro", "março", "abril", "maio", "junho",
    "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
};

// Converte timestamp para data e escreve no formato "dd mês aaaa hh:mm:ss"
void escreve_data(long timestamp) {
    int dias_por_mes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    long dias = timestamp / 86400;
    int resto_seg = timestamp % 86400;

    // Determina o ano
    int ano = 1970;
    while (1) {
        int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        int dias_no_ano = bissexto ? 366 : 365;
        if (dias >= dias_no_ano) {
            dias -= dias_no_ano;
            ano++;
        } else break;
    }

    // Determina mês e dia
    int mes = 0;
    int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
    if (bissexto) dias_por_mes[1] = 29;

    while (dias >= dias_por_mes[mes]) {
        dias -= dias_por_mes[mes];
        mes++;
    }
    int dia = dias + 1;

    // Hora, minuto, segundo
    int hora = resto_seg / 3600;
    int minuto = (resto_seg % 3600) / 60;
    int segundo = resto_seg % 60;

    // Escreve data
    char buf[10];
    myitoa(dia, buf);
    mywrite(buf);
    mywrite(" ");
    mywrite(nomes_meses[mes]);
    mywrite(" ");
    myitoa(ano, buf);
    mywrite(buf);
    mywrite(" ");
    myitoa(hora, buf);
    mywrite(buf);
    mywrite(":");
    myitoa(minuto, buf);
    mywrite(buf);
    mywrite(":");
    myitoa(segundo, buf);
    mywrite(buf);
    mywrite("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        myerror("Utilização: ./informa <nome_ficheiro>\n");
        _exit(1);
    }

    const char *nome = argv[1];
    struct stat info;
    if (lstat(nome, &info) == -1) {
        myerror("Erro a aceder ao ficheiro.\n");
        _exit(1);
    }

    // Tipo de ficheiro
    const char *tipo = "Desconhecido\n";
    if (S_ISREG(info.st_mode))   tipo = "Ficheiro normal\n";
    else if (S_ISDIR(info.st_mode))   tipo = "Diretório\n";
    else if (S_ISLNK(info.st_mode))   tipo = "Link simbólico\n";
    else if (S_ISCHR(info.st_mode))   tipo = "Ficheiro especial (caractere)\n";
    else if (S_ISBLK(info.st_mode))   tipo = "Ficheiro especial (bloco)\n";
    else if (S_ISFIFO(info.st_mode))  tipo = "FIFO (pipe)\n";
    else if (S_ISSOCK(info.st_mode))  tipo = "Socket\n";

    mywrite("Tipo: ");
    mywrite(tipo);

    // i-node
    mywrite("i-node: ");
    char buf[20];
    myitoa((int) info.st_ino, buf);
    mywrite(buf);
    mywrite("\n");

    // UID
    mywrite("Dono (UID): ");
    myitoa((int) info.st_uid, buf);
    mywrite(buf);
    mywrite("\n");

    // Datas
    mywrite("Criação: ");
    escreve_data(info.st_ctime);
    mywrite("Último acesso: ");
    escreve_data(info.st_atime);
    mywrite("Última modificação: ");
    escreve_data(info.st_mtime);
    _exit(0);
}
