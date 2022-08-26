name = ''
people = {}
while name != 'SAIR':
    name = input('diga o nome da pessoa ("SAIR" para encerrar): ')
    if name == 'SAIR':
        print('agora informe as contas\n')
    
    else:
        try:
            income = float(input('diga a renda dessa pessoa: '))
        except:
            print('acho que voce digitou algo que não era um número, tente de novo')
        else:
            people.update({name : income})


nameBill = ''
bills = {}
while nameBill != 'SAIR':
    nameBill = input('diga o nome da conta ("SAIR" para encerrar):')
    if nameBill == 'SAIR':
        print('aqui seu resultado:\n')
    
    else:
        try:
            valueBill = float(input('diga o valor dessa conta: '))
        except:
            print('acho que voce digitou algo que nao era um número, tente de novo')
        else:
            bills.update({nameBill : valueBill})


sumAllIncomes = 0
for i in people:
    sumAllIncomes += people[i]


sumAllBills = 0
for i in bills:
    sumAllBills += bills[i]

if sumAllIncomes < sumAllBills:
    print(f'''voces deveriam considerar um corte de gastos,
    a renda total é R${sumAllIncomes} e as contas deram R${sumAllBills}''')


for i in people:
    try:
        contributionValue = (people[i] / sumAllIncomes) * sumAllBills
    except ZeroDivisionError:
        print('aparentemente toda a renda somada dá zero, nao sera possível pagar nada.')
    else:
        print(f'a pessoa {i} paga R${contributionValue}')