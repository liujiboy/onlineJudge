/*
LANG:C++
TASK:numtri
*/
#include <fstream>
#include <vector>
#include <iostream>
#define R 1000
using namespace std;
int main() {
	ifstream fin ("numtri.in");
	ofstream fout ("numtri.out");
	int value[R][R];
	int r;
	fin>>r;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<=i;j++)
		{
			fin>>value[i][j];
		}
	}
	if(r==1)
		fout<<value[0][0]<<endl;
	else
	{
		for(int i=1;i<r;i++)
			for(int j=0;j<i+1;j++)
			{
				if(j!=0)
				{
					if(value[i-1][j-1]+value[i][j]>value[i-1][j]+value[i][j])
						value[i][j]=value[i-1][j-1]+value[i][j];
                			else
                    				value[i][j]=value[i-1][j]+value[i][j];
				}
				else
				{
					value[i][j]=value[i-1][j]+value[i][j];
				}
			}
		int max=0;
		for(int i=r-1,j=0;j<r;j++)
		{
			if(value[i][j]>max)
				max=value[i][j];
		}
		fout<<max<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
