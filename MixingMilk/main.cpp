/*
LANG:C++
TASK:milk
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
class Farmer{
private:
	int price;
	int amount;
public:
	Farmer(int price,int amount)
	{
		this->price=price;
		this->amount=amount;
	}
	int getPrice() const
	{
		return this->price;
	}
	int getAmount() const
	{
		return this->amount;
	}
};
bool cmp(const Farmer&f1,const Farmer&f2)
{
	return f1.getPrice()<f2.getPrice();
}
int main(int argc,char** argv)
{
	ifstream in("milk.in");
	ofstream out("milk.out");
	int totalAmount,farmerNum;
	in>>totalAmount>>farmerNum;
	vector<Farmer> farmers;
	for(int i=0;i<farmerNum;i++)
	{
		int price,amount;
		in>>price>>amount;
		Farmer f(price,amount);
		farmers.push_back(f);
	}
	sort(farmers.begin(),farmers.end(),cmp);
	int totalPrice=0;
	for(int i=0;i<farmers.size();i++)
	{
		Farmer f=farmers[i];
		if(totalAmount-f.getAmount()>0)
		{
			totalAmount-=f.getAmount();
			totalPrice+=f.getPrice()*f.getAmount();
		}
		else
		{
			totalPrice+=totalAmount*f.getPrice();
			totalAmount=0;
			break;	
		}
	}
	out<<totalPrice<<endl;
	in.close();
	out.close();
	return 0;

}
