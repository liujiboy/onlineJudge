/*
LANG:C++
TASK:butter
 */
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include <cctype>
using namespace std;
ifstream fin("butter.in");
ofstream fout("butter.out");
int N;
int P;
int C;
int cows[501];
int path[801][801];
int main()
{
	fin>>N>>P>>C;
	for(int i=1;i<=N;i++)
	{
		fin>>cows[i];
	}
	for(int i=1;i<=C;i++)
	{
		int a,b,c;
		fin>>a>>b>>c;
		path[a][b]=c;
		path[b][a]=c;
	}
	for(int i=1;i<=P;i++)
		for(int j=1;j<=P;j++)
		{
			if(i!=j)
			{
				if(path[i][j]==0)
					path[i][j]=1451;
			}
		}
/*	for(int i=1;i<=P;i++)
		for(int j=1;j<=P;j++)
		{
			cout<<i<<" "<<j<<":"<<path[i][j]<<endl;
		}
	cin.get();*/
	for(int k=1;k<=P;k++)
		for(int i=1;i<=P;i++)
			for(int j=i+1;j<=P;j++)
			{
				if(path[i][j]>path[i][k]+path[k][j])
				{
					path[i][j]=path[i][k]+path[k][j];
					path[j][i]=path[i][j];
				}
			}
	int min=0x7FFFFFFF;
	for(int i=1;i<=P;i++)
	{
		int length=0;
		for(int j=1;j<=N;j++)
		{
			length+=path[i][cows[j]];
		}
		if(min>length)
		{
			min=length;
		}
	}
	fout<<min<<endl;
	fin.close();
	fout.close();
	return 0;
}
