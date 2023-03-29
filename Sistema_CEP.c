#include <stdio.h> //Biblioteca de Entrada/Sa�da (comunica��o com o usu�rio)
#include <stdlib.h> //Biblioteca de Aloca��o de Mem�ria
#include <locale.h> //Biblioteca de Aloca��o de Texto por Regi�o
#include <string.h> //Biblioteca Respons�vel pelas Strings
#include <wchar.h> //Biblioteca Respons�vel pelos Caracteres Especiais
#include <windows.h> //Biblioteca Respons�vel pelo Terminal do Windows

int registro(); //criando fun��o de registro de CEPs
int consulta(); //criando fun��o de consulta de CEPs
int excluir(); //criando fun��o de exclus�o de CEPs
int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    unsigned int cp = 1252; //garantindo que o prompt leia o alfabeto latino
    SetConsoleCP(cp);
    SetConsoleOutputCP(cp);
	
	int opcao = 0; //definindo as vari�veis
	int laco = 1;
	char senhadigitada[10] = "a";
	int comparacao = 0;
	
	printf("### Sistema de CEP ###\n\n");
	printf("Digite a senha para login de administrador: ");
	scanf("%s", senhadigitada);
	comparacao = strcmp(senhadigitada, "admin");
	
	
	if (comparacao == 0)
	{
	
		for (laco=1; laco=1;)
		{
			//in�cio do menu
		
			system("cls");
	
			printf("### Sistema de CEP ###\n\n");
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1) Registrar Novo CEP\n");
			printf("\t2) Consultar CEP\n");
			printf("\t3) Excluir CEP\n");
			printf("\t4) Sair do Sistema\n\n");
	
			printf("Op��o Selecionada: ");
	
			scanf("%d", &opcao);
	
			system("cls");
	
			//fim do menu
	
			switch (opcao) //acesso a outras fun��es
			{
				case 1:
					registro();
				break;
		
				case 2:
					consulta();
				break;
		
				case 3:
					excluir();
				break;
			
				case 4:
					printf("Obrigado por utilizar o sistema.\n");
					return 0;
				break;
		
				default:
					printf("Essa op��o n�o est� dispon�vel.\n");
					system("pause");
				break;
			}
		}
	}
	else
	{
		printf("\nSenha incorreta!\n\n");
		system("pause");
	}
}

int registro() //fun��o para cadastro de usu�rios
{
	inicioregistro:
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//cria��o de strings
	char arquivo[40];
	char cep[10];
	wchar_t cidade[40];
	wchar_t logradouro[40];
	char numero[40];
	int opcaoregistro = 0;
	
	printf("Digite o CEP a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cep);
	
	strcpy(arquivo, cep); //copiando valor da string pra uma vari�vel
	
	FILE *file; //criando arquivo do banco de dados
	file = fopen(strcat(arquivo,".txt"), "w"); //define nome do arquivo (e local) e cria na pasta
	fprintf(file, cep); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //acessando o arquivo
	fprintf(file, "\n"); //acrescentando uma v�rgula entre os par�metros
	fclose(file); //fechando o arquivo
	
	printf("Digite a Cidade correspondente: "); //coletando informa��o do usu�rio
	wscanf(L" %[^\n]ls", cidade);
	file = fopen(arquivo, "a"); 
	fwprintf(file, cidade); //salvando o valor da vari�vel
	fclose(file); 
	
	file = fopen(arquivo, "a"); //acessando o arquivo
	fprintf(file, "\n"); //acrescentando uma v�rgula entre os par�metros
	fclose(file); //fechando o arquivo
	
	printf("Digite o Logradouro correspondente: "); //coletando informa��o do usu�rio
	wscanf(L" %[^\n]ls", logradouro);
	
	file = fopen(arquivo, "a");
	fwprintf(file, logradouro); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //acessando o arquivo
	fprintf(file, "\n"); //acrescentando uma v�rgula entre os par�metros
	fclose(file); //fechando o arquivo
	
	printf("Digite o N�mero correspondente: "); //coletando informa��o do usu�rio
	scanf("%s", numero);
	
	file = fopen(arquivo, "a");
	fprintf(file, numero); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	printf("\nDeseja cadastrar mais CEPs?\n\n"); //Verificando se o usu�rio deseja cadastrar mais usu�rios
	printf("\t1) Cadastrar mais CEPs\n");
	printf("\t2) Voltar para o menu\n");
	scanf("%d", &opcaoregistro);
	switch (opcaoregistro) //acesso a outras fun��es
		{
			case 1:
				system("cls");
				goto inicioregistro;
			break;
		
			case 2:
			break;
		
			default:
				printf("Essa op��o n�o est� dispon�vel.\n");
				system("pause");
			break;
		}
}

int consulta()
{
	inicioconsulta:
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//cria��o de strings
	char cep[40];
	char conteudo[200];
	int opcaoconsulta = 0;
	
	printf("Digite o CEP a ser consultado: ");
	scanf("%s", cep);
	
	FILE *file;
	file = fopen(strcat(cep,".txt"),"r"); //acesso de leitura ao arquivo
	
	if (file == NULL)
	{
		printf("O CEP consultado n�o foi encontrado.\n");
	}
	int numerador = 0;
	while (fgets(conteudo, 200, file) != NULL) //recupera as informa��es do arquivo e transfere para o conte�do
	{
		numerador = numerador+1;
		if (numerador == 1)
		{
			printf("\nEssas s�o as informa��es do CEP: \n\n");
			printf("%s", conteudo);
		}
		if (numerador == 2)
		{
			printf("Cidade: ");
			printf("%s", conteudo);
		}
		if (numerador == 3)
		{
			printf("Logradouro: ");
			printf("%s", conteudo);
		}
		if (numerador == 4)
		{
			printf("N�mero: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
	
	fclose(file); //fechando o arquivo
	
	printf("\nDeseja consultar mais CEPs?\n\n"); //Verificando se o usu�rio deseja consultar mais usu�rios
	printf("\t1) Consultar mais CEPs\n");
	printf("\t2) Voltar para o menu\n");
	scanf("%d", &opcaoconsulta);
	switch (opcaoconsulta) //acesso a outras fun��es
		{
			case 1:
				system("cls");
				goto inicioconsulta;
			break;
		
			case 2:
			break;
		
			default:
				printf("Essa op��o n�o est� dispon�vel.\n");
				system("pause");
			break;
		}
	
	
}

int excluir()
{
	inicioexcluir:
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cep[40];
	int opcaoexcluir = 0;
	
	printf("Digite o CEP a ser exclu�do: ");
	scanf("%s", cep);
		
	FILE *file;
	file = fopen(strcat(cep,".txt"), "r");
	if (file == NULL)
	{
		printf("O CEP inserido n�o foi encontrado.\n");
	}
	else
	{
		fclose(file);
		remove(cep);
		printf("CEP deletado com sucesso.\n");
	}
	
	printf("\nDeseja excluir mais CEPs?\n\n"); //Verificando se o usu�rio deseja excluir mais usu�rios
	printf("\t1) Excluir mais CEPs\n");
	printf("\t2) Voltar para o menu\n");
	scanf("%d", &opcaoexcluir);
	switch (opcaoexcluir) //acesso a outras fun��es
		{
			case 1:
				system("cls");
				goto inicioexcluir;
			break;
		
			case 2:
			break;
		
			default:
				printf("Essa op��o n�o est� dispon�vel.\n");
				system("pause");
			break;
		}
	
}


