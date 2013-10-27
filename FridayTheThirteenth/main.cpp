/*
LANG:C++
TASK:friday
*/
#include<iostream>
#include<fstream>
using namespace std;
int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
		return true;
	else
		return false;
}
int diff(int year,int month,int day)
{
	int total=0;
	for(int i=1900;i<year;i++)
	{
		if(isLeapYear(i))
		{
			total+=366;
		}else
		{
			total+=365;
		}
	}
	for(int i=1;i<month;i++)
	{
		if(i!=2)
		{
			total+=months[i-1];
		}
		else
		{
			if(isLeapYear(year))
			{
				total+=29;
			}else
			{
				total+=months[i-1];
			}
		}
	}
	total+=day;
	return total;
}
int main()
{
	int counts[]={0,0,0,0,0,0,0};
	ifstream in("friday.in");
	ofstream out("friday.out");
	int n;
	in>>n;
	for(int year=1900;year<1900+n;year++)
	{
		for(int month=1;month<13;month++)
		{
			int total=diff(year,month,13);
			counts[(total-1+2)%7]+=1;
		}
	}
	for(int i=0;i<6;i++)
		out<<counts[i]<<" ";
	out<<counts[6]<<endl;
	in.close();
	out.close();
	return 0;
}

