import tkinter as tk
from tkinter import ttk
import tkinter.messagebox
import os
 
win = tk.Tk()
win.geometry("270x100")
win.title("Code-Definder")
 
label1=ttk.Label(win, text="选择版本:")
label1.grid(column=1, row=1)
label2=ttk.Label(win, text="文件名:")
label2.grid(column=1, row=3)
 
def clickMe():

    source = entry1.get()
    tk.messagebox.showinfo('请确定','请确定开始转化\n转化造成的一切不良后果概不负责\n你不得不同意上述条款')
    if numberChosen.current()==0 :
        os.system("g++ Main/hwc/main.cpp -o main.exe -std=c++11 -O2")
    if numberChosen.current()==1 :
        os.system("g++ Main/ckw/main.cpp -o main.exe -std=c++11 -O2")
    if numberChosen.current()==2 :
        os.system("g++ Main/lsq/main.cpp -o main.exe -std=c++11 -O2")
    os.system("main.exe "+source+" tmp.cpp")
    os.system("del main.exe")
    os.system("del "+source)
    os.system("ren tmp.cpp "+source)
    tk.messagebox.showinfo('提示','转化完成')


action = ttk.Button(win, text="开始转化", command=clickMe)
action.grid(column=2, row=4)

number = tk.StringVar()
numberChosen = ttk.Combobox(win, width=16, textvariable=number)
numberChosen['values'] = ('版本1 - by hwc', '版本2 - by ckw', '版本3 - by lsq')
numberChosen.grid(column=2, row=1)
numberChosen.current(0)

entry1=tk.Entry(win,width=16,bg="white",fg="black")
entry1.grid(column=2, row=3)

win.mainloop()
 
 
