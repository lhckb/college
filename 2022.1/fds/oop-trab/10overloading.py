class Greeter:

  # método definido com parâmetro opcional
  def sayHi(self, name = None):

    # comportamentos diferentes de acordo com os parâmetros
    if name is not None:
      print(f'Oh hi, {name}')
    
    else:
      print('hello, individual')

greetObj = Greeter()

greetObj.sayHi()
greetObj.sayHi('Mark')