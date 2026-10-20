import numpy as np
#A=2*10e6
A=2000000
#visit=np.zeros(A)
visit=np.zeros(A+1,dtype=bool)
sum=0
for i in range(2,A):
    if(visit[i]==0):
        sum+=i
        j=i
        number=2
        while(j*number<=A):
            visit[j*number]=1
            number+=1
    elif(visit[i]==1):
        continue

print(sum)
