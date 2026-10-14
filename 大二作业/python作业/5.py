import tkinter as tk
import math
class Calculator:
    def __init__(self):
        window=tk.Tk()
        window.title("三角形面积")
        window.geometry("300x200+400+400")
        #输入框
        tk.Label(window,text="边长A").grid(row=0,column=0)
        self.a=tk.Entry(window)
        self.a=tk.Entry(window,width=5)
        self.a.grid(row=0,column=1)

        tk.Label(window,text="边长B").grid(row=0,column=2)
        self.b=tk.Entry(window)
        self.b=tk.Entry(window,width=5)
        self.b.grid(row=0,column=3)
        
        tk.Label(window,text="边长C").grid(row=0,column=4)
        self.c=tk.Entry(window)
        self.c=tk.Entry(window,width=5)
        self.c.grid(row=0,column=5)
        #按钮
        button=tk.Button(window,text="计算面积",command=self.compute).grid(row=3,column=0)
        #结果
        self.result=tk.Label(window,text="")
        self.result.grid(row=3,column=2)
        window.mainloop()
    def compute(self):
        numa=float(self.a.get())
        numb=float(self.b.get())
        numc=float(self.c.get())
        if numa+numb<=numc or numa+numc<=numb or numb+numc<=numa:
            self.result.config(text="无法组成三角形")
            return
        p=(numa+numb+numc)/2
        s = math.sqrt(
        p*(p-numa)*(p-numb)*(p-numc)
        )
        self.result.config(text=f"{s:.2f}")

if __name__ == "__main__":
    Calculator()
