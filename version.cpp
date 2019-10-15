#include<bits/stdc++.h>
using namespace std;
#include<string>
int main()
{
	string v1 = "1.1.11 ";
	int num1 = 0, num2 = 0,flag = 0;
	string v2 = "1.1.11";
	int alen = v1.length(), blen = v2.length();
	int len = max(alen, blen);
	cout<<len;
	for(int i=0;i<len;i++)
	{
		if((v1[i]!='.')&&(v2[i]!='.')&&(v1[i]!=' ')&&(v2[i]!=' '))
		{
			num1 = num1*10 +(v1[i]-'0');
			num2 = num2*10 +(v2[i]-'0');
			//cout<<"\n"<<num1<<"\t"<<num2;
		}
		else
		{
			if(num1>num2)
			{
				cout<<"\n version1"<<num1<<"\t"<<num2;
				break;
			}
			else if(num1<num2)
			{
				cout<<"\n version2"<<num1<<"\t"<<num2;
				break;
			}
			else if(num1 == num2)
			{  //	cout<<"\n equal"<<num1<<"\t"<<num2;
				num1 = 0;
				num2 = 0;
				if(i == len-1)
				flag = 1;
				continue;
			}
		}
		
	
	}
	if(flag == 1)
	{
		cout<<"\n equal";
	}
	return 0;
}
