/*
LANG:C++
TASK:rockers
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
ifstream fin("rockers.in");
ofstream fout("rockers.out");
int N,T,M;
int A[21][21][21];
int songs[21];
int main() {
	fin>>N>>T>>M;
	for(int i=1;i<=N;i++)
		fin>>songs[i];
	int best=0;
	for(int a=1;a<=M;a++)
		for(int b=0;b<=T;b++)
			for(int c=0;c<=N;c++)
			{
				for(int d=c+1;d<=N;d++)
				{
					if(b+songs[d]>T)
					{
						if(A[a][b][c]+1>A[a+1][songs[d]][d])
							A[a+1][songs[d]][d]=A[a][b][c]+1;
					}
					else
					{
						if(A[a][b][c]+1>A[a][b+songs[d]][d])
							A[a][b+songs[d]][d]=A[a][b][c]+1;
					}
				
				}
				if(A[a][b][c]>best)
						best=A[a][b][c];
			}
	fout<<best<<endl;
	fin.close();
	fout.close();
	return 0;
}
