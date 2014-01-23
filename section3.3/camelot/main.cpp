/*
LANG:C++
TASK:camelot
*/
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <map>
#include <cctype>
#include <stack>
#define INF 0x7FFFFFFF
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");
struct chess{
	int x;
	int y;
};
chess knights[26*30+1];
chess king;
int row;
int col;
int knights_size;
int board[31][27][31][27];
int kings_shortest_path[31][27];
void debug()
{
	cout<<"king:"<<king.x<<","<<king.y<<endl;
	for(int i=1;i<=knights_size;i++)
	{
		cout<<"knight:"<<knights[i].x<<","<<knights[i].y<<endl;
	}

}
int king_path(int i,int j)
{
	int path=0;
	int dx=abs(i-king.x);
	int dy=abs(j-king.y);
	if(dx>dy)
	{
		path+=dy;
		path+=dx-dy;
	}else
	{
		path+=dx;
		path+=dy-dx;
	}
	return path;
}
int main() {
	fin>>row>>col;
	char c;
	int r;
	fin>>c>>r;
	king.x=r;
	king.y=c-'A'+1;
	while(true)
	{
		fin>>c>>r;
		if(!fin.good())
			break;
		knights_size++;
		knights[knights_size].x=r;
		knights[knights_size].y=c-'A'+1;
	}
	for(int i=1;i<=row;i++)
		for(int j=1;j<=col;j++)
		{
			kings_shortest_path[i][j]=king_path(i,j);
		}
	for(int i1=1;i1<=row;i1++)
		for(int j1=1;j1<=col;j1++)
			for(int i2=1;i2<=row;i2++)
				for(int j2=1;j2<=col;j2++)
				{
					if(i1==i2&&j1==j2)
						board[i1][j1][i2][j2]=0;
					else
						board[i1][j1][i2][j2]=INF;
				}
	for(int i=1;i<=row;i++)
		for(int j=1;j<=col;j++)
		{
			if(i-2>=1&&j-1>=1)
			{
				board[i][j][i-2][j-1]=1;
				board[i-2][j-1][i][j]=1;
			}
			if(i-2>=1&&j+1<=col)
			{
				board[i][j][i-2][j+1]=1;
				board[i-2][j+1][i][j]=1;
			}
			if(i-1>=1&&j-2>=1)
			{
				board[i][j][i-1][j-2]=1;
				board[i-1][j-2][i][j]=1;
			}
			if(i-1>=1&&j+2<=col)
			{
				board[i][j][i-1][j+2]=1;
				board[i-1][j+2][i][j]=1;
			}
			if(i+1<=row&&j-2>=1)
			{
				board[i][j][i+1][j-2]=1;
				board[i+1][j-2][i][j]=1;
			}
			if(i+1<=row&&j+2<=col)
			{
				board[i][j][i+1][j+2]=1;
				board[i+1][j+2][i][j]=1;
			}
			if(i+2<=row&&j-1>=1)
			{
				board[i][j][i+2][j-1]=1;
				board[i+2][j-1][i][j]=1;
			}
			if(i+2<=row&&j+1<=col)
			{
				board[i][j][i+2][j+1]=1;
				board[i+2][j+1][i][j]=1;
			}
		}
	for(int k=1;k<=row;k++)
		for(int l=1;l<=col;l++)
			for(int i1=1;i1<=row;i1++)
				for(int j1=1;j1<=col;j1++)
					for(int i2=1;i2<=row;i2++)
						for(int j2=1;j2<=col;j2++)
						{
							if(i2*col+j2>i1*col+j1)
							{
							if(board[i1][j1][k][l]!=INF&&board[k][l][i2][j2]!=INF)
							{
								if(board[i1][j1][i2][j2]>board[i1][j1][k][l]+board[k][l][i2][j2]){
									board[i1][j1][i2][j2]=board[i1][j1][k][l]+board[k][l][i2][j2];
									board[i2][j2][i1][j1]=board[i1][j1][i2][j2];
								}
							}
							}
						}
	int min_i=INF;
	int min_j=INF;
	int min_path=INF;
	for(int i1=1;i1<=row;i1++)
		for(int j1=1;j1<=col;j1++)
		{
			int path=0;
			//type1
			if(knights_size==0)
			{
				path+=kings_shortest_path[i1][j1];
				for(int k=1;k<=knights_size;k++)
					path+=board[knights[k].x][knights[k].y][i1][j1];
				if(path<min_path)
				{
					min_path=path;
					min_i=i1;
					min_j=j1;
				}
			}
			//type2
			else{
				int knight_path=0;
				for(int k2=1;k2<=knights_size;k2++)
				{
					knight_path+=board[knights[k2].x][knights[k2].y][i1][j1];
				}
				if(knight_path<=min_path)
				{
					for(int k1=1;k1<=knights_size;k1++)
					{
						int short_path=knight_path-board[knights[k1].x][knights[k1].y][i1][j1];
						for(int i2=1;i2<=row;i2++)
							for(int j2=1;j2<=col;j2++)
							{
								path=short_path;
								path+=board[knights[k1].x][knights[k1].y][i2][j2]+board[i2][j2][i1][j1]+kings_shortest_path[i2][j2];
								if(path<min_path)
								{
									min_path=path;
									min_i=i1;
									min_j=j1;
								}
							}

					}
				}
			}
		}
	fout<<min_path<<endl;
	fin.close();
	fout.close();
	return 0;
}
