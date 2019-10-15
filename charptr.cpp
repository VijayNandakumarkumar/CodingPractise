#include<bits/stdc++.h>
using namespace std;
char* strrevv(char *p)
{	cout<<"inside"<<__func__<<__LINE__;
	char *q = NULL;
	q = strrev(p);
	return q;
}
int main()
{
	char *p = NULL,*q = NULL;
	char a[10]="vijay";
	p = a;
	q = strrevv(p);
	cout<<q; 
	return 0;
}
