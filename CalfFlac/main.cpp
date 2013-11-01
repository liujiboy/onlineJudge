/*
LANG:C++
TASK:calfflac
*/
#include <fstream>
#include <iostream>
#define MAXFILELEN 20000
#define MAXPALLEN 2000
using namespace std;
typedef struct{
	char c;
	int pos;
}letter;
inline char toLowerCase(char c)
{
	if(c>='A'&&c<='Z')
	{
		c-='A'-'a';
	}

	return c;

}
inline bool isletter(char c)
{
	if((c>='A'&&c<='Z') or (c>='a'&&c<='z'))
	{
		return true;
	}else
	{
		return false;
	}
}
inline bool ispal(char* file,int i,int j)
{
	int head=i;
	int tail=i+j-1;
	if(!isletter(file[tail]))
		return false;
	while(head<=tail)
	{
		if(!isletter(file[head]))
		{
			head++;
		}
		if(!isletter(file[tail]))
		{
			tail--;
		}
		if(isletter(file[head])&&isletter(file[tail])){
			if(toLowerCase(file[head])!=toLowerCase(file[tail]))
				return false;
			else{
				head++;
				tail--;
			}
		}
	}
	return true;
}
inline void readfile(ifstream&in,char* file,int&flen)
{
	while(in.good())
	{
		char c;
		in.get(c);
		file[flen]=c;
		flen++;
	}
}
inline void findpal(char* file,int flen,int&plen,int&start,int&end)
{
	for(int i=0;i<flen-MAXPALLEN+1;i++)
	{
		char c=file[i];
		if(isletter(c))
		{
			for(int j=flen<MAXPALLEN?flen:MAXPALLEN;j>plen;j--)
			{
				if(ispal(file,i,j))
				{
					plen=j;
					start=i;
					end=i+j-1;
					break;
				}
			}	
		}
	}
}
int main() {
	ifstream fin ("calfflac.in");
	ofstream fout ("calfflac.out");
	char file[MAXFILELEN];
	int flen,start,end,plen;
	readfile(fin,file,flen);
	findpal(file,flen,plen,start,end);
	cout<<plen<<endl;
	for(int i=start;i<=end;i++)
		fout<<file[i];
	cout<<endl;
	//cout<<"init"<<endl;
	//letter letters[2000][20000];
	/*for(int i=0;i<MAXPALLEN;i++)
	  for(int j=0;j<MAXFILELEN;j++)
	  {
	  letter l={0,0};
	  letters[i][j]=l;
	  }
	//readFile(file,letters,fin,flen,llen);
	for(int i=0;i<flen;i++)
	cout<<file[i];
	cout<<endl;
	for(int i=0;i<llen;i++)
	cout<<letters[i].c<<" "<<letters[i].pos<<endl;
	*/
	/*int palLen,start,end;
	  findPal(letters,llen,palLen,start,end);
	  fout<<palLen<<endl;
	  for(int i=start;i<=end;i++)
	  fout<<file[i];
	  fout<<endl;*/
	fin.close();
	fout.close();
	return 0;
}
