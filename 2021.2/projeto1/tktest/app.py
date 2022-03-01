from tkinter import *
from tkinter.ttk import *
from PIL import Image, ImageTk
from functions import openGoodSong, playSound


root = Tk()  #begins window
root.title('Recifeblue Projeto 1-Teste 001')

def secondScreen():
    secondRoot = Toplevel(root)
    secondRoot.title('Recifeblue Projeto 1-Teste 002')

    secondRoot.geometry('400x400')
    #secondRoot.grid(columnspan=3, rowspan=4)

    text = Label(secondRoot, text='nice')
    text.pack()

    okImg = Image.open('./images/nice.jpg')
    okImg = ImageTk.PhotoImage(okImg)
    label = Label(secondRoot, image=okImg)
    label.image = okImg
    label.pack()

    button = Button(secondRoot, command=secondRoot.quit, text='quit')
    button.pack()

# sizes and splits window
canvas = Canvas(root, width=400, height=400)
canvas.grid(columnspan=3, rowspan=5)

# loads image
logo = Image.open('./images/recblue.png')
logo = logo.resize((111, 111))
logo = ImageTk.PhotoImage(logo)
logoLabel = Label(image=logo)
logoLabel.image = logo 
logoLabel.grid(column=1, row=0)

# interactive code
# instruction text
instruction = Label(root, text='welcome to tkinter test')
instruction.grid(column=1, row=1)

# button
webButton = Button(root, command=lambda:openGoodSong(), text='click here to get a free cake recipe')
webButton.grid(column=1, row=2)

soundButton = Button(root, command=lambda:playSound(), text='click here to obtain intelligence')
soundButton.grid(column=1, row=3)

nextButton = Button(root, command=lambda:secondScreen(), text='click here to see something nice')
nextButton.grid(column=1, row=4)

root.mainloop() # ends window
# everything inside window must be inside tk.Tk() and mainloop()

