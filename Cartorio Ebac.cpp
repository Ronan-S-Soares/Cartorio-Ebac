#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() {
    char arquivo[50];  // Aumentei para 50 para acomodar "cpf.txt" mais espaços
    char cpf[40], nome[40], sobrenome[40], cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    sprintf(arquivo, "%s.txt", cpf);  // Concatenando ".txt" ao CPF
    
    FILE *file;
    file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;  // Indicativo de erro
    }
    
    fprintf(file, "%s", cpf);  // Gravando CPF no arquivo
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf(" %39[^\n]", nome);  // Lendo nome com espaços
    
    file = fopen(arquivo, "a");
    fprintf(file, ",%s", nome);
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf(" %39[^\n]", sobrenome);  // Lendo sobrenome com espaços
    
    file = fopen(arquivo, "a");
    fprintf(file, ",%s", sobrenome);
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf(" %39[^\n]", cargo);  // Lendo cargo com espaços
    
    file = fopen(arquivo, "a");
    fprintf(file, ",%s", cargo);
    fclose(file);
    
    printf("Cadastro realizado com sucesso.\n");
    system("pause");
    
    return 0;  // Indicativo de sucesso
}

int consultar() {
    char cpf[40], conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("Não foi possível localizar o CPF.\n");
        system("pause");
        return 1;  // Indicativo de erro
    }
    
    printf("Informações do usuário:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }
    
    fclose(file);
    system("pause");
    
    return 0;  // Indicativo de sucesso
}

int deletar() {
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso.\n");
    } else {
        printf("Erro ao deletar o usuário.\n");
    }
    
    system("pause");
    
    return 0;  // Indicativo de sucesso
}

int main() {
    int opcao;
    char senha[10];

    printf("Cartório da Ebac ###\n\n");
    printf("Login de administrador!\n\nDigite sua senha: ");
    scanf("%s", senha);

    if (strcmp(senha, "admin") == 0) {
        do {
            system("cls");
            setlocale(LC_ALL, "Portuguese");

            printf("Cartório da Ebac ###\n\n");
            printf("Escolha a opção desejada no menu:\n\n");
            printf("\t1 - Registrar Nomes\n");
            printf("\t2 - Consultar Nomes\n");
            printf("\t3 - Apagar Nomes\n");
            printf("\t4 - Sair do Sistema\n");
            printf("Opção: ");
            scanf("%d", &opcao);
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
                case 4:
                    printf("Obrigado por utilizar o sistema.\n");
                    return 0;
                default:
                    printf("Opção inválida. Tente novamente.\n");
                    break;
            }

            system("pause");
        } while (opcao != 4);
    } else {
        printf("Senha incorreta!\n");
    }

    return 0;
}
