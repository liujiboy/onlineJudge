/*
LANG:C++
TASK:cowtour
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
typedef struct{
	double x;
	double y;
}pos;
vector<pos> pastures;
vector<double> max_paths;
double path[150][150];
int n;
double diameter=0;
int main() {
	fin>>n;
	for(int i=0;i<n;i++)
	{
		pos p;
		fin>>p.x>>p.y;
		pastures.push_back(p);
	}
	fin.get();
	for(int row=0;row<n;row++)
	{
		for(int col=0;col<n;col++)
		{
			char flag;
			fin.get(flag);
			if(flag=='1')
			{
				path[row][col]=sqrt(pow(pastures[row].x-pastures[col].x,2)+pow(pastures[row].y-pastures[col].y,2));
			}else
			{
				if(row==col)
					path[row][col]=0;
				else
					path[row][col]=-1;
			}	
		}
		fin.get();
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(path[i][j]==-1&&path[i][k]!=-1&&path[k][j]!=-1)
				{
					path[i][j]=path[i][k]+path[k][j];
				}else if(path[i][j]!=-1&&path[i][k]!=-1&&path[k][j]!=-1)
				{
					if(path[i][j]>path[i][k]+path[k][j])
						path[i][j]=path[i][k]+path[k][j];
				}
			}
	for(int row=0;row<n;row++)
	{
		double max=0;
		for(int col=0;col<n;col++)
		{
			if(path[row][col]>max)
				max=path[row][col];
		}
		max_paths.push_back(max);
		if(max>diameter)
			diameter=max;
	}
	double min=-1;
	for(int row=0;row<n;row++)
	{
		for(int col=row;col<n;col++)
		{
			if(path[row][col]==-1)
			{
				double length=max_paths[row]+max_paths[col]+sqrt(pow(pastures[row].x-pastures[col].x,2)+pow(pastures[row].y-pastures[col].y,2));

				if(min==-1||min>length)
				{
						min=length;
				}
			}
		}
	}
	if(min>diameter)
		diameter=min;
	fout.precision(6);
	fout.setf(ios::fixed,ios::floatfield);	
	fout<<diameter<<endl;
	fin.close();
	fout.close();
	return 0;
}
