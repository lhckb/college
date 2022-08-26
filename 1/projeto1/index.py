from tkinter import *
from PIL import Image, ImageTk

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

#carregar imagem do botão
botaoPlay = Image.open('./resources/images/play.png')
botaoPlay = ImageTk.PhotoImage(botaoPlay)


play = Button(root, image=botaoPlay, borderwidth=0)
play.grid(column=1, row=2)


root.mainloop()
