/*
LANG:C++
TASK:nuggets
 */
#include <list>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <map>
#include <cctype>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream fin("nuggets.in");
ofstream fout("nuggets.out");
int N;
bool numbers[256*256];
int nuggets[11];
int indices[11];
int gcd(int a, int b)
 {
  int t;

  while (b != 0)
   {
    t = a % b;
    a = b;
    b = t;
   }
  return a;
 }
int main() {
	fin>>N;
	for(int i=1;i<=N;i++)
	{
		fin>>nuggets[i];
		numbers[nuggets[i]]=1;
		if(nuggets[i]==1)
		{
			fout<<0<<endl;
			exit(0);
		}
	}
	int g=nuggets[1];
	for(int i=2;i<=N;i++)
		g=gcd(nuggets[i],g);
	if(g>1)
	{
		fout<<0<<endl;
		exit(0);
	}
	for(int i=1;i<256*256;i++)
	{
		if(numbers[i]==1)
		{
			for(int j=1;j<=N;j++)
			{
				if(i+nuggets[j]<256*256)
					numbers[i+nuggets[j]]=1;
			}
		}
	}
	for(int i=256*256-1;i>=1;i--)
	{
		if(numbers[i]!=1)
		{
			fout<<i<<endl;
			break;
		}	
	}
	fin.close();
	fout.close();
	return 0;
}
