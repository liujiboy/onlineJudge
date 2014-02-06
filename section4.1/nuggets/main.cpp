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
int numbers[100001];
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
	int count=0;
	int max_i;
	for(int c=1;c<=100000;c++)
	{
		int min_n=100000;
		for(int i=1;i<=N;i++)
		{
			int n=numbers[indices[i]]+nuggets[i];
			if(n<min_n)
				min_n=n;
		}
		numbers[c]=min_n;
		if(numbers[c]-numbers[c-1]==1)
		{
			count++;
		}
		else
		{
			max_i=numbers[c]-1;
			count=0;
		}
		if(count==256)
			break;
		for(int i=1;i<=N;i++)
		{
			int n=numbers[indices[i]]+nuggets[i];
			if(n==numbers[c])
				indices[i]++;
		}
	}
	fout<<max_i<<endl;
	fin.close();
	fout.close();
	return 0;
}
