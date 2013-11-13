/*
LANG:C++
TASK:milk3
*/
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
class bucket{
private:
	int limit;
	int now;
	int left;
public:
	bucket(int limit=0,int now=0){
		this->limit=limit;
		this->now=now;
		this->left=this->limit-this->now;
	}
	void add(int amount)
	{
		this->now+=amount;
		this->left=this->limit-this->now;
	}
	void sub(int amount)
	{
		this->now-=amount;
		this->left=this->limit-this->now;
	}
	void pourInto(bucket&other)
	{
		if(this->now>0)
		{
		//	cout<<"start:"<<this->now<<" "<<other.left<<endl;
			if(this->now>other.left)
			{	
				this->sub(other.left);
				other.add(other.left);
			}
			else
			{
				other.add(this->now);
				this->sub(this->now);
			}

		//	cout<<"end:"<<this->now<<" "<<other.left<<endl;
		}

	}
	friend class milk3;
};
class milk3{
private:
	bucket a;
	bucket b;
	bucket c;
	bool abc[21][21][21];
	bool result[21];
	void pour(bucket a,bucket b,bucket c)
	{
		if(a.now==0)
			result[c.now]=true;
		bucket a1=a,b1=b,c1=c;
		//a to b
		a1.pourInto(b1);
		//cout<<a1.now<<" "<<b1.now<<" "<<c1.now<<endl;
		if(!abc[a1.now][b1.now][c1.now])
		{
			abc[a1.now][b1.now][c1.now]=true;
			pour(a1,b1,c1);
		}
		//a to c
		a1=a;
		b1=b;
		c1=c;	
		a1.pourInto(c1);
		if(!abc[a1.now][b1.now][c1.now])
		{
			abc[a1.now][b1.now][c1.now]=true;
			pour(a1,b1,c1);
		}
		//b to a
		a1=a;
		b1=b;
		c1=c;	
		b1.pourInto(a1);
		if(!abc[a1.now][b1.now][c1.now])
		{
			abc[a1.now][b1.now][c1.now]=true;
			pour(a1,b1,c1);
		}
		//b to c
		a1=a;
		b1=b;
		c1=c;	
		b1.pourInto(c1);
		//cout<<"b to c "<<a1.now<<" "<<b1.now<<" "<<c1.now<<endl;

		if(!abc[a1.now][b1.now][c1.now])
		{
			abc[a1.now][b1.now][c1.now]=true;
			pour(a1,b1,c1);
		}
		//c to a
		a1=a;
		b1=b;
		c1=c;	
		c1.pourInto(a1);
		//cout<<"c to a "<<a1.now<<" "<<b1.now<<" "<<c1.now<<endl;
		if(!abc[a1.now][b1.now][c1.now])
		{
			abc[a1.now][b1.now][c1.now]=true;
			pour(a1,b1,c1);
		}
		//c to b
		a1=a;
		b1=b;
		c1=c;	
		c1.pourInto(b1);
		//cout<<"c to b "<<a1.now<<" "<<b1.now<<" "<<c1.now<<endl;

		if(!abc[a1.now][b1.now][c1.now])
		{
			//cout<<"true"<<endl;
			abc[a1.now][b1.now][c1.now]=true;
			pour(a1,b1,c1);
		}
		//else
		//{
			//cout<<"false"<<endl;
		//}


	}

public:
	milk3(int limita,int limitb,int limitc):a(limita),b(limitb),c(limitc,limitc)
	{
		for(int i=0;i<21;i++)
			for(int j=0;j<21;j++)
				for(int k=0;k<21;k++)
					abc[i][j][k]=false;
		for(int i=0;i<21;i++)
			result[i]=false;
	}
	void run()
	{
		pour(a,b,c);
	}
	void print(ostream&os)
	{
		for(int i=0;i<21;i++)
		{
			if(result[i])
				os<<i<<" ";
		}
	}
};
int main() {
	ifstream fin ("milk3.in");
	ofstream fout ("milk3.out");
	int a,b,c;
	fin>>a>>b>>c;
	milk3 m(a,b,c);
	m.run();
	stringstream ss;
	m.print(ss);
	string s=ss.str();
	s.erase(s.size()-1);
	fout<<s<<endl;
	fin.close();
	fout.close();
	return 0;
}
