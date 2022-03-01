numStudents = int(input('number of students: '))
studentRegister = []
for i in range(numStudents):
    studentInfo = {
        'name' : input("student's name: "),
        'enrollment' : input('enrollment code: '),
        'subjects' : [{input('subject: ') : float(input('final grade: '))} 
        for i in range(int(input('number of subjects for this student: ')))]
        }

    studentRegister.append(studentInfo)
    # print(studentRegister)

choice = 0
while choice != 3:
    choice = int(input('\nhow would you like to search? 1- name; 2- enrollment code; 3- exit: '))
    if choice == 1:
        name = input('\nname: ')
        try:
            for item in studentRegister:
                if item['name'] == name:
                    print(f'{item}\n') 
        except:
            print(f'\nno students found with name {name}\n')
    
    if choice == 2:
        code = input('\nenrollment code: ')
        try:
            for item in studentRegister:
                if item['enrollment'] == code:
                    print(f'{item}\n')
        except:
            print(f'\nno students found with enrollment {code}\n')

    if choice == 3:
        print('''thanks for choosing the LuisEldrey database services.
        if you like our platform, please donate to our PIX''')
