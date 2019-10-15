#include<bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;
bool arepair(char op,char cl)
{
	if(op=='{'&&cl=='}')
	return true;
	if(op=='('&&cl==')')
	return true;
	if(op=='[]'&&cl==']')
	return true;
	return false;
}
bool para(string e)
{
	stack <char> s;
	for(int i=0;i<e.size();i++)
	if(e[i]=='{'||e[i]=='('||e[i]=='[')
	{
		s.push(e[i]);
	}
	else if(e[i]=='}'||e[i]==')'||e[i]==']')
	{
		if(s.empty()||!arepair(s.top(),e[i]))
		{
			return false;
		}
		else
		s.pop();
	}
	return s.empty()?true:false;
	
}
int main()
{
	string exp = " ({}){";
if(para(exp))
cout<<"balanced";
else
cout<<"not balanced";
	return 0;
}
