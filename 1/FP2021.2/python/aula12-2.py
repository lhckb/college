caminho = input('caminho p o arquivo: ')

file = open(caminho, 'r')

conteudo = file.read().split('\n')
for item in conteudo:
    print(item)

print(conteudo)