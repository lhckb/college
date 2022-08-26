def main(palavras, frases, saida):
    '''função principal do programa, reservada em módulo para visualização melhor'''

    # loop principal
    for line in frases.readlines():
        paraAdicionar = ''
        linha = line.split('|')
        paraAdicionar = paraAdicionar + linha[0] + '|'

        pesos = []
        palavrasRecog = []
        palavrasAprend = []

        # loop para verificação de palavras reconhecidas e obtenção dos peso da frase
        for palavra in linha[0].split():
            palavras.seek(0)

            for line in palavras.readlines():
                if line.split()[0] == palavra:
                    palavrasRecog.append(palavra)
                    pesos.append(float(line.split()[1]))
                    peso = sum(pesos) / len(pesos)
        
                else:
                    palavrasAprend.append(palavra)
                
        # loop para filtragem da lista de palavras aprendidas, 
        # que devido ao loop anterior, poderia receber várias vezes a mesma palavra
        for item in palavrasAprend:
            while palavrasAprend.count(item) > 1:
                palavrasAprend.remove(item)

            if item in palavrasRecog:
                palavrasAprend.remove(item)

        # seção destinada a salvar novas palavras recém aprendidas
        with open('palavras.txt', 'a') as palavrasAppend:
            for item in palavrasAprend:
                palavrasAppend.write(f'\n{item} {peso}')


        paraAdicionar = paraAdicionar + f'{palavrasRecog}' + '|' + f'{peso}' + '|' + f'{palavrasAprend}'
        saida.write(f'\n{paraAdicionar}')

if __name__ == '__main__':
    print(main.__doc__)
