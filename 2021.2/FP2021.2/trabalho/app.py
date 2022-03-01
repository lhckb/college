from utils import main

try:
    palavras = open('palavras.txt', 'r')
    frases = open('frases.txt', 'r')

    # inicia e escreve o cabeçalho do csv
    saida = open('saida.csv', 'w')
    saida.write('frase|palavras_reconhecidas|res_calc_sentimento|palavras_aprendidas')
    saida.close()

    # abre novamente o csv em modo append para escrita linha por linha
    saida = open('saida.csv', 'a')

except Exception as e:
    print(f'não foi possível abrir algum arquivo devido a {e}')


if __name__ == '__main__':
    try:
        main(palavras, frases, saida)

    except Exception as e:
        print(f'não foi possível executar o programa principal devido a {e}')


palavras.close()
frases.close()
saida.close()

