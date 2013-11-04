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
	int s[125001];
	int len;
public:
	Ariprog():Prob("ariprog")
	{
		fin>>n;
		fin>>m;
		for(int i=0;i<m+1;i++)
		{
			for(int j=0;j<m+1;j++)
				s[i*i+j*j]=1;
		}
		len=m*m*2+1;	
	}	
	void run()
	{
		bool none=true;
		for(int b=1;b<len/(n-1)+1;b++)
			for(int a=0;a<len-(n-1)*b+1;a++)
			{
				int flag=1;
				for(int k=0;k<n;k++)
				{
					int v=a+b*k;
					if(v<len)
					{
						if(s[v]!=1)
						{
							flag=0;
							break;
						}
					}else
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
		if(none)
			fout<<"NONE"<<endl;
	}
};
int main() {
	Ariprog a;
	a.run();
	return 0;
}
