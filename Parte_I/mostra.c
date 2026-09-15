/** ***************************************************************
 * @file   mostra.c
 * @brief  Mostra o conteúdo de ficheiros em Linux
 * @details Este programa exibe no ecrã o conteúdo de um ou mais ficheiros
 *          de texto, utilizando apenas chamadas de sistema.
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
	int fd;
	char buffer[100];
	ssize_t bytes_read; //guarda tamanho do buffer lido. -1 se erro

	//verificar se for escrito algum nome de ficheiros 
	if (argc < 2){ 
		myerror("Nome ficheiro em falta.\n");
		exit(1);
	 }

	for (int i = 1; i < argc; i++){

	//abrir ficheiro para leitura
	fd = open(argv[i], O_RDONLY);

	//testar se o ficheiro existe 
	if (fd == -1) {
		myerror("Ficheiro ");
		myerror(argv[i]);
		myerror(" nao existe.\n");
		continue;	}
	
	//ler ficheiro e enviar para ecra
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
	//	bytes_read= read(fd, buffer, sizeof(buffer));
		write(1, buffer, bytes_read);
	}	
	
	close(fd);
	}

	return 0;
}
