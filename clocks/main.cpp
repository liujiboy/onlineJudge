/*
LANG:C++
TASK:clocks
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
class Clocks:public Prob{
	private:
		bool stop;
		int a[10];
		int clocks[9];
		static const string cmds[9];
		void rotate()
		{
			int rclocks[9];
			for(int i=0;i<9;i++)
				rclocks[i]=clocks[i];
			for(int i=1;i<=9;i++)
			{
				for(int j=0;j<a[i];j++)
				{
					string cmd=cmds[i-1];
					for(int k=0;k<cmd.size();k++)
					{
						char c=cmd[k];
						rclocks[c-'A']=(rclocks[c-'A']+3)%12;
					}
				}
			}
			int v=0;
			for(int i=0;i<9;i++)
			{
				v+=rclocks[i];
			}
			if(v==0)
			{
				stop=true;
				stringstream ss;
				for(int j=1;j<=9;j++)
				{
					for(int k=0;k<a[j];k++)
						ss<<j<<" ";
				}
				string result=ss.str();
				result.erase(result.end()-1,result.end());
				fout<<result<<endl;
			}
		}
		void search(int start,int end,int len)
		{
			if(start==end)
			{
				if(len<=3)
				{
					a[start]=len;
					rotate();
				}
			}
			else
			{
				for(int i=3;i>=0&&!stop;i--)
				{
					if(i<=len)
					{
						a[start]=i;
						search(start+1,end,len-i);
					}
				}
			}
		}

	public:
		Clocks():Prob("clocks")
		{	stop=false;
			for(int i=0;i<9;i++)
			{
				int n;
				fin>>n;
				clocks[i]=n%12;
			}
		}	
		virtual void run()
		{	
			int len=1;
			while(!stop)
			{
				search(1,9,len);
				len++;
			}
		}
};
const string Clocks::cmds[9]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int main() {
	Clocks c;
	c.run();
	return 0;
}
