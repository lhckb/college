with open('test.txt', 'r') as file:

    print(file.tell())

    print(file.read(2))

    file.seek(0)

    for line in file:
        if 'text' in line:
            print(line, '\n', end='')

    file.seek(0)


    print(file.read())

    #file.seek(0)

        
    print(file.tell())


    #print(file.read(15))
