class Parent:

  # definindo um atributo da classe parent
  whatami = 'a class'

class Child(Parent):

  iAm ='the bluest of blues'

print(Parent.whatami)
print(Child.whatami)

print(Child.iAm)

# atributo dado a classe filha além das heranças
# não existe na classe pai
print(Parent.iAm)