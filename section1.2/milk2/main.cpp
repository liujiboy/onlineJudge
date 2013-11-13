/*
LANG:C++
TASK:milk2
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
typedef struct{
	int start;
	int end;
}milking;
bool cmp(const milking&a,const milking&b)
{
	return a.start<b.start;
}
int main(int argc,char** argv)
{
	ifstream in("milk2.in");
	ofstream out("milk2.out");
	int n;
	vector<milking> v;
	in>>n;
	for(int i=0;i<n;i++)
	{
		milking m;
		in>>m.start>>m.end;
		v.push_back(m);
	}
	sort(v.begin(),v.end(),cmp);
	for(vector<milking>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<it->start<<" "<<it->end<<endl;
	}
	
	int max1=0;
	int max2=0;
	int start=v[0].start;
	int end=v[0].end;
	for(vector<milking>::iterator it=v.begin()+1;it!=v.end();it++)
	{
		int val=it->start-end;
		if(val<=0)
		{
			if(it->end>end)
				end=it->end;
		}
		else
		{
			if(max1<end-start)
			{
				max1=end-start;
			}
			if(max2<val)
			{
				max2=val;
			}
			start=it->start;
			end=it->end;
		}
	}
	if(max1<end-start)
	{
		max1=end-start;
	}
	out<<max1<<" "<<max2<<endl;
	return 0;
}
