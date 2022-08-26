investments = []
choice = ''
while choice != 4:
    choice = int(input('register-0; update-1; consult-2; delete-3; close program-4 '))
    
    if choice == 0:
        newDict = {
            'name' : input('name: '),
            'date of purchase' : input('date of purchase: '),
            'purchase value' : f'R${input("purchase value(just numbers): ")}',
            'current value' : f'R${input("current value(just numbers): ")}',
            'value history':[f'R${input(f"{i + 1} month(s) ago: ")}' 
            for i in range(int(input('how many past months do you want to register? ')))]
            }
        
        investments.append(newDict)
        print(investments)

    elif choice == 1:
        name = input('investment name: ')
        currentVal = input('current value: ')
        newName = input('new name: ')

        for index, item in enumerate(investments):
            if item['name'] == name:
                item['value history'].insert(0, item['current value'])
                item['current value'] = f'R${currentVal}'
                item['name'] = newName
                print(investments[0])
            else:
                print(f'investment {index} checked, no match.')
            
    elif choice == 2:
        investName = input('what investment do you wish to consult? ')
        for index, item in enumerate(investments):
            if item['name'] == investName:
                print(investments[index])
            else:
                print(f'investment {index} checked, no match.')

    elif choice == 3:
        investName = input('what investment do you wish to delete? ')
        for index, item in enumerate(investments):
            if item['name'] == investName:
                investments.pop(index)
                print('succesfully deleted')
        
    elif choice == 4:
        print('program closed')
