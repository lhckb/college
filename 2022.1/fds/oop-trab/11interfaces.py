class IAnimal:

  # é definida uma classe com seus métodos sem implementação
  # para que cada classe filha faça a sua própria implementação
  # e se não fizer, o programa não quebra, apenas não faz nada (nesse caso)
  def walk():
    pass

  def eat():
    pass

  def sleep():
    pass

class Dog(IAnimal):

  def walk():
    print('on four legs...')

  def eat():
    print('meat...')

  def sleep():
    print('all day long...')
