class Human: 
    
    # função construtora
    def __init__(self, name, age):

        # self diz "eu mesmo"
        self.name = name
        self.age = age


ricardo = Human('Ricardo Costa', 30)
luis = Human('Luís Cruz', 18)

print(ricardo.name)
print(luis.name)