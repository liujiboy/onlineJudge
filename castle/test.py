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
                    if wall&1==0:
                        setroom(rooms,row,col-1)
                    if wall&2==0:
                        setroom(rooms,row-1,col)
                    if wall&4==0:
                        setroom(rooms,row,col+1)
                    if wall&8==0:
                        setroom(rooms,row+1,col)
f=open("castle.in")
line=f.readline()
numbers=re.split(" ",line)
m=int(numbers[0])
n=int(numbers[1])
castle=np.zeros((n,m),dtype="i4")
rooms=np.zeros((n,m),dtype="i4")
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
        if wall&2:
            if row-1>=0:
                nnum=rooms[row-1][col]
                if nnum<>num:
                    if maxrnum<mm[nnum]+mm[num]:
                        maxrnum=mm[nnum]+mm[num]
                        mrow=row
                        mcol=col
                        c='N'
        if wall&4:
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

