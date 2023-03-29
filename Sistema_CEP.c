#include <stdio.h> //Biblioteca de Entrada/Saída (comunicação com o usuário)
#include <stdlib.h> //Biblioteca de Alocação de Memória
#include <locale.h> //Biblioteca de Alocação de Texto por Região
#include <string.h> //Biblioteca Responsável pelas Strings
#include <wchar.h> //Biblioteca Responsável pelos Caracteres Especiais
#include <windows.h> //Biblioteca Responsável pelo Terminal do Windows

int registro(); //criando função de registro de CEPs
int consulta(); //criando função de consulta de CEPs
int excluir(); //criando função de exclusão de CEPs
int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    unsigned int cp = 1252; //garantindo que o prompt leia o alfabeto latino
    SetConsoleCP(cp);
    SetConsoleOutputCP(cp);
	
	int opcao = 0; //definindo as variáveis
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
			//início do menu
		
			system("cls");
	
			printf("### Sistema de CEP ###\n\n");
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1) Registrar Novo CEP\n");
			printf("\t2) Consultar CEP\n");
			printf("\t3) Excluir CEP\n");
			printf("\t4) Sair do Sistema\n\n");
	
			printf("Opção Selecionada: ");
	
			scanf("%d", &opcao);
	
			system("cls");
	
			//fim do menu
	
			switch (opcao) //acesso a outras funções
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
					printf("Essa opção não está disponível.\n");
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

int registro() //função para cadastro de usuários
{
	inicioregistro:
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//criação de strings
	char arquivo[40];
	char cep[10];
	wchar_t cidade[40];
	wchar_t logradouro[40];
	char numero[40];
	int opcaoregistro = 0;
	
	printf("Digite o CEP a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cep);
	
	strcpy(arquivo, cep); //copiando valor da string pra uma variável
	
	FILE *file; //criando arquivo do banco de dados
	file = fopen(strcat(arquivo,".txt"), "w"); //define nome do arquivo (e local) e cria na pasta
	fprintf(file, cep); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //acessando o arquivo
	fprintf(file, "\n"); //acrescentando uma vírgula entre os parâmetros
	fclose(file); //fechando o arquivo
	
	printf("Digite a Cidade correspondente: "); //coletando informação do usuário
	wscanf(L" %[^\n]ls", cidade);
	file = fopen(arquivo, "a"); 
	fwprintf(file, cidade); //salvando o valor da variável
	fclose(file); 
	
	file = fopen(arquivo, "a"); //acessando o arquivo
	fprintf(file, "\n"); //acrescentando uma vírgula entre os parâmetros
	fclose(file); //fechando o arquivo
	
	printf("Digite o Logradouro correspondente: "); //coletando informação do usuário
	wscanf(L" %[^\n]ls", logradouro);
	
	file = fopen(arquivo, "a");
	fwprintf(file, logradouro); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //acessando o arquivo
	fprintf(file, "\n"); //acrescentando uma vírgula entre os parâmetros
	fclose(file); //fechando o arquivo
	
	printf("Digite o Número correspondente: "); //coletando informação do usuário
	scanf("%s", numero);
	
	file = fopen(arquivo, "a");
	fprintf(file, numero); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	printf("\nDeseja cadastrar mais CEPs?\n\n"); //Verificando se o usuário deseja cadastrar mais usuários
	printf("\t1) Cadastrar mais CEPs\n");
	printf("\t2) Voltar para o menu\n");
	scanf("%d", &opcaoregistro);
	switch (opcaoregistro) //acesso a outras funções
		{
			case 1:
				system("cls");
				goto inicioregistro;
			break;
		
			case 2:
			break;
		
			default:
				printf("Essa opção não está disponível.\n");
				system("pause");
			break;
		}
}

int consulta()
{
	inicioconsulta:
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//criação de strings
	char cep[40];
	char conteudo[200];
	int opcaoconsulta = 0;
	
	printf("Digite o CEP a ser consultado: ");
	scanf("%s", cep);
	
	FILE *file;
	file = fopen(strcat(cep,".txt"),"r"); //acesso de leitura ao arquivo
	
	if (file == NULL)
	{
		printf("O CEP consultado não foi encontrado.\n");
	}
	int numerador = 0;
	while (fgets(conteudo, 200, file) != NULL) //recupera as informações do arquivo e transfere para o conteúdo
	{
		numerador = numerador+1;
		if (numerador == 1)
		{
			printf("\nEssas são as informações do CEP: \n\n");
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
			printf("Número: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
	
	fclose(file); //fechando o arquivo
	
	printf("\nDeseja consultar mais CEPs?\n\n"); //Verificando se o usuário deseja consultar mais usuários
	printf("\t1) Consultar mais CEPs\n");
	printf("\t2) Voltar para o menu\n");
	scanf("%d", &opcaoconsulta);
	switch (opcaoconsulta) //acesso a outras funções
		{
			case 1:
				system("cls");
				goto inicioconsulta;
			break;
		
			case 2:
			break;
		
			default:
				printf("Essa opção não está disponível.\n");
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
	
	printf("Digite o CEP a ser excluído: ");
	scanf("%s", cep);
		
	FILE *file;
	file = fopen(strcat(cep,".txt"), "r");
	if (file == NULL)
	{
		printf("O CEP inserido não foi encontrado.\n");
	}
	else
	{
		fclose(file);
		remove(cep);
		printf("CEP deletado com sucesso.\n");
	}
	
	printf("\nDeseja excluir mais CEPs?\n\n"); //Verificando se o usuário deseja excluir mais usuários
	printf("\t1) Excluir mais CEPs\n");
	printf("\t2) Voltar para o menu\n");
	scanf("%d", &opcaoexcluir);
	switch (opcaoexcluir) //acesso a outras funções
		{
			case 1:
				system("cls");
				goto inicioexcluir;
			break;
		
			case 2:
			break;
		
			default:
				printf("Essa opção não está disponível.\n");
				system("pause");
			break;
		}
	
}


