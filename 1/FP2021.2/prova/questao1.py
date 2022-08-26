text = [input('begin your text:\n')]
altered = True
cond = True

while cond: 
    choice = input('''c- escrever; r- ler; u- modificar; d- deletar pedaço;
    O- abrir arquivo; S- salvar texto atual; E- sair da aplicação \n''')

    if choice == 'c':
        text.append(input('\ncontinue writing: '))
        altered = True

    if choice == 'r':
        line = 0
        for i in text:
            print(f'{line}| {i}')
            line += 1

    if choice == 'u':
        print('\ndiga o index(linha) da frase:\n')

        index = int(input())

        currentStr = input('palavra a substituir: ')
        newStr = input('nova palavra: ')

        try:
            text[index].replace(currentStr, newStr)
            altered = True

        except IndexError as e:
            print(f'index indisponível: {e}')

    if choice == 'd':
        print('\ndiga o index(linha) da frase:\n')
            
        index = int(input())

        try:
            text.pop(index)
            altered = True

        except IndexError as e:
            print(f'index indisponível: {e}')


        
    if choice == 'S':
        file = open(input('nome do arquivo sem extensão: ')+'.txt', 'w')
        for i in text:
            file.write(i + '\n')
        file.close()
        altered = False
        
    if choice == 'O':
        file = open(input('nome do arquivo com extensão: '), 'r')
        text = []
        for line in file.readlines():
            text.append(line.split("\n")[0])
        file.close()

    if choice == 'E':
        if altered == False:
            print('aplicação encerrada')
            cond = False
        else:
            saveOrNot = input('deseja salvar seu texto? 1- sim; 2- nao')
            if saveOrNot == '1':
                file = open(input('nome do arquivo sem extensão: ')+'.txt', 'w')
                for i in text:
                    file.write(i + '\n')
                altered = False
                print('aplicação encerrada')
                cond = False
                file.close()

            elif saveOrNot == '2':
                print('aplicação encerrada')
                cond = False
