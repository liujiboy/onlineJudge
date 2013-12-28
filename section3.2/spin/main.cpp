/*
LANG:C++
TASK:spin
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
ifstream fin("spin.in");
ofstream fout("spin.out");
struct area{
	int start;
	int end;
	area(int s=0,int e=0){
		start=s;
		end=e;
	}
	bool intersect(area&other,area&r)
	{
		if(other.start<=end&&other.start>=start)
		{
			r.start=other.start;
			if(end<=other.end)
			{
				r.end=end;
			}else
			{
				r.end=other.end;
			}
			return true;
		}else if(other.end<=end&&other.end>=start)
		{
			r.end=end;
			if(start>=other.start)
			{
				r.start=start;
			}else
			{
				r.start=other.start;
			}
			return true;
		}else
		{
			return false;
		}
	}	
};

struct wedge{
	int start;
	int extend;
	void rotate(int speed)
	{
		start+=speed;
	}
	void toarea(vector<area>&r)
	{
		int s=start%360;
		int e=(start+extend)%360;
		if(e<s)
		{
			r.push_back(area(s,360));
			r.push_back(area(0,e));
		}else
		{
			r.push_back(area(s,e));
		}
	}
	friend ostream&operator<<(ostream&out,const wedge&w)
	{
		out<<"wedge:"<<w.start<<","<<(w.start+w.extend);
		return out;
	}
};
struct wheel{
	int num;
	int speed;
	wedge wedges[5];
	void add(const wedge&w)
	{
		wedges[num++]=w;
	}
	void rotate()
	{
		for(int i=0;i<num;i++)
		{
			wedges[i].rotate(speed);

		}
	}
	void toarea(vector<area>&r)
	{
		for(int i=0;i<num;i++)
		{
			wedges[i].toarea(r);
		}
	}
	friend ostream&operator<<(ostream&out,const wheel&w)
	{
		out<<"wheel:"<<w.speed<<endl;
		for(int i=0;i<w.num;i++)
			out<<w.wedges[i]<<endl;
		out<<"..........."<<endl;
		return out;
	}
};
void intersect(vector<area>&v1,vector<area>&v2,vector<area>&v3)
{
	for(int i=0;i<v1.size();i++)
	{
		for(int j=0;j<v2.size();j++)
		{
			area r;
			bool f=v1[i].intersect(v2[i],r);
			if(f)
				v3.push_back(r);
		}
	}
}
int main() {
	wheel wheels[5];
	for(int i=0;i<5;i++)
	{
		fin>>wheels[i].speed;
		int num;
		fin>>num;
		for(int j=0;j<num;j++)
		{
			wedge w;
			fin>>w.start>>w.extend;
			wheels[i].add(w);
		}
	}
	bool stop=false;
	for(int i=0;i<360&&!stop;i++)
	{
		vector<area> v1;
		vector<area> v2;
		vector<area> v3;
		vector<area> v4;
		vector<area> v5;
		wheels[0].toarea(v1);
		wheels[1].toarea(v2);
		wheels[2].toarea(v3);
		wheels[3].toarea(v4);
		wheels[4].toarea(v5);
		for(int j=0;j<5;j++)
		{
			wheels[j].rotate();
		}
		vector<area> v1v2;
		intersect(v1,v2,v1v2);	
		/*cout<<"v1"<<endl;
		for(int k=0;k<v1.size();k++)
		{
			cout<<v1[k].start<<" "<<v1[k].end<<endl;
		}
		cout<<"v2"<<endl;
		for(int k=0;k<v2.size();k++)
		{
			cout<<v2[k].start<<" "<<v2[k].end<<endl;
		}
		cout<<"v1v2"<<endl;
		for(int k=0;k<v1v2.size();k++)
		{
			cout<<v1v2[k].start<<" "<<v1v2[k].end<<endl;
		}
		cin.get();*/
		if(v1v2.size()==0)
			continue;
		vector<area> v1v2v3;
		intersect(v1v2,v3,v1v2v3);
		if(v1v2v3.size()==0)
			continue;
		vector<area> v1v2v3v4;
		intersect(v1v2v3,v4,v1v2v3v4);
		if(v1v2v3v4.size()==0)
			continue;
		vector<area> v1v2v3v4v5;
		intersect(v1v2v3v4,v5,v1v2v3v4v5);
		if(v1v2v3v4v5.size()==0)
			continue;
		fout<<i<<endl;
		stop=true;
		
	}
	if(!stop)
		fout<<"none"<<endl;
	//area a(1,3);
	//area b(2,4);
	//area r;
	//a.intersect(b,r);
	//cout<<r.start<<" "<<r.end<<endl;
	fin.close();
	fout.close();
	return 0;
}
