agenda={
    'Eldrey':{'fone':'(41) 99999-9999'},
    'Mateus':{'fone':'8888-8888'},
    'Luciana':{'fone':'+351 213 924 999'},
    'Police':{'fone':'112'},
    'Policia':{'fone':'190'}
}

def searchPhone(number):
    controle=0
    for pessoa in agenda:
        numero=agenda[pessoa]['fone']
        number=number.rstrip()#coloquei strip pra evitar erros de digitação com o espaço
        number=number.lstrip()
        if numero==number:
            print(f'{pessoa} = {number}')
            controle += 1
    if controle==0:
        print("Contato não foi encontrado")

searchPhone('1901')#teste numero inexistente
searchPhone('(41) 99999-9999')#teste numero que existe