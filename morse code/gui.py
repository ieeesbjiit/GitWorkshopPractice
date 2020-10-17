import tkinter as tk
from tkinter import *
#from PIL import ImageTk,Image
import backend
m=tk.Tk()
m.title('MORSE CODE TRANSLATOR ')
a=Label(m,text='MORSE CODE TRANSLATOR',font=("Times New Roman",20)).grid(row=0)
'''canvas=Canvas(m,width=300,height=300)
img=ImageTk.PgithotoImage(Image.open(morse-code.jpg))
canvas.create_image(20,20,anchor=NE,image=img)'''
#ENG TO MORSE
b=Label(m,text='Enter sentance to be translated to morse').grid(row=2)
e1=Entry(m)
e1.grid(row=2, column=1)
def clicked():
    result=backend.encrypt(e1.get())
    output="The sentence in morse code is"+result
    c=Label(m,text=output).grid(row=3,column=0)

bt=Button(m,text="Convert",command=clicked)
bt.grid(row=2,column=2)
#MORSE TO ENG
d=Label(m,text='Enter morse code to be translated to english').grid(row=5)
e2=Entry(m)
e2.grid(row=5, column=1)
def clicked():
    result=backend.decrypt(e2.get())
    output="The sentence in English is"+result
    c=Label(m,text=output).grid(row=6,column=0)
    

bt=Button(m,text="Convert",command=clicked)
bt.grid(row=5,column=2)


m.mainloop()