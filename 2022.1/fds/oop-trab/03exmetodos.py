# qualquer string é um objeto do tipo str()
str = 'this is a string'

print(str)

# .upper() é um método de strings, um método proveniente de str()
# .upper() retorna uma cópia da sua string convertida em maiúsculas
str = str.upper()

print(str)

class Utils:
    # classe utils não tem atributos, não tem um tipo de dado específico
    # método não manipula objetos do tipo Utils
    
    def sum(num1, num2):
        return num1 + num2