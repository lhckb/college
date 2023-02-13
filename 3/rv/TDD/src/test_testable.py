from main import Testable
import pytest

# Utilizando os princípios do TDD, desenvolva o código para retirar o maior e o menor valor de uma lista de números naturais, EXCETO se algum deles for primo. No caso de algum deles ou ambos serem primo deve ser retirado o próximo número maior/menor.   


# Caso a lista esteja vazia, deve retornar uma lista vazia. OK
# Caso o tamanho da lista seja um ou dois e composta por números não primos, deve retornar uma lista vazia. 
# Se houver algum número primo, deve retornar a lista somente com os números primos.
# Para os demais casos, deve retornar uma lista sem o maior e o menor valor .

# A prática deve ser feita em dupla
# Utilize o pyTest 
# Quando finalizar, enviar os arquivos com o código e os testes dos através do Google Classroom

#@pytest
def test_empty_list():
  test = Testable()
  assertion = test.remove_biggest_and_lowest([])
  assert assertion == []

def test_no_primes_list():
  test = Testable()
  assertion = test.remove_biggest_and_lowest([4, 10])
  assert assertion == []


def test_primes_list():
  test = Testable()
  assertion = test.remove_biggest_and_lowest([4, 1, 5, 7, 10])
  assert assertion == [1, 5, 7]
  