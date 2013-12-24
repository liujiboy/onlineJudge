/*
LANG:C++
TASK:fact4
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
ifstream fin("fact4.in");
ofstream fout("fact4.out");
unsigned long n;
unsigned long right_n(unsigned long k,unsigned long n)
{
	if(n==0)
		return 0;
	return right_n(k/10,n-1)*10+k%10;
}
unsigned long right_most(unsigned long k)
{
	while(k%10==0)
	{
		k=k/10;
	}
	return k%10;
}
int main() {
	//cout<<right_n(123456789,5);
	fin>>n;
	unsigned long m=1;
	//n=15;
	for(unsigned long i=1;i<=n;i++)
	{
		//m=right_most(m*right_most(i));
		m=m*i;
		while(m%10==0)
		{
			m=m/10;
		}
		m=right_n(m,5);
	}
	fout<<right_most(m)<<endl;
	fin.close();
	fout.close();
	return 0;
}
