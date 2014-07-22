/*
LANG:C++
TASK:fence8
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
ifstream fin("fence8.in");
ofstream fout("fence8.out");
int boards[51];
int rails[1024];
int boards_len;
int rails_len;
int max_cuts=0;
int c=0;
int find_max_cuts(int level)
{
	c++;
	if(level>rails_len)
		return 0;
	int max_cuts_level=0;
	bool flag=true;
	for(int j=1;j<=boards_len;j++)
	{
		if(boards[j]>=rails[level])
		{
			flag=false;
			boards[j]-=rails[level];
			int cuts=find_max_cuts(level+1);
	//		cout<<level<<"\t"<<cuts<<endl;
			boards[j]+=rails[level];
			if(cuts+1>max_cuts_level)
			{
				max_cuts_level=cuts+1;
				if(max_cuts_level>max_cuts)
					max_cuts=max_cuts_level;
				if(max_cuts_level>=rails_len-level+1||max_cuts>=rails_len-level+1)
				{
					cout<<"ok"<<endl;
					return max_cuts_level;
				}
			}
		}
	}
	cout<<level<<"\t"<<flag<<"\t"<<max_cuts<<endl;
	if(flag==true)
		return max_cuts_level;
	int cuts=find_max_cuts(level+1);
	if(cuts>max_cuts_level)
	{
		max_cuts_level=cuts;
		if(max_cuts_level>max_cuts)
			max_cuts=max_cuts_level;
	}
	return max_cuts_level;
}
int main() {
	fin>>boards_len;
	for(int i=1;i<=boards_len;i++)
		fin>>boards[i];
	fin>>rails_len;
	for(int i=1;i<=rails_len;i++)
		fin>>rails[i];
	sort(rails,rails+rails_len);
	for(int i=1;i<=rails_len;i++)
		cout<<rails[i]<<endl;
	fout<<find_max_cuts(1)<<endl;
	cout<<c<<endl;
	fin.close();
	fout.close();
	return 0;
}
