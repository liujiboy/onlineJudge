/*
LANG:C++
TASK:nocows
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");
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
unsigned int tree[200][100];
int  f(int n,int k)
{
	if(tree[n][k]!=-1)
		return tree[n][k];
	int v=0;
	for(int i=1;i<n-1;i+=2)
	{
		int j=n-1-i;
		for(int l=1;l<k;l++)
		{
				v=(v%9901+f(i,l)*f(j,k-1)%9901)%9901;
	//			printf("n=%d,k=%d,v=%d,f(%d,%d)=%d,f(%d,%d)=%d\n",n,k,v,i,l,f(i,l),j,k-1,f(j,k-1));
	//			cin.get();
		}
		for(int l=1;l<k-1;l++)
		{
				v=(v%9901+f(i,k-1)*f(j,l)%9901)%9901;
	//			printf("n=%d,k=%d,v=%d,f(%d,%d)=%d,f(%d,%d)=%d\n",n,k,v,i,k-1,f(i,k-1),j,l,f(j,l));
	//			cin.get();
		}

	}
	tree[n][k]=v;
	return v;
}
int main() {
	for(int n=1;n<200;n+=2)
	{
		for(int k=1;k<100;k++)
		{
			if(n<2*k-1||n>pow(2,k)-1)
				tree[n][k]=0;
			else
			{
				if(n==pow(2,k)-1)
					tree[n][k]=1;
				else
					tree[n][k]=-1;
			}
	//		cout<<"("<<n<<","<<k<<")="<<tree[n][k]<<endl;
			//cin.get();
		}
	}
	int n,k;
	fin>>n>>k;
	//cout<<f(11,4)%9901<<endl;
	//f(33,6);
	fout<<f(n,k)<<endl;

	/*for(int n=1;n<200;n+=2)
	{
		for(int k=1;k<100;k++)
		{
			printf("(%d,%d)=%d\n",n,k,tree[n][k]);
		}
	}*/

	fin.close();
	fout.close();
	return 0;
}
