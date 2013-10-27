/*
ID:liujiboy
LANG:C++
TASK:ride
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long fun(char *str)
{
	long result=1;
	for(int i=0;i<strlen(str);i++)
		result*=str[i]-'A'+1;
	return result;
}
int main(int argc,char** argv)
{
	FILE *fin=fopen("ride.in","r");
	FILE *fout=fopen("ride.out","w");
	char comet[7];
	char group[7];
	fscanf(fin,"%s",comet);
	fscanf(fin,"%s",group);
	long a,b;
	a=fun(comet);
	b=fun(group);
	if(a%47==b%47)
		fprintf(fout,"%s\n","GO");
	else
		fprintf(fout,"%s\n","STAY");
	exit(0);
}
