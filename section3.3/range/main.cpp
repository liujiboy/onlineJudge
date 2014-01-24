/*
LANG:C++
TASK:range
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
#define INF 100000
using namespace std;
ifstream fin("range.in");
ofstream fout("range.out");
unsigned long count=0;
int N;
char field[251][251];
int nums[251];
int max_w[251][251];
bool is_square(int r,int c,int w)
{
	if(r+w-1<=N&&c+w-1<=N)
	{
		for(int i=r;i<r+w;i++)
			for(int j=c;j<c+w;j++)
			{
				if(field[i][j]=='0')
					return false;
			}
		return true;
	}
	else
	{
		return false;
	}

}
/*void cal_nums(int w)
{
	if(w==2)
	{
		return;
	}else
	{
		nums[w-1]+=4;
		cal_nums(w-1);
	}
}*/
void cal_nums(int r,int c,int w)
{
	if(r+w-1<=N&&c+w-1<=N)
	{
		for(int i=r;i<r+w-1;i++)
		{
			if(field[i][c+w-1]=='0')
				return;
		}
		for(int i=c;i<c+w;i++)
		{
			if(field[r+w-1][i]=='0')
				return ;
		}
		//if(w==5)
		//	cout<<r<<" "<<c<<endl;
		nums[w]++;
		max_w[r][c]=w;
		cal_nums(r,c,w+1);
	}
}
int main() {
	fin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			fin>>field[i][j];
		}
	/*for(int i=1;i<=N;i++)
	  {
	  for(int j=1;j<=N;j++)
	  {
	  cout<<field[i][j];
	  }
	  cout<<endl;
	  }*/
	for(int r=1;r<N;r++)
	{
		for(int c=1;c<N;c++)
		{
			int w=0;
			if(c>1)
			{
				w=max_w[r][c-1]-1;
			}else if(r>1)
			{
			
				w=max_w[r-1][c]-1;
			}else{
				w=0;
			}
			//cout<<r<<" "<<c<<" "<<w<<" "<<nums[2]<<endl;
			//cin.get();
			if(w>=0)
			{
				for(int i=w;i>=1;i--)
					nums[i]++;
			//	cout<<nums[2]<<endl;
				max_w[r][c]=w;
				cal_nums(r,c,w+1);
			}
			else
			{
				cal_nums(r,c,1);
			}
		}
	}
	for(int i=2;i<=N;i++)
	{
		if(nums[i]!=0)
			fout<<i<<" "<<nums[i]<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
