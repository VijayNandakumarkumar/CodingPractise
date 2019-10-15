#include<bits/stdc++.h>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	vector <int> v;
	vector <int>::iterator itr;
	vector <int> :: reverse_iterator rtr;
	for(int i=0;i<=10;i++)
	{
		v.push_back(i*10);
	}
	/*for(itr=v.begin();itr!=v.end();itr++)
	{
		cout<<"\t"<<*itr;
	}*/
	cout<<"\n"<<"rtr"<<"\n";
	for(rtr = v.rbegin();rtr!=v.rend();rtr++)
	{
		cout<<"\t"<<*rtr;
	}
	cout<<"\n"<<"rtr.end"<<"\n";
	for(rtr=v.rend();rtr<v.rbegin();rtr++)
	{
		cout<<"\t"<<*rtr;
	}
	cout<<"\n"<<v.size()<<"\t"<<v.max_size()<<"\t"<<v.capacity()<<"\n";
	int sum =0;
	int i=0;
	for(itr = v.begin();itr!=v.end();itr++)
{cout<<"h";
	sum += *itr;
}
while(i!=v.size())
{
	sum+=v[i];
	i++;
}
cout<<"\n"<<v.front()<<"\t"<<v.back()<<"\t"<<v.at(4);
	while(!v.empty())
{
	sum += v.back();
	v.pop_back();
}

for(itr = v.begin();itr!=v.end();itr++)
{cout<<"h";
	sum += *itr;
}

cout<<"\n"<<"sum is"<<sum;
	return 0;
}
