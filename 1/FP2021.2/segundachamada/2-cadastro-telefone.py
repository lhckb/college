agenda={
    'Eldrey':{'fone':'(41) 99999-9999'},
    'Mateus':{'fone':'8888-8888'},
    'Luciana':{'fone':'+351 213 924 999'},
    'Police':{'fone':'112'},
    'Policia':{'fone':'190'}
}


def registerContact(nome, telefone):
    if nome in agenda:
        numeroAtual=agenda[nome]['fone'] 
        if telefone!=numeroAtual:
            print("Aperte 1 para atualizar o número")
            print("Aperte 2 para manter o atual")
            escolha=(int(input()))
            if escolha==1:
                agenda[nome]['fone']=telefone
            elif escolha==2:
                print("Número atual mantido")
            else:
                print("Escolha inválida, operação cancelada")
    else:
        agenda[nome]={'fone':telefone}

registerContact("Eldrey", "(41) 99999-9998")#teste contato existente numero diferente
registerContact("Mateus Rebelo Fernandes", "1234-5678")#teste contato novo

print(agenda)