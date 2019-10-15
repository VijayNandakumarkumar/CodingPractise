#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &vect)
{vect.push_back(40);
	for(int i=0;i<vect.size();i++)
	cout<<vect[i];
}
int main()
{
	vector<int> vect;
	vector<int>::iterator i;
	vector<int>::reverse_iterator ir;
	
	vect.push_back(10);
	vect.push_back(20);
	vect.push_back(30);
		printf("dcwf\n");
	func(vect);
	for(int i=0;i<vect.size();i++)
	cout<<vect[i];
	cout<<endl;
	for(ir=vect.rbegin();ir!=vect.rend();++ir)
	cout<<'\t'<<*ir;
	cout<<endl;
	for(i=vect.begin();i!=vect.end();++i)
	cout<<'\t'<<*i;

	return 0;
}
