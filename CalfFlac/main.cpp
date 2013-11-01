/*
LANG:C++
TASK:calfflac
*/
#include <fstream>
#include<vector>
#include <iostream>
#include <ctime>
#define MAXFILELEN 20000
#define MAXPALLEN 2000
using namespace std;
typedef struct{
	char c;
	int pos;
}letter;
typedef struct{
	int pos[MAXPALLEN];
	int len;
}PLEN;
inline char toLowerCase(char c)
{
	if(c>='A'&&c<='Z')
	{
		c-='A'-'a';
	}
	
	return c;
	
}

inline void readFile(char* file,letter* letters,ifstream&in,int&flen,int&llen)
{
	while(in.good())
	{
		char c;
		in.get(c);
		file[flen]=c;
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
			letters[llen].c=toLowerCase(c);
			letters[llen].pos=flen;
			llen++;
		}
		flen++;
	}
}
/*inline bool isPal(letter* letters,int i,int palLen)
{
	for(int head=i,tail=i+palLen-1;head<=tail;head++,tail--)
	{
		if(toLowerCase(letters[head].c)!=toLowerCase(letters[tail].c))
			return false;
		//cout<<toLowerCase(letters[head].c)<<" "<<toLowerCase(letters[tail].c)<<endl;			
	}
	//cout<<i<<"  "<<palLen<<endl;
	return true;
}
inline void findPal(letter* letters,int llen,int&palLen,int&start,int&end)
{
	for(palLen=llen<MAXPALLEN?llen:MAXPALLEN;palLen>=1;palLen--)
	{
		for(int i=0;i<llen-palLen+1;i++)
		{
			if(isPal(letters,i,palLen))
			{
				start=letters[i].pos;
				end=letters[i+palLen-1].pos;
				return;
			}
		}
	}
	for(int i=0;i<llen-MAXPALLEN+1>0?llen-MAXPALLEN+1:llen;i++)
	{
		for(int j=llen>MAXPALLEN?MAXPALLEN:llen;j>palLen;j--)
		{
			if(isPale(letters,i,j))
			{
				start=letters[i].pos;
				end=letters[i+j-1].pos;
			}
		}
	}
}*/
inline bool ispal(letter* letters,int i,int j)
{
	for(int head=i,tail=j;head<=tail;head++,tail--)
	{
		if(letters[head].c!=letters[tail].c)
			return false;
		//cout<<toLowerCase(letters[head].c)<<" "<<toLowerCase(letters[tail].c)<<endl;			
	}
	//cout<<i<<"  "<<palLen<<endl;
	return true;
}

void findpal(PLEN* plen,letter* letters,int&start,int&end,int&len)
{
for(int i=MAXPALLEN-1;i>=0;i--)
	{
			for(int j=0;j<plen[i].len;j++)
			{
				int pos=plen[i].pos[j];
				if(ispal(letters,pos,pos+i))
				{
					start=letters[pos].pos;
					end=letters[pos+i].pos;
					len=i+1;
					return;
				}
			}
	}

}
int main() {
	ifstream fin ("calfflac.in");
	ofstream fout ("calfflac.out");
	char file[MAXFILELEN];
	letter letters[MAXFILELEN];
	//letter pal[MAXPALLEN];
	int flen=0,llen=0;
	clock_t start=clock();
	readFile(file,letters,fin,flen,llen);
	clock_t end=clock();
	cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	PLEN plen[MAXPALLEN];
	start=clock();
	for(int i=0;i<llen;i++)
	{
		char c=letters[i].c;
		for(int j=i+MAXPALLEN-1>llen-1?llen-1:i+MAXPALLEN-1;j>=i;j--)
		{
			if(c==letters[j].c )
			{
				//cout<<plen[j-i].len<<endl;
				plen[j-i].pos[plen[j-i].len++]=j;
			}
		}
	}
	end=clock();
	cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	int pstart,pend,len;
	start=clock();
	findpal(plen,letters,pstart,pend,len);
	end=clock();
	cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	fout<<len<<endl;
	for(int i=pstart;i<=pend;i++)
		fout<<file[i];
	fout<<endl;
		/*for(int i=0;i<flen;i++)
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
