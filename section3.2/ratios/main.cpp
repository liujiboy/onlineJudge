/*
LANG:C++
TASK:ratios
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
ifstream fin("ratios.in");
ofstream fout("ratios.out");
int a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
int min_v=301;
int min_i;
int min_j;
int min_k;
int min_d;
int main() {
	fin>>a1>>a2>>a3>>b1>>b2>>b3>>c1>>c2>>c3>>d1>>d2>>d3;
	for(int l=1;l<=100;l++)
	{
		for(int i=0;i<=100;i++)
		{
			for(int j=0;j<=100;j++)
			{
				for(int k=0;k<=100;k++)
				{
					int v=i+j+k;
					if(v>min_v)
						continue;
					int w1=b1*i+c1*j+d1*k;
					int w2=b2*i+c2*j+d2*k;
					int w3=b3*i+c3*j+d3*k;
					if(w1==a1*l&&w2==a2*l&&w3==a3*l)
					{
							min_v=v;
							min_i=i;
							min_j=j;
							min_k=k;
							min_d=l;
					}
				}
			}
		}	
	}
	if(min_v!=301)
		fout<<min_i<<" "<<min_j<<" "<<min_k<<" "<<min_d<<endl;
	else
		fout<<"NONE"<<endl;
	fin.close();
	fout.close();
	return 0;
}
