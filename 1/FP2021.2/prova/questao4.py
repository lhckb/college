# essa questão eu estendi a questao passada entao tem que cadastrar os livros
# de novo antes de consultar


acervo = {}

def registerBooks(name_book, names_author, classification):
    if classification in acervo.keys():
        acervo[classification].update({name_book : {'names_authors' : names_author}})
    else:
        acervo.update({classification : {name_book : {'names_authors' : names_author}}})

def searchBooks(name_book):
    c = 0
    for key in acervo:
        if name_book in acervo[key]:
            print(f'classificação: {key}')
            print(f'nome do livro: {name_book}')
            print('autores: ')
            c += 1
            for i in acervo[key][name_book]['names_authors']:
                print(i)
    if c == 0:
        print('livro não encontrado...')


bookName = ''
while bookName != 'SAIR':
    bookName = input('nome do livro ("SAIR" para encerrar): ')
    if bookName == 'SAIR':
        print('adiçao de titulos encerrada')
    else:
        numAuthors = int(input('quantos autores? '))
        listAuthors = [input(f'nome do autor {i + 1}: ') for i in range(numAuthors)]
        classification = input('qual a classificação do livro? ')

        registerBooks(bookName, listAuthors, classification)


bookToQuery = ''
while bookToQuery != 'SAIR':
    bookToQuery = input('diga o nome do livro a consultar ("SAIR" para encerrar): ')
    if bookToQuery == 'SAIR':
        print('programa encerrado.')
    else:
        searchBooks(bookToQuery)
