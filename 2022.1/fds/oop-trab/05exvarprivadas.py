class Example:

    # definição de variável privada, inacessível por objeto
    __privateVariable = 10

    # variável pública para comparação
    regularVariable = 20

obj1 = Example()

# printando var acessível pelo objeto
#print(obj1.regularVariable)

# printando var inacessível pelo objeto
#print(obj1.__privateVariable)


class Cryptography:

    # definindo var privada
    __secretHash = 10

    # método que utiliza var privada
    def hashPassword(self, passw):
        return passw * self.__secretHash

# instanciação
passwGenerator = Cryptography()

# chamada de método salvando retorno em myPassword
myPassword = passwGenerator.hashPassword(123)

# printando retorno salvo
print(myPassword)
