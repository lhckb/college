class Animal:

  # o método original
  def walk():
    print('using legs...')

class Dog(Animal):

  # o método sobrescrito
  def walk():
    print('on four legs...')

Dog.walk()

class Person(Animal):

  # nada é sobrescrito nem definido
  pass

Person.walk()