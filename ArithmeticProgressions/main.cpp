/*
LANG:C++
TASK:ariprog
*/
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
class Prob{
	protected:
		ofstream fout;
		ifstream fin;
	public:
		Prob(string name)
		{
			fin.open((name+".in").c_str());
			fout.open((name+".out").c_str());
		}
		virtual void run()=0;
		~Prob()
		{
			fin.close();
			fout.close();
		}
};
class Ariprog:public Prob{
private:
	int m;
	int n;
	bool s[125001];
	int numbers[125001];
	int ncount;
	int max;
public:
	Ariprog():Prob("ariprog")
	{
		fin>>n;
		fin>>m;
		for(int i=0;i<m+1;i++)
		{
			for(int j=0;j<m+1;j++)
			{
				s[i*i+j*j]=true;
			}
		}
		for(int i=0;i<125001;i++)
		{
			if(s[i])
			{
				numbers[ncount++]=i;
			}
		}
		/*for(int i=0;i<ncount;i++)
			cout<<numbers[i]<<endl;*/
		max=m*m*2;	
	}	
	void run()
	{
		bool none=true;
		for(int b=1;b<=max/(n-1);b++)
		{
			for(int i=0;numbers[i]<=max-(n-1)*b;i++)
			{
				int a=numbers[i];
				int flag=1;
				for(int k=n-1;k>=0;k--)
				{
					int v=a+b*k;
					//cout<<a<<" "<<b<<endl;
					if(!s[v])
					{
							flag=0;
							break;
					}
				}
				if(flag==1)
				{
					fout<<a<<" "<<b<<endl;
					none=false;
				}
			}
		}	
		if(none)
			fout<<"NONE"<<endl;
	}
};
int main() {
	Ariprog a;
	a.run();
	return 0;
}
