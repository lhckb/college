validate = False
#Insira o código aqui
def validate_rgb(value):
    if int(value) < 256 and int(value) > -1:
        return True
    else: 
        return False

#Insira o código aqui
def rgb2hex(r, g, b):
    if (int(r) and int(g) and int(b)) > 0:
        redInHex = f'{int(r):X}'
        greenInHex = f'{int(g):X}'
        blueInHex = f'{int(b):X}'
    
    else:
        redInHex = '00'
        greenInHex = '00'
        blueInHex = '00'

    return f'#{redInHex}{greenInHex}{blueInHex}'

while validate != True:
    rgb_str = input()
    r, g, b = rgb_str.split(' ')
    validate = validate_rgb(r) and validate_rgb(g) and validate_rgb(b)

hex = rgb2hex(r, g, b)

print('A cor {} em hex é {}'.format((r,g,b), (hex)))