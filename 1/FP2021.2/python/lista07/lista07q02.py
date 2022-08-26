import math

coordP1 = (float(input('x1: ')), float(input('y1: ')))
coordP2 = (float(input('x2: ')), float(input('y2: ')))

res = math.sqrt((coordP2[0] - coordP1[0])**2 + (coordP2[1] - coordP1[1])**2)

print(res)