class Example:

    # atributo definido no top-level da classe
    name = 'class example'

class Example2:

    def __init__(self, name):
        # atributo definido pela construtora ao instanciar
        self.name = name

ex1 = Example()
ex2 = Example2('another class example')

print(ex1.name)
print(ex2.name)

newObj = Example()
anotherObj = Example()
lastObj = Example()

print(newObj.name)
print(anotherObj.name)
print(lastObj.name)

walter = Example2('heisenberg')
jesse = Example2('pinkman')

print(walter.name)
print(jesse.name)
