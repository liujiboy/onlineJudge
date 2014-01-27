/*
LANG:C++
TASK:fence4
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
#define INF 100000
#define EPS 0.1
using namespace std;
ifstream fin("fence4.in");
ofstream fout("fence4.out");
struct line{
	int i1;
	int i2;
};
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
	int z=cross(ba,ca)*cross(ba,da);
	if(z==0)
		return 0;
	else if(z>0)
		return 1;
	else
		return -1;
}
void min_max(float a,float b,float&min_v,float&max_v)
{
	if(a>b)
	{
		min_v=b;
		max_v=a;
	}else
	{
		min_v=a;
		max_v=b;
	}
}
bool line_seg_intersect(const point& a,const point& b,const point& c,const point& d)
{
	float minx1,miny1,minx2,miny2,maxx1,maxx2,maxy1,maxy2;
	min_max(a.x,b.x,minx1,maxx1);
	min_max(a.y,b.y,miny1,maxy1);
	min_max(c.x,d.x,minx2,maxx2);
	min_max(c.y,d.y,miny2,maxy2);
	/*int minx,miny,maxx,maxy;
	cout<<minx1<<" "<<maxx1<<endl;
	cout<<miny1<<" "<<maxy1<<endl;
	cout<<minx2<<" "<<maxx2<<endl;
	cout<<miny2<<" "<<maxy2<<endl;
	minx=min(minx1,minx2);
	miny=min(miny1,miny2);
	maxx=max(maxx1,maxx2);
	maxy=max(maxy1,maxy2);
	cout<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
	if(minx>maxx||miny>maxy)
		return false;
	else 
		return true;*/
	if(maxx1<minx2||maxx2<minx1)
		return false;
	if(maxy1<miny2||maxy2<miny1)
		return false;
	return true;
}
bool line_seg_cross(const point& a,const point& b,const point& c,const point& d)
{
	if(line_seg_intersect(a,b,c,d))
	{
		int z1=sameside(a,b,c,d);
		int z2=sameside(c,d,a,b);
		if(z1>0||z2>0)
		{
			return false;
		}else
		{
			return true;
		}
	}

	return false;
}

point person;
point corners[200];
int corners_size;
vector<line> lines;
bool isvalid()
{
	for(int i=2;i<corners_size;i++)
	{
		point a=corners[i];
		point b=corners[(i+1)%corners_size];
		for(int j=i-1;j>0;j--)
		{
			if(i==corners_size-1&&j==1)
				break;
			point c=corners[j];
			point d=corners[j-1];

			if(line_seg_cross(a,b,c,d))
				return false;
		}
	}
	return true;
}
bool cansee(const point&a,const point&b,int index)
{
	point c((a.x+b.x)/2,(a.y+b.y)/2);
	bool a_cansee=true;
	bool b_cansee=true;
	bool c_cansee=true;
	for(int i=0;i<corners_size;i++)
	{
		if(i==index)
			continue;
		point p1=corners[i];
		point p2=corners[(i+1)%corners_size];
		bool t1=line_seg_cross(person,a,p1,p2);
		bool t2=line_seg_cross(person,b,p1,p2);
		bool t3=line_seg_cross(person,c,p1,p2);
		if(t1&&t2)
		{
	//		cout<<"t1&&t2:"<<a<<" "<<b<<" "<<c<<p1<<" "<<p2<<endl;
			return false;
		}
		if(t1)
		{
	//		cout<<"t1:"<<a<<" "<<b<<" "<<c<<p1<<" "<<p2<<endl;
			a_cansee=false;
		}
		if(t2)
		{
	//		cout<<"t2:"<<a<<" "<<b<<" "<<c<<p1<<" "<<p2<<endl;
			b_cansee=false;
		}
		if(t3)
		{
	//		cout<<"t3:"<<a<<" "<<b<<" "<<c<<p1<<" "<<p2<<endl;
			c_cansee=false;
		}
	//	cout<<a_cansee<<" "<<b_cansee<<" "<<c_cansee<<endl;
		if(!a_cansee&&!b_cansee&&!c_cansee)
			break;
	}
	if(!a_cansee&&!b_cansee&&!c_cansee)
	{
	//	cout<<"test"<<endl;
		float length=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
		//cout<<length<<endl;
		if(length<=0.00001)
		{
	//		cout<<"test length "<<length<<" "<<a<<" "<<b<<endl;
			return false;
		}

		if(cansee(a,c,index)||cansee(c,b,index))
			return true;
		else
			return false;
	}
	else
	{
		return true;
	}
}
bool cmp(line l1,line l2)
{
	if(l1.i2<l2.i2)
		return true;
	else if(l1.i2>l2.i2)
		return false;
	else if(l1.i2==l2.i2)
	{
		return l1.i1<l2.i1;
	}
	return l1.i2<l2.i2;
}
int main() {
	fin>>corners_size;
	fin>>person.x>>person.y;
	for(int i=0;i<corners_size;i++)
		fin>>corners[i].x>>corners[i].y;
	//cout<<cansee(corners[0],corners[1],0)<<endl;
		//cout<<line_seg_cross(person,point(2.5,0),point(2,0),point(3,0))<<endl;
	if(isvalid())
	{
		for(int i=0;i<corners_size;i++)
		{
			point a=corners[i];
			point b=corners[(i+1)%corners_size];
	//		cout<<a<<" "<<b<<endl;
			if(cansee(a,b,i))
			{
				line l;
				if(i<(i+1)%corners_size)
				{
					l.i1=i;
					l.i2=(i+1)%corners_size;
				}
				else{
					l.i1=(i+1)%corners_size;
					l.i2=i;
				}
				lines.push_back(l);
			}
		}
		sort(lines.begin(),lines.end(),cmp);
		fout<<lines.size()<<endl;
		for(int i=0;i<lines.size();i++)
		{
			point p1=corners[lines[i].i1];
			point p2=corners[lines[i].i2];
			fout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<endl;
		}
	}
	else{
		fout<<"NOFENCE"<<endl;
	}
	/*point a(0,0);
	point b(1,1);
	point c(2,2);
	point d(3,3);
	cout<<sameside(a,b,c,d);
	cout<<sameside(c,d,a,b);
	cout<<line_seg_intersect(a,b,c,d);*/
	fin.close();
	fout.close();
	return 0;
}
