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
char toLowerCase(char c)
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
int findpal(letter* letters,int left,int right,int llen)
{
	int len=0;
	for(int i=left,j=right;i>=0&&j<=llen-1;i--,j++,len++)
	{
		if(letters[i].c!=letters[j].c)
			break;
	}
	return len;
}
int main() {
	ifstream fin ("calfflac.in");
	ofstream fout ("calfflac.out");
	char file[MAXFILELEN];
	letter letters[MAXFILELEN];
	int flen=0,llen=0;
	readFile(file,letters,fin,flen,llen);
	int pallen=0,start,end;
	for(int i=0;i<llen;i++)
	{
		// i is the center
		int len=findpal(letters,i-1,i+1,llen);
		if(2*len+1>pallen)
		{
			pallen=2*len+1;
			start=i-len;
			end=i+len;
		}
		// i is the first elem of letf side
		len=findpal(letters,i,i+1,llen);
		if(2*len>pallen)
		{
			pallen=2*len;
			start=i-len+1;
			end=i+len;
		}
	}

	fout<<pallen<<endl;
	for(int i=letters[start].pos;i<=letters[end].pos;i++)
		fout<<file[i];
	fout<<endl;
	fin.close();
	fout.close();
	return 0;
}
