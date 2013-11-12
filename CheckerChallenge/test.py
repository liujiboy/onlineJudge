#!/usr/local/bin/python
import numpy as np
def printboard(board,n):
    global solution
    if solution<3:
        for row in range(0,n):
            for col in range(0,n):
                if board[row][col]:
                    print col+1,
        print "\n"
    solution+=1
def setflag(flag,row,col,n,v):
    #for i in range(col,n):
    #    flag[row][i]+=v
    for i in range(row+1,n):
        flag[i][col]+=v
    k=1
    while(row+k<n and col-k>=0):
        flag[row+k][col-k]+=v
        k+=1
    k=1
    while(row+k<n and col+k<n):
        flag[row+k][col+k]+=v
        k+=1
def checker(board,flag,row,n):
    for col in range(0,n):
        if flag[row][col]==0:
            board[row][col]=1
            setflag(flag,row,col,n,1)
            #print row,col
            #print flag
            #raw_input()
            if row==n-1:
                printboard(board,n)
            else:
                #print "next"
                checker(board,flag,row+1,n)
            board[row][col]=0
            setflag(flag,row,col,n,-1)
solution=0
n=13
board=np.zeros((n,n))
flag=np.zeros((n,n))
checker(board,flag,0,n)
print solution
