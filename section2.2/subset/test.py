import numpy as np
n=31
A=np.zeros(n*(n+1)/4+1,dtype=np.int)
middle=n*(n+1)/4
len=0;
A[0]=1;
A[1]=1
len=1
for col in range(2,n+1):
    for row in range(middle,-1,-1):
        if A[row]!=0:
            v=col+row
#            print v
            if v<=middle:
            #    if col==8:
             #       print row,col,A[row],A[v]
                A[v]+=A[row]
    print A
    raw_input()
    
