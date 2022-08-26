def soma(num1, num2):
    return num1 + num2

def subtracao(num1, num2):
    return num1 - num2

def multiplicacao(num1, num2):
    return num1 * num2

def divisao(num1, num2):
    return num1 / num2


def main():
    operacao = input()
    if '+' in operacao:
        operacao = operacao.split('+')
        print(soma(float(operacao[0]), float(operacao[1])))

    elif '-' in operacao:
        operacao = operacao.split('-')
        print(subtracao(float(operacao[0]), float(operacao[1])))

    elif '*' in operacao:
        operacao = operacao.split('*')
        print(multiplicacao(float(operacao[0]), float(operacao[1])))
            
    elif '/' in operacao:
        operacao = operacao.split('/')
        try:
            print(divisao(float(operacao[0]), float(operacao[1])))
        except Exception as e:
            print(f'you got {e} error')
            main()

    else:
        print('input not valid, try again')
        main()

if __name__ == '__main__':
    main()