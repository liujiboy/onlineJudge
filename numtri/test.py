import numpy as np
f=open("numtri.in")
n=int(f.readline())
value=np.zeros((n,n))
for i in range(0,n):
    line=f.readline()
    import re
    numbers=[int(s) for s in re.split(" ",line)]
    for j in range(0,len(numbers)):
        value[i][j]=numbers[j]        
if n==1:
    print value[0][0]
else:
    for i in range(1,n):
        for j in range(0,i+1):
            if j<>0:
                if value[i-1][j-1]+value[i][j]>value[i-1][j]+value[i][j]:
                    value[i][j]=value[i-1][j-1]+value[i][j]
                else:
                    value[i][j]=value[i-1][j]+value[i][j]
            else:
                    value[i][j]=value[i-1][j]+value[i][j]
    print value




