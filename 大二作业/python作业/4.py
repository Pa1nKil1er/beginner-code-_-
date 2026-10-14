import math

#判断是否能构成三角形
# Returns true if the sum of any two sides is greater than the third
# side.
def is_valid(x, y, z):
    if(x+y>z and x+z>y and y+z>x):
        return True
    else:
        return False

#计算三角形面积
# Returns the area of the triangle.
def area(x, y, z):
    s=(x+y+z)/2
    area=math.sqrt(s*(s-x)*(s-y)*(s-z))
    return area

#主函数
# The first running function.
def main():
    print("Enter three sized in double")
    a,b,c=map(float,input().split(','))
    if(is_valid(a,b,c)):
        print("the area of the triangle",area(a,b,c))
    else:
        print("input is invalid")

#程序入口
# Press the green button in the gutter to run the script. Shift + F10
if __name__ == '__main__':
    main()
