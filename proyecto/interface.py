import tkinter

ventana = tkinter.tk()
ventana.geometry("400x300") # dimensiones de la ventana

etiqueta = tkinter.Label(ventana, text = "Hola mundo")
etiqueta.pack()

ventana.mainloop() # lleva el registro de lo que ocurre en la ventana

