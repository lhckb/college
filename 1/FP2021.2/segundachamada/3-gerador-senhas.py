frase=input("Digite a sua frase de no mínimo 200 caracteres:")
senhasGeradas=[]

while len(frase)<200:
    frase=input("Digite a sua frase de no mínimo 200 caracteres:")

escolha=0
while escolha!=2:
    print("Aperte 1 para gerar uma nova senha")
    print("Aperte 2 para parar o gerador de senhas")
    escolha=(int(input()))
    if escolha==1:
        numeroAleatorio=(int(input("Diga um número:")))
        if numeroAleatorio<=0 or numeroAleatorio>=(len(frase)-4):
            print("Número inválido")
        else:
            frase=frase.capitalize()
            frase=frase.replace(' ', '')
            frase=frase.replace('\n', '')
            frase=frase.replace('a', '@')
            frase=frase.replace('A', '@')
            frase=frase.replace('i', '1')
            frase=frase.replace('I', '!')
            frase=frase.replace('.', 'i\'mGroot')
            frase=frase.replace(',', 'i\'mGroot')
            frase=frase.replace(':', 'i\'mGroot')
            frase=frase.replace(';', 'i\'mGroot')

            senha=frase[0:4] + frase[-4:] + frase[numeroAleatorio:numeroAleatorio+4]
            senhasGeradas.append(senha)
        
        
        
    elif escolha==2:
        print("Gerador encerrado.")
    else:
        print("Opção inválida, tente novamente.")
    
for senha in senhasGeradas:
    print(senha)






