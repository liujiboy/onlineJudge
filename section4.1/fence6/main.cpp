/*
LANG:C++
TASK:fence6
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_VERTEX_SIZE 200
#define INF 0xFFFF
#define MAX_EDGE_SIZE 100
#define MAX_ITEM_SIZE 8
using namespace std;
ifstream fin("fence6.in");
ofstream fout("fence6.out");
struct Edge{
	int ls;
	int v1[MAX_ITEM_SIZE];
	int v2[MAX_ITEM_SIZE];
	Edge()
	{
		memset(v1,0,MAX_ITEM_SIZE);
		memset(v2,0,MAX_ITEM_SIZE);
	}
};
Edge edges[MAX_EDGE_SIZE];
int dist[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
int nv; //number of vertex;
int *vertices[MAX_VERTEX_SIZE];
int find_vertex(int *v)
{
	int i;
	for(i=0;i<nv;i++)
	{
		int j;
		for(j=0;j<MAX_ITEM_SIZE;j++)
		{
			if(vertices[i][j]!=v[j])
				break;
		}
		if(j!=MAX_ITEM_SIZE)
			continue;
		else
			break;
	}
	if(i==nv)
	{
		//append v to vertices
		vertices[nv++]=v;
	}
	return i;
}
int dijkstra(int start,int end)
{
	int min_len[MAX_VERTEX_SIZE];
	bool visited[MAX_VERTEX_SIZE];
	memset(visited,false,MAX_VERTEX_SIZE);
	for(int i=0;i<nv;i++)
		min_len[i]=dist[start][i]==0?INF:dist[start][i];
	min_len[start]=0;
	visited[start]=true;
	while(true)
	{
		int min=INF;
		int w;
		for(int i=0;i<nv;i++)
		{
			if(!visited[i]&&min_len[i]<=min)
			{
				min=min_len[i];
				w=i;
			}
		}
	/*	for(int i=0;i<nv;i++)
			cout<<min_len[i]<<"\t";
		cout<<endl;
		for(int i=0;i<nv;i++)
			cout<<visited[i]<<"\t";
		cout<<endl;

		cout<<w<<"\t"<<min<<endl;*/
	//	if(w==6)
	//		cin.get();
		if(w==end)
			return min_len[w];
		visited[w]=true;
		for(int i=0;i<nv;i++)
		{
			if(!visited[i])
			{
				if(min_len[w]!=INF&&dist[w][i]!=0)
				{
					if(min_len[i]>min_len[w]+dist[w][i])
						min_len[i]=min_len[w]+dist[w][i];
				}
			}
		}
	}



}
int main() {
	int n,s,ls,ns1,ns2;
	fin>>n;
	for(int i=0;i<n;i++)
	{
		fin>>s>>ls>>ns1>>ns2;
		edges[i].ls=ls;
		edges[i].v1[0]=s;
		edges[i].v2[0]=s;
		for(int j=1;j<=ns1;j++)
		{
			fin>>edges[i].v1[j];
		}
		for(int j=1;j<=ns2;j++)
		{
			fin>>edges[i].v2[j];
		}
		sort(edges[i].v1,edges[i].v1+MAX_ITEM_SIZE);
		sort(edges[i].v2,edges[i].v2+MAX_ITEM_SIZE);
	}
	for(int i=0;i<n;i++)
	{
		int iv1=find_vertex(edges[i].v1);
		int iv2=find_vertex(edges[i].v2);
		dist[iv1][iv2]=edges[i].ls;		
		dist[iv2][iv1]=edges[i].ls;
		//cout<<iv1<<"\t"<<iv2<<"\t"<<edges[i].ls<<endl;
	}
	//cout<<nv<<endl;
	int shortest=INF;
	for(int i=0;i<nv;i++)
	{
		for(int j=i+1;j<nv;j++)
		{
			if(dist[i][j]!=0)
			{
				int old=dist[i][j];
				dist[i][j]=0;
				dist[j][i]=0;
				//cout<<i<<"\t"<<j<<"\t"<<endl;	
				int d=dijkstra(i,j);
				//cout<<i<<"\t"<<j<<"\t"<<s<<endl;
	//			cin.get();
				dist[i][j]=old;
				dist[j][i]=old;
				if(old+d<shortest)
				{
					shortest=d+old;
				//	cout<<s<<"\t"<<d<<endl;
				}
			}
		}
	}
	fout<<shortest<<endl;
	fin.close();
	fout.close();
	return 0;
}
