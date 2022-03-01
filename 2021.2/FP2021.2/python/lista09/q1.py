def potenciacao_em_lista(lista):
    if len(lista) > 0:
        if len(lista) == 1:
            return lista
        else:
            newLista = [lista[0]]
            for item in lista[1 : len(lista) - 1]:
                if item % 2 == 0:
                    newItem = item ** 2
                    newLista.append(newItem)

                if item % 2 != 0:
                    newItem = item ** 3
                    newLista.append(newItem)
            
            newLista.append(lista[-1])

            return newLista
    else:
        return lista

print(potenciacao_em_lista([2, 4, 3, 2, 56, 1]))
        