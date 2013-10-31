/*
LANG:C++
TASK:barn1
*/
#include <fstream>
#include <iostream>
#define MAXS 201
using namespace std;
int main() {
	ifstream fin ("barn1.in");
	ofstream fout ("barn1.out");
	int gaps[MAXS],stalls[MAXS],m,s,c;
	for(int i=0;i<MAXS;i++)
	{
		gaps[i]=0;
		stalls[i]=0;
	}
	fin>>m>>s>>c;
	for(int i=0;i<c;i++)
	{
		int stall;
		fin>>stall;
		stalls[stall]=1;
	}
	int min=200,max=1,prev=0;
	for(int i=1;i<MAXS;i++)
	{
		int stall=stalls[i];
		if(stall==1)
		{
			if(i>max)
				max=i;
			if(i<min)
				min=i;
			if(prev!=0)
				gaps[i-prev-1]++;
			prev=i;
		}
	}
	int maxLength=max-min+1;
	for(int i=MAXS-1;i>=0&&m>1;i--)
	{
		while(gaps[i]>0&&m>1)
		{
			maxLength-=i;
			gaps[i]--;
			m--;
		}
	}
	fout<<maxLength<<endl;
	fin.close();
	fout.close();
	return 0;
}
