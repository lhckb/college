nomeDoArquivo = input('nome do arquivo: ')

def validarSalvar(input):
    if input == 'SALVAR':
        return True

def abrirArquivo():
    global file
    file = open(nomeDoArquivo, 'w')
    

def escrever():
    global entrada
    entrada = input('escreva seu texto: ')
    if entrada == 'SALVAR':
        print('encerrado')
    else:
        file.write(f'{entrada} \n')

def main():
    cond = True
    abrirArquivo()
    while cond:
        escrever()
        if validarSalvar(entrada):
            cond = False



if __name__ == '__main__':
    main()

