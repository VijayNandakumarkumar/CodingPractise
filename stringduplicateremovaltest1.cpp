#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	map <char, int> m;
	for(int i=0;i<s.length();i++)
	{
	char u = toupper(s[i]);
	char l = tolower(s[i]);
		if((m[u]==0)&&(m[l]==0)&&(m[s[i]]==0))
				{
			
			if(s[i]<65)
			{
				m[s[i]]++;
			}
			else
			{
				m[u]++;
				m[l]++;
			}
		}
		else
		{
			if(s[i]<65)
			{
				s[i]=(s[i]+1-48)%10+48;
				m[s[i]]++;
				char u = toupper(s[i]);
				char l = tolower(s[i]);
				if((m[u]==0)&&(m[l]==0))
				{
				m[u]++;
				m[l]++;
				//m[s[i]]++;
			}
			}
			else if(isupper(s[i]))
			{
				s[i]=(s[i]+1-65)%26+65;
				char u = toupper(s[i]);
				char l = tolower(s[i]);
				if((m[u]==0)&&(m[l]==0))
				{
			
				m[u]++;
				m[l]++;
		}	}
			else if(islower(s[i]))
			{
			l1:	s[i]=(s[i]+1-97)%26+97;
				char u = toupper(s[i]);
				char l = tolower(s[i]);
			if((m[u]==0)&&(m[l]==0))
				{
				m[u]++;
				m[l]++;
			}
			else goto l1;
		}
		/*char u=toupper(s[i]);
		char l=tolower(s[i]);
		if((m[u]==0)&&(m[l]==0))
		{
			m[u]++;
			m[l]++;
		}*/
		}
	}
	cout<<"\n"<<"after change"<<s;
	return 0;
}
