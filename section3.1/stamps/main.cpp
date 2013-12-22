/*
LANG:C++
TASK:stamps
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
ifstream fin("stamps.in");
ofstream fout("stamps.out");
int k,n;
int stamp_values[200*10000+1];
vector<int> stamps;
int max_stamp;
bool cmp(int a,int b)
{
	return a>b;
}
int main() {
	fin>>k>>n;
	for(int i=0;i<n;i++)
	{
		int stamp;
		fin>>stamp;
		stamps.push_back(stamp);
	}
	sort(stamps.begin(),stamps.end(),cmp);
	stamp_values[0]=0;
	for(int i=1;i<=200*10000;i++)
	{
		int min_num=k+1;
		for(int j=0;j<stamps.size();j++)
		{
			int v=i-stamps[j];
			if(v>=0)
			{
				if(min_num>stamp_values[v]+1)
						min_num=stamp_values[v]+1;
			}
		}
		if(min_num==k+1)
			break;
		else
		{
			stamp_values[i]=min_num;
			max_stamp=i;
		}
	}
	fout<<max_stamp<<endl;
	fin.close();
	fout.close();
	return 0;
}
