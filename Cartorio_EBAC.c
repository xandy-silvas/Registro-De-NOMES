#include <stdio.h>
#include <stdlib.h> //aloca��o de espa�o na memoria 
#include <locale.h> //Biblioteca para saber localiza��o de texto 
#include <string.h> //Biblioteca responsavel para utilizar strings no codigo

int registro(){
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	//colocando o cpf no arquivo
	printf("Digite o CPF para cadastar: ");
	scanf("%s", &cpf);
	
	strcpy(arquivo, cpf); //strcpy copia os valores de string
	
	FILE *file; //cria o arquino
	file = fopen(arquivo, "w");
	fprintf(file, cpf); //salva valor da variavel no arquivo
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//colocando o nome no arquivo 
	printf("Digite o Nome: ");
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//colocando o sobrenome no arquivo
	printf("Digite o Sobrenome: ");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//colocando o cargo no arquivo 
	printf("Digite o Cargo: ");
	scanf("%s", &cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
}



//consultano o nome no banco de dados
int consulta(){
	
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF que gostaria de consultar: ");
	scanf("%s", &cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if(file == NULL){
		printf ("\nN�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL){
		printf("Essas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar(){
	char cpf[40];
	
	printf("Digite o ID a ser deletado: ");
	scanf("%f", cpf);
	
	//comando para apagar algo ddo arquivo
	remove (cpf);
	
	//veerficando se ID esta no sistema
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf ("\nN�o foi possivel encontrar usuario no sistema!\n");
		system("pause");
	}
	
}


int main(){
	int opcao = 0;
	int x = 1;
	char senhadigitada[10]="a";
	int compare;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a senha\n\n");
	scanf ("%s", &senhadigitada);
	
	compare = strcmp (senhadigitada, "admin");
	
	if(compare == 0){
	
		for(x = 1; x=1;){
			system("cls");
		
			setlocale(LC_ALL, "Portuguese");
	
			printf("### Cart�rio da EBAC ###\n\n");
			printf("Selecione a op��o deesejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n"); //  \t � para dar espa�o na frente da frase no printf
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("Op��o: ");
	
			scanf("%d", &opcao);
	
			system ("cls"); //ele limpa a tela apos alguma a��o do usuario
		
			switch(opcao){
				case 1:
					registro();
				break;
			
				case 2:
					consulta();
				break;
			
				case 3:
					deletar();
				break;
			
				default:
					printf("### Nenhuma Op��o Valida! ###\n\n");
					system("pause");
				break;
			}
		}
	}
	
	else {
		printf("Senha Incorreta!");
	}
	
	
	return 0;
}

