/*
LANG:C++
TASK:comehome
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
ifstream fin("comehome.in");
ofstream fout("comehome.out");
int path[26*2][26*2];
bool cows[26];
int toIndex(char c,bool *cows)
{
	int index;
	if(c>='A'&&c<='Z')
	{
		index=c-'A'+26;
		cows[c-'A']=true;
	}else
	{
		index=c-'a';
	}
	return index;
}
int main() {
	int n;
	fin>>n;
	fin.get();
	for(int i=0;i<n;i++)
	{
		char s,e;
		int d;
		fin.get(s);
		fin.get();
		fin.get(e);
		fin>>d;
		int start=toIndex(s,cows);
		int end=toIndex(e,cows);
		if(path[start][end]!=0)
		{
			if(path[start][end]>d)
			{
				path[start][end]=d;
				path[end][start]=d;

			}
		}else
		{
			path[start][end]=d;
			path[end][start]=d;
		}
		fin.get();
	}
	for(int k=0;k<26*2;k++)
		for(int i=0;i<26*2;i++)
			for(int j=0;j<26*2;j++)
			{
				if(path[i][k]!=0&&path[k][j]!=0)
				{
					if(path[i][j]==0||path[i][j]>path[i][k]+path[k][j])
					{
						path[i][j]=path[i][k]+path[k][j];
					}
					
				}
			}
	int min=-1;
	int p=-1;
	for(int i=26;i<26*2-1;i++)
	{
		if(cows[i-26])
		{
			if(min==-1||min>path[i][51])
			{
				p=i-26;
				min=path[i][51];
			}
		}
	}	
	fout<<(char)('A'+p)<<" "<<min<<endl;
	fin.close();
	fout.close();
	return 0;
}
