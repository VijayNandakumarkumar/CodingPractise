#include<bits/stdc++.h>

struct glo
{
int a;
char b;
char c[100];
};
void pri(struct glo obj[]);
void pri1(int,struct glo obj[]);
int main()
{
	struct glo obj[5];
	
//	struct glo h;
	
	//obj[0].c="vijay";
	for(int i=0;i<5;i++)
	{
	obj[i].a=1;
	obj[i].b=2;
	strcpy(obj[i].c,"vijay");
	printf("\n%d \n%d \n%s",obj[i].a,obj[i].b,obj[i].c);
	//return 0;
    }
pri(obj);
int w=1;
pri1(w,obj);
	return 0;
}
void pri(struct glo obj[])
{
for(int i=0;i<5;i++)
	{
	printf("\n%d \n%d \n%s",obj[i].a,obj[i].b,obj[i].c);
}
}
void pri1(int i,struct glo obj[])
{printf("sbshvvjbsjkv");

		printf("\n%d \n%d \n%s",obj[i].a,obj[i].b,obj[i].c);
}

