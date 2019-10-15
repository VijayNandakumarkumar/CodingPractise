#include<bits/stdc++.h>
#include<string>
using namespace std;
/*bool IsCyclicWord(char *s1, char *s2) {
	char *s3=strcat(s1,s1);
	int l1 = sizeof(s1)/sizeof(char),l2=sizeof(s2)/sizeof(char);
    return l1==l2 && strstr(s3,s2);
}*/
int main()
{
	char *s1 =" picture";char *s2 = "icturep";
//	IsCyclicWord(s1,s2);
char *p=s1;
char *q=s2;
int l1 = sizeof(s1)/sizeof(char),l2=sizeof(s2)/sizeof(char),i=0,flag=0;
*(q+l2)='\0';
//cout<<*(q+1);
while(strcmp(p,q))
{
	if(*p!=*q)
	{//cout<<"q++"<<*q;
	if(*(q+1)!='\0')
			{
					q++;
					continue;
			}
			else if(*q==*p)
			{
			break;
			}
			else
			{
					q=s2;
			}
			
	
	}
		
			}
			

	if(*p==*q)
	{cout<<"inloop";
		for(int i=0;i<l1;i++)
		{
		cout<<"\ng";
			if(!(strcmp(p,q)))
			{cout<<"\n"<<*p<<*q<<"f";
				p++;
				flag=1;
				if(*q=='\0')
			{
				q=s2;
			}
			else
			{
				q++;
			}
			}
			else
			{
				flag =0;
				break;
			}
			
		}
	}
	
if(flag==1)
{
	cout<<"cyclic";
	//break;
}

return 0;
}
