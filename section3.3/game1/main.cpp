/*
LANG:C++
TASK:game1
*/
#include <list>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <map>
#include <cctype>
#include <stack>
using namespace std;
ifstream fin("game1.in");
ofstream fout("game1.out");
int N;
int board[100];
int r[100][100][2];
void game(int start,int end,int&player1,int&player2)
{
	if(r[start][end][0]!=0)
	{
		player1=r[start][end][0];
		player2=r[start][end][1];
		return;
	}
	if(end-start==1)
	{
		if(board[start]>board[end])
		{
			player1=board[start];
			player2=board[end];
		}else
		{
			player1=board[end];
			player2=board[start];
		}
	}
	else
	{
		int a1,b1,a2,b2;
		game(start+1,end,a1,b1);
		game(start,end-1,a2,b2);
		if(board[start]+b1>board[end]+b2)
		{
			player1=board[start]+b1;
			player2=a1;
		}else
		{
			player1=board[end]+b2;
			player2=a2;
		}
	}
	r[start][end][0]=player1;
	r[start][end][1]=player2;
}
int main() {
	fin>>N;
	for(int i=0;i<N;i++)
		fin>>board[i];
	//for(int i=0;i<N;i++)
	//	cout<<board[i]<<" ";
	int player1,player2;
	game(0,N-1,player1,player2);
	fout<<player1<<" "<<player2<<endl;
	fin.close();
	fout.close();
	return 0;
}
