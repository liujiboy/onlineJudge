/*
LANG:C++
TASK:concom
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");
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
int len=0;
int a[101][101];
int b[101][101];
/*int f(int i,int j)
{
	if(b[i][j]!=-1)
		return b[i][j];
	if(a[i][j]>50)
	{
		b[i][j]=1;
		return 1;
	}
	b[i][j]=-2;
	int r=0;
	for(int k=1;k<=len;k++)
	{
		if(j==5)
		cout<<b[2][4]<<endl;	
		if(i!=k&&j!=k&&b[i][k]!=-2&&f(i,k))
		{
			cout<<i<<" "<<k<<" "<<j<<endl;
		//	cout<<i<<""<<j<<" "<<k<<endl;
		//	cin.get();
			r+=a[k][j];
		}
	}
	if(r>50)
	{
		b[i][j]=1;
	}else
	{
		b[i][j]=0;
	}
	return b[i][j];
}*/
int main() {
	int n;
	fin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		fin>>x>>y>>z;
		a[x][y]=z;
		if(x>len)
		{
			len=x;
		}
		if(y>len)
		{
			len=y;
		}
	}
	for(int i=1;i<=len;i++)
		for(int j=1;j<=len;j++)
		{
			if(i==j)
			{
				b[i][j]=1;
			}else
			{
				if(a[i][j]>50)
					b[i][j]=1;
			}
		}
	n=1;
	while(n)
	{
		n=0;
		for(int i=1;i<=len;i++)
			for(int j=1;j<=len;j++)
			{
				if(b[i][j]==0)
				{
					int r=0;
					for(int k=1;k<=len;k++)
					{
						if(i!=k&&j!=k&&b[i][k]==1)
						{
							/*if(i==34)
							{
								printf("(%d,%d)=%d\n",k,j,a[k][j]);
							}*/
							r+=a[k][j];
						}

					}
					r+=a[i][j];
					if(r>50)
					{
						b[i][j]=1;
						n++;
					}
				}
			}
	}
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(i!=j)
			{
				if(b[i][j])
				{
					fout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}
