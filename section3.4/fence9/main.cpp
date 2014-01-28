/*
LANG:C++
TASK:fence9
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
using namespace std;
ifstream fin("fence9.in");
ofstream fout("fence9.out");
struct vec{
	float x;
	float y;
	vec(float x=0,float y=0){
		this->x=x;
		this->y=y;
	}
};
struct point{
	float x;
	float y;
	point(float x=0,float y=0){
		this->x=x;
		this->y=y;
	}

	friend vec operator-(const point&a,const point&b)
	{
		vec v;
		v.x=a.x-b.x;
		v.y=a.y-b.y;
		return v;
	}
	friend ostream&operator<<(ostream&out,const point&p)
	{
		out<<"("<<p.x<<","<<p.y<<")";
		return out;
	}
};

float cross(const vec&u,const vec&v)
{
	return u.x*v.y-u.y*v.x;
}
int sameside(const point&a,const point&b,const point&c,const point&d)
{
	vec ba=b-a;
	vec ca=c-a;
	vec da=d-a;
	//cout<<ba.x<<","<<ba.y<<" "<<ca.x<<","<<ca.y<<" "<<da.x<<","<<da.y<<endl;
	float z1=cross(ba,ca);
	float z2=cross(ba,da);
	if(z1==0||z2==0)
		return 0;
	else if(z1>0&&z2>0)
		return 1;
	else if(z1<0&&z2<0)
		return 1;
	else
		return -1;
}
int n,m,p;
int main() {
	fin>>n>>m>>p;
	float k1=(float)n/(float)m;
	float b1=0;
	float k2=(float)(n-p)/(float)m;
	float b2=p;
	int num=0;
	for(int y=1;y<m;y++)
	{
		float x1=k1*y;
		float x2=k2*y;
		int left=ceil(x1);
		int right=floor(x2);
		if(left==x1)
		{
			left++;
		}
		if(right==x2)
		{
			right--;
		}
		left+=b1;
		right+=b2;
		if(right>=left)
			num+=right-left+1;
	}
	fout<<num<<endl;
	/*point a(0,0);
	point b(n,m);
	point c(p,0);
	point center((a.x+b.x+c.x)/3,(a.y+b.y+c.y)/3);
	long num=0;
	int maxx=max(n,p);
	for(int y=1;y<m;y++)
	{
		int rx=0;
		int lx=1;
		cout<<y<<endl;
		for(int x=1;x<maxx;x++)
		{
			point l(x,y);
			int z1=sameside(a,b,l,center);
			int z2=sameside(b,c,l,center);
			int z3=sameside(a,c,l,center);
//			cout<<"left:"<<l<<" "<<z1<<" "<<z2<<" "<<z3<<endl;
			if(z1==1&&z2==1&&z3==1)
			{
				lx=x;
				break;
			}
		}
		for(int x=maxx-1;x>=1;x--)
		{
			point l(x,y);
			int z1=sameside(a,b,l,center);
			int z2=sameside(b,c,l,center);
			int z3=sameside(a,c,l,center);
//			cout<<"right:"<<l<<" "<<z1<<" "<<z2<<" "<<z3<<endl;
			if(z1==1&&z2==1&&z3==1)
			{
				rx=x;
				break;
			}
		}
		num+=rx-lx+1;
		//cout<<num<<endl;
	}
	fout<<num<<endl;*/
	fin.close();
	fout.close();
	return 0;
}
