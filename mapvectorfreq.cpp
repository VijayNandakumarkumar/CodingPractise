#include<bits/stdc++.h>
#include<vector>
using namespace std;

void ortt(vector<int> &vect)
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
int a[8] = {-1,-1,2,1,1,2,1,-1};
int max = 0;
map <int,int> freq;
map <int, vector <int> > frr;
map <int,int>::iterator i;
map <int,int>::iterator ir;
int size = sizeof(a)/sizeof(a[0]);
for(int i=0;i<size;i++)
{
	freq[a[i]]++;
	if(max<freq[a[i]])
	{
		max=freq[a[i]];
	}
}
cout<<"\n"<<"key"<<"\t"<<"value"<<"\n";
for(i = freq.begin();i!=freq.end();i++)
{
	cout<<i->first<<"\t"<<i->second<<"\n";
}
cout<<"\n";
for(int i = 0;i < size;i ++)
{
	frr[freq[a[i]]].push_back(a[i]);
}
cout<<"\n";
for(int i = max;i >= 0;i--)
{
	if(frr[i].size()>0)
	{
	//	sort(frr[i].begin(),frr[i].end());
ortt(frr[i]);
	for(int j=0;j<frr[i].size();j++)
	{
		cout<<frr[i][j]<<"\t";
		//a[k++]=frr[i][j];
	}
	}
}
return 0;
}

