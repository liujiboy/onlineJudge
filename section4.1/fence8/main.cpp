/*
LANG:C++
TASK:fence8
*/
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream fin("fence8.in");
ofstream fout("fence8.out");
int boards[51];
int rails[1024];
int min_length[1024]; //min_length[i] represents the sum of the lenth of  1-ith rails
int waste;
int total_length; //total length of all boards
int boards_len;
int rails_len;
int rail_num_by_cut=0;
bool test(int index,int start)
{
	if(index<1)
		return true;
	if(total_length-waste<min_length[rail_num_by_cut])
		return false;
	for(int i=boards_len;i>=start;i--)
	{
		if(boards[i]>=rails[index])
		{
			boards[i]-=rails[index];
			if(boards[i]<rails[1])
				waste+=boards[i];
			
			bool reval;
			if(rails[index-1]==rails[index])
				reval=test(index-1,i);
			else
				reval=test(index-1,1);
			if(boards[i]<rails[1])
				waste-=boards[i];
			boards[i]+=rails[index];
			if(reval==true)
				return true;
		}
	}
	return false;
}
int main() {
	fin>>boards_len;
	for(int i=1;i<=boards_len;i++)
	{
		fin>>boards[i];
		total_length+=boards[i];
	}
	fin>>rails_len;
	for(int i=1;i<=rails_len;i++)
	{
		fin>>rails[i];
		min_length[i]=rails[i]+min_length[i-1];
	}
	sort(rails,rails+rails_len+1);
	sort(boards,boards+boards_len+1);
	for(int i=1;i<=rails_len;i++)
	{
		if(rails[i]<=boards[boards_len])
		{
			min_length[i]=rails[i]+min_length[i-1];
		}
		else
		{
			rails_len=i;
			break;
		}
	}
	int high=rails_len;
	int low=0;
	rail_num_by_cut=(high+low)/2;
	while(low<=high)
	{
		waste=0;
		if(test(rail_num_by_cut,1))
			low=rail_num_by_cut+1;
		else
			high=rail_num_by_cut-1;

		rail_num_by_cut=(high+low)/2;
	}
	fout<<rail_num_by_cut<<endl;
	fin.close();
	fout.close();
	return 0;
}
