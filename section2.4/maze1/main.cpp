/*
LANG:C++
TASK:maze1
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
ifstream fin("maze1.in");
ofstream fout("maze1.out");
char maze[2*38+1][2*100+1];
int w;
int h;
typedef struct{
	int x;
	int y;
}pos;
pos exits[2];
int d1[2*38+1][2*100+1];
int d2[2*38+1][2*100+1];
void find(int d[2*38+1][2*100+1],pos exit)
{
	queue<pos> q;
	d[exit.x][exit.y]=1;
	q.push(exit);
	while(!q.empty())
	{
		pos p=q.front();
		q.pop();
		int x=p.x;
		int y=p.y;
		if(x-1>=0&&maze[x-1][y]==' '&&d[x-1][y]==0)
		{
			d[x-1][y]=d[x][y]+1;
			pos n;
			n.x=x-1;
			n.y=y;
			q.push(n);
		}

		//x+1,y
		if(x+1<2*w+1&&maze[x+1][y]==' '&&d[x+1][y]==0)
		{
			d[x+1][y]=d[x][y]+1;
			pos n;
			n.x=x+1;
			n.y=y;
			q.push(n);
		}
		//x,y-1
		if(y-1>=0&&maze[x][y-1]==' '&&d[x][y-1]==0)
		{
			d[x][y-1]=d[x][y]+1;
			pos n;
			n.x=x;
			n.y=y-1;
			q.push(n);
		}
		//x,y+1
		if(y+1<2*h+1&&maze[x][y+1]==' '&&d[x][y+1]==0)
		{
			d[x][y+1]=d[x][y]+1;
			pos n;
			n.x=x;
			n.y=y+1;
			q.push(n);
		}
		/*for(int y=0;y<2*h+1;y++)
		  {
		  for(int x=0;x<2*w+1;x++)
		  {
		  cout<<distances[x][y]<<"\t";
		  }
		  cout<<endl;
		  }
		  cin.get();
		  */
	}
}


int main() {
	fin>>w>>h;
	fin.get();
	char c;
	int len=0;
	for(int y=0;y<2*h+1;y++)
	{
		for(int x=0;x<2*w+1;x++)
		{
			fin.get(c);
			maze[x][y]=c;
			if(c==' '&&(x==0||y==0||x==2*w||y==2*h))
			{
				exits[len].x=x;
				exits[len].y=y;
				len++;
			}
		}
		fin.get(c);
	}
	/*for(int y=0;y<2*h+1;y++)
	  {
	  for(int x=0;x<2*w+1;x++)
	  {
	  cout<<maze[x][y];
	  }
	  cout<<endl;
	  }*/
	//int d1[2*38+1][2*100+1];
	//int d2[2*38+1][2*100+1];
	find(d1,exits[0]);
	/*for(int y=0;y<2*h+1;y++)
	  {
	  for(int x=0;x<2*w+1;x++)
	  {
	  cout<<d1[x][y]<<"\t";
	  }
	  cout<<endl;
	  }
	 */
	find(d2,exits[1]);
	int max=0;
	for(int y=0;y<2*h+1;y++)
	{
		for(int x=0;x<2*w+1;x++)
		{
			if(d1[x][y]>d2[x][y])
				d1[x][y]=d2[x][y];
			if(d1[x][y]>max)
				max=d1[x][y];
		}
	}
	fout<<max/2<<endl;	
	fin.close();
	fout.close();
	return 0;
}
