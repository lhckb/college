class Parent:

  # definindo um atributo da classe parent
  whatami = 'a class'

class Child(Parent):

  # a classe child apenas estende a classe parent
  # não foi definido nenhum atributo, a child apenas herdou os atributos
  # usamos a palavra chave "pass" para o python seguir em frente
  pass

print(Parent.whatami)
print(Child.whatami)
