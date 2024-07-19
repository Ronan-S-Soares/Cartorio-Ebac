#include <stdio.h> //definindo linguagem
#include <stdlib.h> // biblioteca de aloca��o de esp�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regiao
#include <string.h> // biblioteca responsavel pela string
int registro()
{
	char arquivo[40];// Vari�vel para armazenar o nome do arquivo
	char cpf[40];// Vari�vel para armazenar o CPF do usu�rio
	char nome[40];// Vari�vel para armazenar o nome do usu�rio
	char sobrenome[40];// Vari�vel para armazenar o sobrenome do usu�rio
	char cargo[40];// Vari�vel para armazenar o cargo do usu�rio
	
	printf("Digite o CPF a ser cadastrado: "); // Solicita ao usu�rio o CPF a ser cadastrado
	scanf("%s,", cpf);// L� o CPF do usu�rio e armazena na vari�vel `cpf`
	
	strcpy(arquivo, cpf);//responsavel por copiar o valor das string
	
	FILE *file;
	file = fopen(arquivo, "w");// Abre o arquivo no modo de escrita ("w")
	fprintf(file,cpf);//salvo o valor da variavek
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");// Abre o arquivo no modo de adi��o ("a")
	fprintf(file,",");// Grava uma v�rgula no arquivo para separar os campos
	fclose(file);// Fecha o arquivo ap�s gravar a v�rgula
	
	printf("Digite o nome a ser cadastrado: ");// Solicita ao usu�rio o nome a ser cadastrado
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");// Abre o arquivo no modo de adi��o ("a") novamente
	fprintf(file, nome);// Grava o nome do usu�rio no arquivo
	fclose(file);// Fecha o arquivo ap�s gravar o nome
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s,", sobrenome);
	
	file= fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite  o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
		
}
// Fun��o para consultar um nome
int consultar()
{
char cpf[40];// Vari�vel para armazenar o CPF do usu�rio
char conteudo[200];// Vari�vel para armazenar o conte�do do arquivo

 
 printf("digite o o cpf a ser consultado..");// Solicita ao usu�rio o CPF a ser consultado
 scanf("%s",cpf);// L� o CPF do usu�rio e armazena na vari�vel `cpf`
 
 FILE *file;
 file = fopen(cpf,"r");
 
 if(file == NULL)
 {
 	printf("N�o foi possivel Localizar o CPF. \n ");
 }

while(fgets(conteudo, 200, file)!= NULL)
{
	printf("\nEssas s�o as informa��es do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}

	system ("pause");



}


int deletar()
{
char cpf[40];

printf("Digite o Cpf do usu�rio a ser Deletado:  ");
scanf("%s",cpf);

 remove(cpf);
 
 FILE *file;
 file = fopen(cpf,"r");
 
 if(file == NULL)
 {
 	printf("o Usu�rio n�o se encontra no sistema.\n");
 	system("pause");
 }
 
}





int main () {
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco==1;)
	{	
	
	
	system("cls");

	setlocale(LC_ALL, "Portuguese");

	printf("Cart�rio da Ebac ###\n\n"); // menu
	printf("Escolha a op��o desejada no menu: \n\n");
	printf ("\t1 - Registrar Nomes\n");
	printf ("\t2 - Consultar Nomes\n");
	printf ("\t3 - Apagar Nomes\n");
	 printf("Op��o:  ");

	scanf ("%d", &opcao);

	system("cls");
	
switch (opcao) {

   case 1:
   registro();
    break;

   case 2:
    consultar();
    break;

   case 3:
    deletar();
    break;
    
   default:
    printf("Op��o inv�lida. Tente novamente.\n");
    system("pause");

  }	
  
  
}


}

