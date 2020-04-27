from tkinter import *
import net
import comands

net.inter()
width, height = 200, 45
window = Tk()
window.title('JSerial')
window.minsize(width=width, height=height)
window.maxsize(width=width, height=height)

primeiroContainer = Frame(window)
primeiroContainer.pack()

btnligar = Button(primeiroContainer,height =2 ,width = 8,bg="dark green",fg="snow", text="LIGAR",command=comands.liga)
btnligar.pack(side=LEFT)

btnDesligar = Button(primeiroContainer,height = 2,width =8,bg="dark red",fg="snow",text="DESLIGAR",command=comands.desliga)
btnDesligar.pack(side=LEFT)

window.mainloop()
