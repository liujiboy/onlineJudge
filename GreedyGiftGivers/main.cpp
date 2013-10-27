/*
LANG:C++
TASK:gift1
 */
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
int main(int argc,char** argv)
{
	ifstream in("gift1.in");
	ofstream out("gift1.out");
	int np;
	in>>np;
	map<string,int> givers;
	vector<string> giverNames;
	for(int i=0;i<np;i++)
	{
		string name;
		in>>name;
		giverNames.push_back(name);
		givers[name]=0;
	}
	for(int i=0;i<np;i++)
	{
		string name;
		in>>name;
		int total,num;
		in>>total>>num;
		if(num!=0)
		{
			givers[name]+=total%num-total;
			for(int j=0;j<num;j++)
			{
				string reciever;
				in>>reciever;
				givers[reciever]+=total/num;
			}
		}
		else
			givers[name]+=total;
	}
	for(vector<string>::const_iterator it=giverNames.begin();it!=giverNames.end();it++)
	{
		out<<*it<<" "<<givers[*it]<<endl;
	}
	in.close();
	out.close();
	return 0;
}
