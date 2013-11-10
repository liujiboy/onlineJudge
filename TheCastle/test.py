import numpy as np
import re
def setroom(rooms,row,col):
    if rooms[row][col]==0:
        rooms[row][col]=-1
def flood_fill(castle,rooms,n,m,rnum):
    flag=1
    while flag:
        flag=0
        for row in range(0,n):
            for col in range(0,m):
                if rooms[row][col]==-1:
                    flag=1
                    rooms[row][col]=rnum
                    wall=castle[row][col]
                    if wall==1:
                        setroom(rooms,row-1,col)
                        setroom(rooms,row,col+1)
                        setroom(rooms,row+1,col)
                    elif wall==2:
                        setroom(rooms,row,col+1)
                        setroom(rooms,row+1,col)
                        setroom(rooms,row,col-1)
                    elif wall==4:
                        setroom(rooms,row-1,col)
                        setroom(rooms,row+1,col)
                        setroom(rooms,row,col-1)
                    elif wall==8:
                        setroom(rooms,row-1,col)
                        setroom(rooms,row,col+1)
                        setroom(rooms,row,col-1)
                    elif wall==1+2:
                        setroom(rooms,row,col+1)
                        setroom(rooms,row+1,col)
                    elif wall==1+4:
                        setroom(rooms,row-1,col)
                        setroom(rooms,row+1,col)
                    elif wall==1+8:
                        setroom(rooms,row-1,col)
                        setroom(rooms,row,col+1)
                    elif wall==2+4:
                        setroom(rooms,row,col-1)
                        setroom(rooms,row+1,col)
                    elif wall==2+8:
                        setroom(rooms,row,col-1)
                        setroom(rooms,row,col+1)
                    elif wall==4+8:
                        setroom(rooms,row-1,col)
                        setroom(rooms,row,col-1)
                    elif wall==1+2+4:
                        setroom(rooms,row+1,col)
                    elif wall==1+2+8:
                        setroom(rooms,row,col+1)
                    elif wall==1+4+8:
                        setroom(rooms,row-1,col)
                    elif wall==2+4+8:
                        setroom(rooms,row,col-1)
f=open("castle.in")
line=f.readline()
numbers=re.split(" ",line)
m=int(numbers[0])
n=int(numbers[1])
castle=np.zeros((n,m))
rooms=np.zeros((n,m))
for row in range(0,n):
    line=f.readline()
    numbers=re.split(" ",line)
    for col in range(0,m):
        castle[row][col]=int(numbers[col])
rnum=0
for row in range(0,n):
    for col in range(0,m):
        if rooms[row][col]==0:
            rnum+=1
            rooms[row][col]=-1
            flood_fill(castle,rooms,n,m,rnum)
print rnum
mm={}
for row in range(0,n):
    for col in range(0,m):
        mm[rooms[row][col]]=mm.get(rooms[row][col],0)+1
maxrnum=0
mrow=0
mcol=0
for i in mm:
    if maxrnum<mm[i]:
        maxrnum=mm[i]
print maxrnum
c=''
#  2
#1   4
#  8
for row in range(n-1,-1,-1):
    for col in range(0,m):
        wall=castle[row][col]
        num=rooms[row][col]
        if wall==3 or wall==6 or wall==10 or wall==7 or wall==14 or wall==11 or wall==15:
            if row-1>=0:
                nnum=rooms[row-1][col]
                if nnum<>num:
                    if maxrnum<mm[nnum]+mm[num]:
                        maxrnum=mm[nnum]+mm[num]
                        mrow=row
                        mcol=col
                        c='N'
        if wall==5 or wall==6 or wall==12 or wall==7 or wall==14 or wall==13 or wall==15:
            if col+1<m:
                nnum=rooms[row][col+1]
                if nnum<>num:
                    if maxrnum<mm[nnum]+mm[num]:
                        maxrnum=mm[nnum]+mm[num]
                        mrow=row
                        mcol=col
                        c='E'
print maxrnum
print mrow+1,mcol+1,c

