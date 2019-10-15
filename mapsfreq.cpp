#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[8]={-1,-1,1,-1,1,2,1,2};
void sortt(vector<int> &vect)
{
	for(int i=0;i<vect.size()-1;i++)
	{
		for(int j=0;j<vect.size()-i-1;j++)
		{
			if(vect[j]>vect[j+1])
			{
				swap(vect[j],vect[j+1]);
			}
		}
	}
}
int main()
{
	map<int,int> m;
	map<int,int>:: iterator ir;
	map<int,vector<int> > m1;
	map<int,vector<int> >:: iterator ri;
    int max=0;
	for(int i=0;i<8;i++)
	{
		m[a[i]]++;
		if(m[a[i]]>max)
		{
			max=m[a[i]];
		}
	}
	
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for(ir=m.begin();ir!=m.end();++ir)
    {
    	cout<<'\t'<<ir->first<<'\t'<<ir->second<<'\n';
	}
	cout<<"max="<<max<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<"aa"<<a[i];
		m1[m[a[i]]].push_back(a[i]);
	}
	int i=0;
 /*   cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
  for(ri=m1.begin();ri!=m1.end();++ri)
  {
    	cout<<'\t'<<ri->first<<'\t';
    	for(int j=0;j<m1[i].size();j++)
		cout<<m1[i][j]<<'\n';
       i++; 
  }*/
for(int i=max;i>=0;i--)
{
	if(m1[i].size()>0)
//sort(m1[i].begin(),m1[i].end());
sortt(m1[i]);
cout<<"size"<<m1[i].size();
for(int j=0;j<m1[i].size();j++)
{
	cout<<m1[i][j]<<" ";
}

}
cout<<'\t'<<"key"<<'\t'<<"data"<<'\n';
/*for(i=0;i<m1.size();i++)
{
	//cout<<'\t'<<m1[i]<<'\t'
	for(int j=0;j<m1[i].size();j++)
	{
		cout<<m1[i][j];
	}
  }*/  
return 0;
}
