/*
LANG:C++
TASK:kimbits
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
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
unsigned long N,L,I;
int c=0;
int s[32];
bool stop=false;
unsigned long cnm(int n,int m)
{
	unsigned long s = 1;
	int k = 1;
	if(m > n/2)
		m = n-m;
	for(int i=n-m+1;i<=n;i++)
	{
		s *= (unsigned long)i;
		while(k<=m && s%k == 0)
		{
			s /= (unsigned long)k;
			k++;
		}
	}
	return s;
}
unsigned long f(int l,int n)
{
	unsigned long r=0;
	for(int i=0;i<=l&&i<=n;i++)
		r+=cnm(n,i);
	return r;
}
void g(int*s,int n,int l,int i)
{
	if(n==1)
	{
		if(i==2)
		{
			s[n]=1;
		}
		for(int i=N;i>=1;i--)
			fout<<s[i];
		fout<<endl;
		return ;
	}
	unsigned long r=f(l,n-1);
	if(r>=i)
	{
		g(s,n-1,l,i);
	}
	else
	{
		s[n]=1;
		//r=f(l-1,n-1);
		g(s,n-1,l-1,i-r);
	}
}
int main() {
	fin>>N>>L>>I;
	//N=4;
	//L=4;
	//I=15;
	/*unsigned long l=0;
	for(;l<=L;l++)
	{
		unsigned long r=cnm(N,l);
		cout<<l<<" "<<N<<" "<<r<<endl;
		if(I>r)
		{
			I=I-r;
		}
		else
			break;
	}
	cout<<l<<" "<<I<<endl;
	f(s,N,l,0);*/
	g(s,N,L,I);	
	fin.close();
	fout.close();
	return 0;
}
