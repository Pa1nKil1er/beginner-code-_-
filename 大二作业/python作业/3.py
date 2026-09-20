i=100
n=0
while(i<=1000):
    if(i%5==0 and i%6==0):
        n+=1
        print(i,end=" ")
        if(n==10):
            n=0
            print(end="\n")
    i+=1
