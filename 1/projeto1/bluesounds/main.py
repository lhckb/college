from playpause import *

print('-----BEM VINDO AO BLUESOUNDS by Recifeblue-----\n')
print('---instruções: pressione o numero de acordo com a sua escolha---\n')

def main():
    choice1 = int(input('1- entrar no jogo; 2- sair do app: '))

    if choice1 == 1:
        cond = True

        while cond:
            choice2 = int(input('1- do; 2- re; 3- mi; 4- fa; 5- so; 6- la; 7- si; 8- do; 9- VOLTAR AO MENU: '))

            if choice2 == 1:
                playFirstDo()
            
            if choice2 == 2:
                playRe()

            if choice2 == 3:
                playMi()

            if choice2 == 4:
                playFa()

            if choice2 == 5:
                playSo()

            if choice2 == 6:
                playLa()

            if choice2 == 7:
                playSi()

            if choice2 == 8:
                playLastDo()

            if choice2 == 9:
                if not main():
                    cond = False


    elif choice1 == 2:
        print('obrigado por usar o Bluesounds!')
        return False

    else:
        print('escolha inválida, tente novamente.')
        main()


if __name__ == '__main__':
    main()