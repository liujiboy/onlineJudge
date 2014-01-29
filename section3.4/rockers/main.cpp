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
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=1;k<=T;k++)
			{
				if(k<songs[i])
					A[i][j][k]=max(A[i-1][j][k],A[i-1][j-1][T]);
				else
					A[i][j][k]=max(A[i-1][j][k-songs[i]],A[i-1][j-1][T])+1;
			}
	fout<<A[N][M][T]<<endl;
	fin.close();
	fout.close();
	return 0;
}
