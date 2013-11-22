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
unsigned long money[10001];
int main() {
	int v;
	fin>>v>>n;
	for(int i=0;i<v;i++)
	{
		fin>>coins[i];
	}
	money[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i/2;j++)
		{
			money[i]+=money[j]*
		}
	}
	print(coins,v);	
	fin.close();
	fout.close();
	return 0;
}
