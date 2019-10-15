#include<bits/stdc++.h>
using namespace std;
int main()
{
	string v="vowel";
	int i=0,j=v.length()-1;
	cout<<j;
	while(i<j)
	{
		if((v[i]=='a'||v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u')&&(v[j]=='a'||v[j]=='e'||v[j]=='i'||v[j]=='o'||v[j]=='u'))
	{
		
		//char temp=v[i];
		cout<<"\n swap \t"<<v[i]<<"\t"<<v[j];
		//v[i]=v[j];
		//v[j]=temp;
		swap(v[i],v[j]);
		i++;
		j--;
	}
	if((v[i]!='a'&&v[i]!='e'&&v[i]!='i'&&v[i]!='o'&&v[i]!='u'))
	{ 
	cout<<"\n i++ \t"<<v[i];
	i++;
	}
			
    if((v[j]!='a'&&v[j]!='e'&&v[j]!='i'&&v[j]!='o'&&v[j]!='u'))
	{cout<<"\n j-- \t"<<v[j];
		j--;
	}
	
}
cout<<"the string is \n"<<v;
	return 0;
}
