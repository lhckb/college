from tkinter import *
from PIL import Image, ImageTk
from playpause import *

root = Tk()
root.title('Bluesounds')


#definir tamanho da janela e divisão dos espaços
canvas = Canvas(root, background='#38c3ff', width=1920, height=1080)
canvas.grid(columnspan=3, rowspan=4)

#carregar e mostrar imagem com a logo do app
imagem = Image.open('./resources/images/temp.jpg')  # TODO colocar a imagem séria
imagem = ImageTk.PhotoImage(imagem)
label = Label(image=imagem)
label.grid(column=1, row=1)


button1 = Button(root, command=lambda:play1(), text='teste')
button1.grid(column=0, row=2)


button2 = Button(root, command=lambda:play2(), text='teste')
button2.grid(column=1, row=2)

button3 = Button(root, command=lambda:play3(), text='teste')
button3.grid(column=2, row=2)

root.mainloop()