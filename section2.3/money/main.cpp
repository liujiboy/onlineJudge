/*
LANG:C++
TASK:money
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
	template<class T>
void print(T a,int row,int col,ostream&out=cout)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(j!=col-1)
				out<<a[i][j]<<" ";
			else
				out<<a[i][j];
		}
		cout<<endl;
	}
}
	template<class T>
void print(T a,int len,ostream&out=cout,bool newline=false)
{
	for(int i=0;i<len;i++)
	{
		if(!newline)
		{
			if(i!=len-1)
				out<<a[i]<<" ";
			else
				out<<a[i]<<endl;
		}
		else
		{
			out<<a[i]<<endl;
		}
	}
}
	template<class T>
void init(T* a,int len,T v)
{
	for(int i=0;i<len;i++)
		a[i]=v;
}
template<class T> 
class comp{
	public:
		bool operator()(T a,T b)
		{
			return a<b;
		}
};
int coins[25];
int v;
int n;
signed long long solutions[25][10001];
signed long long search(int i,int remain)
{
	
	if(remain==0)
	{
		return 1;
	}else if(remain<0)
	{
		return 0;
	}else if(i==v)
	{
		return 0;
	}
	if(solutions[i][remain]!=-1)
		return solutions[i][remain];
	int coin=coins[i];
	signed long long r=0;
	for(int j=0;j<=remain/coin;j++)
	{
		r+=search(i+1,remain-j*coin);
	}
	solutions[i][remain]=r;
	return r;
}
int main() {
	fin>>v>>n;
	for(int i=0;i<v;i++)
	{
		fin>>coins[i];
	}
	for(int i=0;i<25;i++)
		for(int j=0;j<10001;j++)
			solutions[i][j]=-1;
	search(0,n);
	fout<<solutions[0][n]<<endl;
	fin.close();
	fout.close();
	return 0;
}
