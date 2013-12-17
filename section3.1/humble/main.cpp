/*
LANG:C++
TASK:humble
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
#include <set>
#define INF 2147483647
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
int s[100];
int indices[100];
long humbles[100001];
int k,n;
int main() {
	fin>>k>>n;
	for(int i=0;i<k;i++)
	{
		int h;
		fin>>h;
		s[i]=h;
		indices[i]=0;
	}
	humbles[0]=1;
	for(int i=1;i<=n;i++)
	{
		long min_v=INF;
		for(int j=0;j<k;j++)
		{
			int v=humbles[indices[j]]*s[j];
			if(v<min_v)
				min_v=v;
		}
		humbles[i]=min_v;
		for(int j=0;j<k;j++)
		{
			int v=humbles[indices[j]]*s[j];
			if(v==humbles[i])
				indices[j]++;
		}

	}
	fout<<humbles[n]<<endl;
	fin.close();
	fout.close();
	return 0;
}
