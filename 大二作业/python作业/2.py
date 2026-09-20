import math as m
n=int(input())
while n:
    a=float(input())
    b=float(input())
    c=float(input())
    if a+b>c and b+c>a and a+c>b:
        s=(a+b+c)/2
        area=m.sqrt(s*(s-a)*(s-b)*(s-c))
        print(area)
    else:
        print("输入错误")
    n-=1
