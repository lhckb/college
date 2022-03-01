names =[]
jumps = []
averages = []

name = ''
while name != 'SAIR':
    name = input("athlete's name: (type SAIR to stop): ")
    if name == 'SAIR':
        print('program stopped')

    elif name == 'eldrey' or name == 'Eldrey':
        print('sei la... acho que esse cara vai perder\n')
        names.append(name)
        jumps.append([float(input(f'jump {i + 1} score: ')) for i in range(5)])

    elif name == 'luis' or name == 'Luis':
        print('esse aqui salta como ninguém, e programa muito bem também\n')
        names.append(name)
        jumps.append([float(input(f'jump {i + 1} score: ')) for i in range(5)])

    else: 
        names.append(name)
        jumps.append([float(input(f'jump {i + 1} score: ')) for i in range(5)])

for item in jumps:
    item.pop(item.index(min(item)))
    average = sum(item) / 4
    averages.append(average)

pos = 1
for average in reversed(sorted(averages)):
    index = averages.index(average)
    print(f'''athlete {names[index]} gets position {pos} 
    with average {average} and best score {max(jumps[index])}\n''')
    pos += 1
