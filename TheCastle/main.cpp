/*
LANG:C++
TASK:castle
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
class Task{
private:
	ifstream fin;
	ofstream fout;
	int rooms[50][50];
	int row;
	int col;
	int castle[50][50];
	int rsize[50*50];
	int maxrsize;
	int maxrrsize;
	int rrow;
	int rcol;
	char direction;
	int rnum;
	inline void setroom(int r,int c)
	{
		if(rooms[r][c]==0)
		{
			rooms[r][c]=-1;
		}
	}
	void flood_fill()
	{
		bool flag=true;
		while(flag)
		{
			flag=false;
			for(int r=0;r<row;r++)
			{
				for(int c=0;c<col;c++)
				{
					if(rooms[r][c]==-1)
					{
						flag=true;
						rooms[r][c]=rnum;
						int w=castle[r][c];
						if((w&1)==0)
						{
							setroom(r,c-1);
						}
						if((w&2)==0)
						{
							setroom(r-1,c);
						}
						if((w&4)==0)
						{
							setroom(r,c+1);
						}
						if((w&8)==0)
						{
							setroom(r+1,c);
						}
						/*for(int r=0;r<row;r++)
						{	
							for(int c=0;c<col;c++)
								cout<<rooms[r][c]<<" ";
							cout<<endl;
						}
						cin.get();
						*/
					}
				}
			}
		}
	}
public:
	Task()
	{
		fin.open("castle.in");
		fout.open("castle.out");
	}
	~Task()
	{
		fin.close();
		fout.close();
		maxrsize=0;
	}
	void run()
	{
		fin>>col>>row;
		for(int r=0;r<row;r++)
		{
			for(int c=0;c<col;c++)
			{
				fin>>castle[r][c];
			}
		}
		for(int r=0;r<row;r++)
			for(int c=0;c<col;c++)
				rooms[r][c]=0;
		rnum=0;
		for(int r=0;r<row;r++)
		{
			for(int c=0;c<col;c++)
			{
				if(rooms[r][c]==0)
				{	
					rnum++;
					rooms[r][c]=-1;
					flood_fill();
				}

			}
		}
		for(int i=0;i<=rnum;i++)
		{
			rsize[i]=0;
		}
		for(int r=0;r<row;r++)
		{
			for(int c=0;c<col;c++)
			{
				rsize[rooms[r][c]]++;
			}
		}
		for(int i=1;i<=rnum;i++)
		{
			if(maxrsize<rsize[i])
				maxrsize=rsize[i];
		}
		maxrrsize=maxrsize;

		for(int c=0;c<col;c++)
		{
			for(int r=row-1;r>=0;r--)
			{
				int w=castle[r][c];
				int n=rooms[r][c];
				if(w&2)
				{
					if(r-1>0)
					{
						int nn=rooms[r-1][c];
						if(nn!=n)
						{
							if(maxrrsize<rsize[nn]+rsize[n])
							{
								maxrrsize=rsize[nn]+rsize[n];
								rrow=r;
								rcol=c;
								direction='N';
							}
						}

					}
				}
				if(w&4)
				{
					if(c+1<col)
					{
						int nn=rooms[r][c+1];
						if(nn!=n)
						{
							if(maxrrsize<rsize[nn]+rsize[n])
							{
								maxrrsize=rsize[nn]+rsize[n];
								rrow=r;
								rcol=c;
								direction='E';
							}
						}
					}
				}
			}

		}	
		fout<<rnum<<endl;
		fout<<maxrsize<<endl;
		fout<<maxrrsize<<endl;
		fout<<rrow+1<<" "<<rcol+1<<" "<<direction<<endl;
		
	}
};
int main() {
	Task t;
	t.run();
	return 0;
}
