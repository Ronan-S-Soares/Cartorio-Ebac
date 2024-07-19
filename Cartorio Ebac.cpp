#include <stdio.h> //definindo linguagem
#include <stdlib.h> // biblioteca de alocação de espço em memoria
#include <locale.h> // biblioteca de alocação de texto por regiao
#include <string.h> // biblioteca responsavel pela string
int registro()
{
	char arquivo[40];// Variável para armazenar o nome do arquivo
	char cpf[40];// Variável para armazenar o CPF do usuário
	char nome[40];// Variável para armazenar o nome do usuário
	char sobrenome[40];// Variável para armazenar o sobrenome do usuário
	char cargo[40];// Variável para armazenar o cargo do usuário
	
	printf("Digite o CPF a ser cadastrado: "); // Solicita ao usuário o CPF a ser cadastrado
	scanf("%s,", cpf);// Lê o CPF do usuário e armazena na variável `cpf`
	
	strcpy(arquivo, cpf);//responsavel por copiar o valor das string
	
	FILE *file;
	file = fopen(arquivo, "w");// Abre o arquivo no modo de escrita ("w")
	fprintf(file,cpf);//salvo o valor da variavek
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");// Abre o arquivo no modo de adição ("a")
	fprintf(file,",");// Grava uma vírgula no arquivo para separar os campos
	fclose(file);// Fecha o arquivo após gravar a vírgula
	
	printf("Digite o nome a ser cadastrado: ");// Solicita ao usuário o nome a ser cadastrado
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");// Abre o arquivo no modo de adição ("a") novamente
	fprintf(file, nome);// Grava o nome do usuário no arquivo
	fclose(file);// Fecha o arquivo após gravar o nome
	
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
// Função para consultar um nome
int consultar()
{
char cpf[40];// Variável para armazenar o CPF do usuário
char conteudo[200];// Variável para armazenar o conteúdo do arquivo

 
 printf("digite o o cpf a ser consultado..");// Solicita ao usuário o CPF a ser consultado
 scanf("%s",cpf);// Lê o CPF do usuário e armazena na variável `cpf`
 
 FILE *file;
 file = fopen(cpf,"r");
 
 if(file == NULL)
 {
 	printf("Não foi possivel Localizar o CPF. \n ");
 }

while(fgets(conteudo, 200, file)!= NULL)
{
	printf("\nEssas são as informações do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}

	system ("pause");



}


int deletar()
{
char cpf[40];

printf("Digite o Cpf do usuário a ser Deletado:  ");
scanf("%s",cpf);

 remove(cpf);
 
 FILE *file;
 file = fopen(cpf,"r");
 
 if(file == NULL)
 {
 	printf("o Usuário não se encontra no sistema.\n");
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

	printf("Cartório da Ebac ###\n\n"); // menu
	printf("Escolha a opção desejada no menu: \n\n");
	printf ("\t1 - Registrar Nomes\n");
	printf ("\t2 - Consultar Nomes\n");
	printf ("\t3 - Apagar Nomes\n");
	 printf("Opção:  ");

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
    printf("Opção inválida. Tente novamente.\n");
    system("pause");

  }	
  
  
}


}

