/*
LANG:C++
TASK:clocks
*/
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
bool stop=false;
int a[10];
int clocks[9];
string cmds[9]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};

ofstream fout ("clocks.out");
void rotate(int *clocks,int *a)
{
	int rclocks[9];
	for(int i=0;i<9;i++)
		rclocks[i]=clocks[i];
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			string cmd=cmds[i-1];
			for(int k=0;k<cmd.size();k++)
			{
				char c=cmd[k];
				rclocks[c-'A']=(rclocks[c-'A']+3)%12;
			}
		}
	}
	int v=0;
	for(int i=0;i<9;i++)
	{
		v+=rclocks[i];
	}
	if(v==0)
	{
		stop=true;
		stringstream ss;
		for(int j=1;j<=9;j++)
		{
			for(int k=0;k<a[j];k++)
				ss<<j<<" ";
		}
		string result=ss.str();
		result.erase(result.end()-1,result.end());
		fout<<result<<endl;
	}
}
void search(int *a,int start,int end,int len)
{
	if(start==end)
	{
		if(len<=3)
		{
			a[start]=len;
			rotate(clocks,a);
		}
	}
	else
	{
			for(int i=3;i>=0&&!stop;i--)
			{
				if(i<=len)
				{
					a[start]=i;
					search(a,start+1,end,len-i);
				}
			}
	}
}
int main() {
	ifstream fin ("clocks.in");
	for(int i=0;i<9;i++)
	{
		int n;
		fin>>n;
		clocks[i]=n%12;
	}	
	int len=1;
	while(!stop)
	{
		search(a,1,9,len);
		len++;
	}
	fin.close();
	fout.close();
	return 0;
}
