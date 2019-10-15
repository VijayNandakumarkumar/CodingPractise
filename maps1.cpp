#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;
int main()
{
	map <int, int> a;
	map<string, int> m;
	m["vijay"]=1;
	//int c = m.find("vijay");
	cout<<"hi"<<m["vijay"]<<endl;
	

	a[0] = 1;
	a[1] = 2;
	a[3] = 4;cout<<"hello";//<< a.find(2);//	cout<<"c is"<<c<<endl;
	map <int, int>:: iterator itr;
	for(int i = 0;i < a.size();i++)
	{
		cout<<a[i]<<"\n";
	 } 
	 cout<<endl<<"key"<<"\t"<<"value"<<"\n";
	 for(itr=a.begin();itr!=a.end(); itr++)
	 {
	 	cout<<itr->first<<"\t"<<itr->second<<"\n";
	 }
	 map <int, int> b(a.begin(), a.end());
	 cout<<endl<<"key"<<"\t"<<"value"<<"\n";
	 for(itr=b.begin();itr!=b.end(); itr++)
	 {
	 	cout<<itr->first<<"\t"<<itr->second<<"\n";
	 }
	 b.erase(b.begin(),b.find(2));
	// b.clear();
	 b.erase(3);b.clear();
	 b.insert(pair <int, int> (0,1));
 	 b.insert(pair <int, int> (1,1));
	 b.insert(pair <int, int> (2,1));
	 b.insert(pair <int, int> (3,1));

	 //b.insert(2,1);
	 //b.insert(3,1);
	 //b.insert(4,1);
	 
	 cout<<endl<<"key"<<"\t"<<"value"<<"\n";
	 for(itr=b.begin();itr!=b.end(); itr++)
	 {
	 	cout<<itr->first<<"\t"<<itr->second<<"\n";
	 }
return 0;
}
