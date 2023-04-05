import os

def menuprincipal():

    def registro():
        while True:
            arquivo = ""
            cep = 0
            cidade = ""
            logradouro = ""
            numero = ""
            opcaoregistro = 0;
            print("Digite o CEP a ser cadastrado: ")
            cep = input()
            print("Digite a Cidade correspondente: ")
            cidade = input()
            print("Digite o Logradouro correspondente: ")
            logradouro = input()
            print("Digite o Número correspondente: ")
            numero = input()

            arquivo = str(cep)

            with open(arquivo+'.txt','w') as f:
                f.write(cep+"\n"+cidade+"\n"+logradouro+"\n"+numero)
	
            print("\nDeseja cadastrar mais CEPs?\n")
            print("\t1) Cadastrar mais CEPs")
            print("\t2) Voltar para o menu")
            opcaoregistro = int(input())
            if (opcaoregistro != 1 and opcaoregistro != 2):
                print('Essa opção não está disponível!\n\n')
                print("\nDeseja cadastrar mais CEPs?\n")
                print("\t1) Cadastrar mais CEPs")
                print("\t2) Voltar para o menu")
            elif opcaoregistro == 1:
                os.system('cls')
                print('Vamos cadastrar mais CEPs!')
            elif opcaoregistro == 2:
                break

    def consulta():
        while True:
            cep = 0;
            conteudo = ""
            opcaoconsulta = 0
            print("Digite o CEP a ser consultado: ");
            cep = input()
	
            arquivo = str(cep)
            f = 0
            try:
                f = open(arquivo+'.txt','r')
                line1 = f.readline()
                line2 = f.readline()
                line3 = f.readline()
                line4 = f.readline()
                f.close()
                print('\nCEP: '+line1)
                print('Cidade: '+line2)
                print('Logradouro: '+line3)
                print('Número: '+line4)
            except:
                print('O CEP consultado não foi encontrado.')

            print("\nDeseja consultar mais CEPs?\n")
            print("\t1) Consultar mais CEPs")
            print("\t2) Voltar para o menu")
            opcaoconsulta = int(input())
            if (opcaoconsulta != 1 and opcaoconsulta != 2):
                print('Essa opção não está disponível!\n')
                print("\nDeseja consultar mais CEPs?\n")
                print("\t1) Consultar mais CEPs")
                print("\t2) Voltar para o menu")
            elif opcaoconsulta == 1:
                os.system('cls')
                print('Vamos consultar mais CEPs!')
            elif opcaoconsulta == 2:
                break

    def excluir():
        while True:
            cep = 0
            opcaoexcluir = 0
            print("Digite o CEP a ser excluído: ");
            cep = input()

            arquivo = str(cep)
            f = 0
            fileexists = os.path.isfile(arquivo+'.txt')
            if fileexists == True:
                os.remove(arquivo+'.txt')
                print('O CEP foi excluído com sucesso.')
            else:
                print('O CEP inserido não foi encontrado.')

            print("\nDeseja excluir mais CEPs?\n")
            print("\t1) Excluir mais CEPs")
            print("\t2) Voltar para o menu")
            opcaoexcluir = int(input())
            if (opcaoexcluir != 1 and opcaoexcluir != 2):
                print('Essa opção não está disponível!\n\n')
                print("\nDeseja excluir mais CEPs?\n")
                print("\t1) Excluir mais CEPs")
                print("\t2) Voltar para o menu")
            elif opcaoexcluir == 1:
                os.system('cls')
                print('Vamos excluir CEPs!')
            elif opcaoexcluir == 2:
                break

    while True:
        os.system('cls')
        print("### Sistema de CEP ###\n\n")
        print("Escolha a opção desejada do menu:\n\n")
        print("\t1) Registrar Novo CEP")
        print("\t2) Consultar CEP")
        print("\t3) Excluir CEP")
        print("\t4) Sair do Sistema\n")
	
        print("Opção Selecionada: ")
	

        def opcoesmenu(opcaoescolhida):
            switcher = {
                1: 'um',
                2: 'dois',
                3: 'três',
                4: 'quatro',
            }
            return switcher.get(opcaoescolhida)

        opcaoescolh = int(input())
        os.system('cls')

        if opcoesmenu(opcaoescolh) == 'um':
            registro()
        elif opcoesmenu(opcaoescolh) == 'dois':
            consulta()
        elif opcoesmenu(opcaoescolh) == 'três':
            excluir()
        elif opcoesmenu(opcaoescolh) == 'quatro':
            print('Obrigado por usar o sistema!')
            sys.exit()
        else:
            print('Essa opção não está disponível!')
            os.system("pause")

opcao = 0
senhadigitada = "a"
comparacao = 0
senhadigitada = ''
print("### Sistema de CEP ###\n\n");

while senhadigitada != 'Admin':
    print("Digite a senha para login de administrador: ");
    senhadigitada = input()
    if senhadigitada == "admin":
        comparacao = 0
    else:
        comparacao = 1
    if comparacao == 0:
        menuprincipal()
    else:
        print('Senha incorreta!\n\n')





