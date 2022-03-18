class Parent:
  
  # definindo a função sum na classe pai
  def sum(num1, num2):
    return num1 + num2

class Child(Parent):

  # definindo a classe child herdando da classe pai
  # assim como atributos, não é necessário declarar nada
  pass

# acessando sum pela classe pai
print(Parent.sum(2, 3))

# acessando sum pela classe child
print(Child.sum(2, 3))

# as duas chamadas são acessíveis e retornam com sucesso