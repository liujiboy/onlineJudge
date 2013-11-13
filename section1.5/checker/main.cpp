/*
LANG:C++
TASK:checker
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
int n;
bool board[13][13];
int flag[13][13];
int solution=0;
ifstream fin ("checker.in");
ofstream fout ("checker.out");
inline void printboard()
{
	if(solution<3)
	{
		for(int row=0;row<n-1;row++)
		{
			for(int col=0;col<n;col++)
			{
				if(board[row][col])
				{
					fout<<col+1<<" ";
					break;
				}
			}
		}
		for(int col=0;col<n;col++)
			if(board[n-1][col])
			{
				fout<<col+1<<endl;
				break;
			}
	}
	solution++;
}
inline void  setflag(int row,int col,int v)
{
	for(int i=row+1;i<n;i++)
		flag[i][col]+=v;
	int k=1;
	while(row+k<n)
	{
		if(col-k>=0)
			flag[row+k][col-k]+=v;
		if(col+k<n)
			flag[row+k][col+k]+=v;
		k++;
	}
}
inline void checker(int row)
{
	for(int col=0;col<n;col++)
	{
		if(!flag[row][col])
		{
			board[row][col]=true;
			if(row==n-1)
				printboard();
			else
			{
				setflag(row,col,1);
				checker(row+1);
				setflag(row,col,-1);
			}
			board[row][col]=false;
		}
	}
}
int main() {
	fin>>n;
	checker(0);
	fout<<solution<<endl;
	fin.close();
	fout.close();
	return 0;
}
