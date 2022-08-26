acervo = {}

def registerBooks(name_book, names_author, classification):
    if classification in acervo.keys():
        acervo[classification].update({name_book : {'names_authors' : names_author}})
    else:
        acervo.update({classification : {name_book : {'names_authors' : names_author}}})

bookName = ''
while bookName != 'SAIR':
    bookName = input('nome do livro ("SAIR" para encerrar): ')
    if bookName == 'SAIR':
        print('programa encerrado')
    else:
        numAuthors = int(input('quantos autores? '))
        listAuthors = [input(f'nome do autor {i + 1}: ') for i in range(numAuthors)]
        classification = input('qual a classificação do livro? ')

        registerBooks(bookName, listAuthors, classification)

#print(acervo)