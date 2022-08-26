with open('test2.txt', 'w') as file:
    file.write('test')
    file.write('ok')
    file.seek(0)
    file.write('r')
