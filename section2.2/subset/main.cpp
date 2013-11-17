/*
LANG:C++
TASK:subset
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");
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
unsigned int A[391];
int main() {
	int n;
	fin>>n;
	if(n*(n+1)%4==0)
	{
		int middle=n*(n+1)/4;
		A[0]=1;
		A[1]=1;
		for(int col=2;col<=n;col++)
		{
			for(int row=middle;row>=0;row--)
			{
				if(A[row]!=0)
				{
					int v=row+col;
					if(v<=middle)
						A[v]+=A[row];
				}
			}
		}
		fout<<A[middle]/2<<endl;
	}else
	{
		fout<<0<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
