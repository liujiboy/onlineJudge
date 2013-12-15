/*
LANG:C++
TASK:inflate
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
ifstream fin("inflate.in");
ofstream fout("inflate.out");
int m,n;
class Problem{
public:
	int score;
	int time;
};
vector<Problem> problems;
int A[10001];
int maxA(int y)
{
	int max=0;
	for(int i=0;i<problems.size();i++)
	{
		if(y-problems[i].time>=0)
		{
			int score=problems[i].score+A[y-problems[i].time];
			if(max<score)
				max=score;
		}
	}
	return max;
}
int main() {
	fin>>m>>n;
	for(int i=0;i<n;i++)
	{
		Problem p;
		fin>>p.score>>p.time;
		problems.push_back(p);
	}
	A[0]=0;
	for(int i=1;i<=m;i++)
	{
		int ma=maxA(i);	
		A[i]=A[i-1]>ma?A[i-1]:ma;
	}
	fout<<A[m]<<endl;
	fin.close();
	fout.close();
	return 0;
}
