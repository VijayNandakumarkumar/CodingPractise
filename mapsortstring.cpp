#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s="JavAB199";
	map<char,int> m;
	for(int i=0;i<s.length();i++)
	{
		char u=toupper(s[i]);
		char l=tolower(s[i]);
		if((m[u]==0)&&(m[l]==0)&&m[s[i]]==0)
		{if(s[i]<65)
		{
			m[s[i]]++;
		}
		else{
			m[u]++;
			m[l]++;
		}
		}
		else
		{
		if(s[i]<65)
		{
			s[i]=(s[i]+1-48)%10+48;
			//s[i]%=48;
				/*s[i]=(s[i]+1);
				if(s[i]>'9')
				{
					s[i]=s[i]-'9'+'0'-1;
				}*/
		m[s[i]]++;	
		char u=toupper(s[i]);
		char l=tolower(s[i]);
		if((m[u]==0)&&(m[l]==0))
		{
			m[u]++;
			m[l]++;
		}
		}
			else if(isupper(s[i]))
			{
			//cout<<"s"<<s[i];
				s[i]=(s[i]+1-65)%26+65;
			//	cout<<"hehe"<<s[i];
			
		char u=toupper(s[i]);
		char l=tolower(s[i]);
		if((m[u]==0)&&(m[l]==0))
		{
			m[u]++;
			m[l]++;
		}
			}
			else
			{//cout<<s[i]<<'\n';
				s[i]=(s[i]+1-97)%26+97;
			//	cout<<'\n'<<s[i];
			}
		
		char u=toupper(s[i]);
		char l=tolower(s[i]);
		if((m[u]==0)&&(m[l]==0))
		{
			m[u]++;
			m[l]++;
		}
		}
	
	}
	cout<<'\t'<<"after change"<<s<<endl;
	return 0;
}
