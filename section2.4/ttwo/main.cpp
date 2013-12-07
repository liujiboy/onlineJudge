/*
LANG:C++
TASK:ttwo
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
	template<class T>
void print(T a,int row,int col,ostream&out=cout)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(j!=col-1)
				out<<a[i][j]<<" ";
			else
				out<<a[i][j];
		}
		cout<<endl;
	}
}
	template<class T>
void print(T a,int len,ostream&out=cout,bool newline=false)
{
	for(int i=0;i<len;i++)
	{
		if(!newline)
		{
			if(i!=len-1)
				out<<a[i]<<" ";
			else
				out<<a[i]<<endl;
		}
		else
		{
			out<<a[i]<<endl;
		}
	}
}
	template<class T>
void init(T* a,int len,T v)
{
	for(int i=0;i<len;i++)
		a[i]=v;
}
template<class T> 
class comp{
	public:
		bool operator()(T a,T b)
		{
			return a<b;
		}
};
class Object{
public:
	int x;
	int y;
	int d;
	Object(int x,int y,int d)
	{
		this->x=x;
		this->y=y;
		this->d=d;
	}
	void move(char map[10][10])
	{
		switch(d)
		{
			case 0:
				//north
				if(y-1>=0&&map[x][y-1]=='.')
				{
					y--;
				}
				else
				{
					d=1;
				}
				break;
			case 1:
				//east
				if(x+1<10&&map[x+1][y]=='.')
				{
					x++;
				}
				else
				{
					d=2;
				}
				break;
			case 2:
				//sourth
				if(y+1<10&&map[x][y+1]=='.')
				{
					y++;
				}
				else
				{
					d=3;
				}
				break;
			case 3:
				//west
				if(x-1>=0&&map[x-1][y]=='.')
				{
					x--;
				}
				else
				{
					d=0;
				}
				break;
		}
	}
};
char map[10][10];
int main() {
	Object *cow;
	Object *farmer;
	for(int y=0;y<10;y++)
	{
		for(int x=0;x<10;x++)
		{
			char c;
			fin>>c;
			if(c=='F')
			{
				farmer=new Object(x,y,0);
				map[x][y]='.';
			}else if(c=='C')
			{
				cow=new Object(x,y,0);
				map[x][y]='.';
			}else{
				map[x][y]=c;
			}
		}
	}
	/*for(int y=0;y<10;y++)
	{
		for(int x=0;x<10;x++)
		{
			cout<<map[x][y];
		}
		cout<<endl;
	}*/
	bool flag=false;
	for(int i=1;i<160000;i++)
	{
		cow->move(map);
		farmer->move(map);
	//	cout<<"cow:"<<cow->x<<","<<cow->y<<","<<cow->d<<endl;
	//	cout<<"farmer:"<<farmer->x<<","<<farmer->y<<","<<farmer->d<<endl;
	//	cin.get();
		if(cow->x==farmer->x&&cow->y==farmer->y)
		{
			fout<<i<<endl;
			flag=true;
			break;
		}
	}
	if(flag==false)
		fout<<0<<endl;
	delete cow;
	delete farmer;
	fin.close();
	fout.close();
	return 0;
}
