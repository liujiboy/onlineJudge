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
inline void readFile(char* file,letter* letters,ifstream&in,int&flen,int&llen)
{
	while(in.good())
	{
		char c;
		in.get(c);
		file[flen]=c;
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
			letters[llen].c=c;
			letters[llen].pos=flen;
			llen++;
		}
		flen++;
	}
}
inline char toLowerCase(char c)
{
	if(c>='A'&&c<='Z')
	{
		c-='A'-'a';
	}
	
	return c;
	
}
inline bool isPal(letter* letters,int i,int palLen)
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
}
int main() {
	ifstream fin ("calfflac.in");
	ofstream fout ("calfflac.out");
	char file[MAXFILELEN];
	letter letters[MAXFILELEN];
	letter pal[MAXPALLEN];
	int flen=0,llen=0;
	readFile(file,letters,fin,flen,llen);
	/*for(int i=0;i<flen;i++)
		cout<<file[i];
	cout<<endl;
	for(int i=0;i<llen;i++)
		cout<<letters[i].c<<" "<<letters[i].pos<<endl;
	*/
	int palLen,start,end;
	findPal(letters,llen,palLen,start,end);
	fout<<palLen<<endl;
	for(int i=start;i<=end;i++)
		fout<<file[i];
	fout<<endl;
	fin.close();
	fout.close();
	return 0;
}
