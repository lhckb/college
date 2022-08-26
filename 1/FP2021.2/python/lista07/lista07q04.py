text = input('begin your text:\n')

while True: 
    choice = input('''c- write more text; r- read what has been written so far
    u- update/modify text already written; d- delete portion of the text; 
    press any other key- quit program: \n''')

    if choice == 'c':
        text += ' ' + input('\ncontinue writing: ')

    if choice == 'r':
        print('\n' + text)

    if choice == 'u':
        print('\nprovide START index and END index for portion of the text:\n')

        start = int(input('START:'))
        end = int(input('END: '))

        currentStr = input('word to edit: ')
        newStr = input('new word: ')

        # temporary string to separate information and then replace on the main text
        tempStr = text[start : end] 
        tempStr = tempStr.replace(currentStr, newStr)

        text = text.replace(text[start : end], tempStr)

    if choice == 'd':
        print('\nprovide START index and END index for portion of the text:\n')
        
        start = int(input('START:'))
        end = int(input('END: '))

        text = text.replace(text[start : end], '')

    