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
#define INF 100000
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");
int king;
int knights[26*30];
int row;
int col;
int knights_size;
int board[30*26][30*26];
int kings_shortest_path[30*26];
int king_path(int r,int c)
{
	int path=0;
	//cout<<king<<endl;
	//cin.get();
	int dx=abs(c-(king%col));
	int dy=abs(r-(king/col));
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
	king=(r-1)*col+(c-'A');
	while(true)
	{
		fin>>c>>r;
		if(!fin.good())
			break;
		knights[knights_size++]=(r-1)*col+(c-'A');
	}
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			kings_shortest_path[i*col+j]=king_path(i,j);
		}
/*for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			cout<<i<<" "<<j<<" "<<kings_shortest_path[i*col+j]<<endl;
			cin.get();
		}
*/
	for(int i=0;i<row*col;i++)
		for(int j=0;j<row*col;j++)
		{
			if(i==j)
				board[i][j]=0;
			else
				board[i][j]=INF;
		}

	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			if(i-2>=0&&j-1>=0)
			{
				board[i*col+j][(i-2)*col+j-1]=1;
				board[(i-2)*col+j-1][i*col+j]=1;
				//board[i][j][i-2][j-1]=1;
				//board[i-2][j-1][i][j]=1;
			}
			
			if(i-2>=0&&j+1<col)
			{
				board[i*col+j][(i-2)*col+j+1]=1;
				board[(i-2)*col+j+1][i*col+j]=1;
				//board[i][j][i-2][j+1]=1;
				//board[i-2][j+1][i][j]=1;
			}

			if(i-1>=0&&j-2>=0)
			{
				board[i*col+j][(i-1)*col+j-2]=1;
				board[(i-1)*col+j-2][i*col+j]=1;
				//board[i][j][i-1][j-2]=1;
				//board[i-1][j-2][i][j]=1;
			}

			if(i-1>=0&&j+2<col)
			{
				board[i*col+j][(i-1)*col+j+2]=1;
				board[(i-1)*col+j+2][i*col+j]=1;
				//board[i][j][i-1][j+2]=1;
				//board[i-1][j+2][i][j]=1;
			}

			if(i+1<row&&j-2>=0)
			{
				board[i*col+j][(i+1)*col+j-2]=1;
				board[(i+1)*col+j-2][i*col+j]=1;
				//board[i][j][i+1][j-2]=1;
				//board[i+1][j-2][i][j]=1;
			}

			if(i+1<row&&j+2<col)
			{
				board[i*col+j][(i+1)*col+j+2]=1;
				board[(i+1)*col+j+2][i*col+j]=1;
				//board[i][j][i+1][j+2]=1;
				//board[i+1][j+2][i][j]=1;
			}

			if(i+2<row&&j-1>=0)
			{
				board[i*col+j][(i+2)*col+j-1]=1;
				board[(i+2)*col+j-1][i*col+j]=1;
				//board[i][j][i+2][j-1]=1;
				//board[i+2][j-1][i][j]=1;
			}

			if(i+2<row&&j+1<col)
			{
				board[i*col+j][(i+2)*col+j+1]=1;
				board[(i+2)*col+j+1][i*col+j]=1;
				//board[i][j][i+2][j+1]=1;
				//board[i+2][j+1][i][j]=1;
			}
	
		}

	for(int k=0;k<row*col;k++)
		for(int i=0;i<row*col;i++)
			for(int j=i+1;j<row*col;j++)
			{
				if(board[i][k]!=INF&&board[k][j]!=INF)
				{
					if(board[i][j]>board[i][k]+board[k][j])
					{
						board[i][j]=board[i][k]+board[k][j];
						board[j][i]=board[i][j];
					}
				}
			}

	/*for(int i=0;i<row*col;i++)
			for(int j=0;j<row*col;j++)
			{
				cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
				cin.get();
			}*/
	int min_i=INF;
	int min_path=INF;
	for(int i1=0;i1<row*col;i1++)
		{
			int path=0;
			//type1
			if(knights_size==0)
			{
				path+=kings_shortest_path[i1];
	//			cout<<path<<endl;
				if(path<min_path)
				{
					min_path=path;
					min_i=i1;
				}
			}
			//type2
			else{
				int knight_path=0;
				for(int k2=0;k2<knights_size;k2++)
				{
					knight_path+=board[knights[k2]][i1];
				}
				if(knight_path<=min_path)
				{

					for(int k1=0;k1<knights_size;k1++)
					{
						int short_path=knight_path-board[knights[k1]][i1];
						for(int i2=0;i2<row*col;i2++)
							{
								path=short_path;
								path+=board[knights[k1]][i2]+board[i2][i1]+kings_shortest_path[i2];
					//			cout<<path<<endl;
								if(path<min_path)
								{
									min_path=path;
									min_i=i1;
								}
							}

					}
				}
				//cout<<i1<<" "<<min_path<<endl;
			}
		}
/*	for(int i=0;i<row*col;i++)
	{
		int path=0;
		for(int j=0;j<knights_size;j++)
		{
			path+=board[knights[j]][i];
		}
		if(path<min_path)
		{
			min_path=path;
			min_i=i;
		}
	}*/
	fout<<min_path<<endl;
	fin.close();
	fout.close();
	return 0;
}
