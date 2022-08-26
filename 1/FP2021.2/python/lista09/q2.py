

multiplicador = int(input())
resp = 0
num = -1
def calcular(multiplicador, num):
    global resp
    resp = multiplicador * (num + 1)
    
    

while num < 10:
    calcular(multiplicador, num)
    num += 1
    print('{} x {} = {}'.format(num, multiplicador, resp))
