#include<bits/stdc++.h>
struct node
{
	int key;
	int data;
	struct node* next;
};
struct node* head;
struct node* current=NULL;
int len()
{
int lengt=0;
	struct node* current=head;
	while(current!=NULL)
	{
		lengt++;
	    current=current->next;	
	}
	return lengt;
}

void printt(struct node** head1)
{//printf("here");
	struct node* prev=*head1;
	while(prev!=NULL)
	{
		printf("data = %d\tkey = %d\t\n",prev->data,prev->key);
		prev=prev->next;
	}
}
void insert(int key, int data)
{   //printf("hello\n");
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->key=key;
	n->data=data;
	if(head==NULL)
	{
	//printf("hello1\n");
		head=n;
		head->next=NULL;
	}
	else
	{
	//	printf("hello2\n");
		n->next=head;
		head=n;
	}
}
struct node* delet()
{
	struct node* temp;
	if(head==NULL)
	{
		return NULL;
	}
	else{
		temp=head;
		head=head->next;
	}
return temp;
}
struct node* deleteat(int key)
{
	struct node* current=head;
	struct node* prev;
	while(current->key!=key)
	{
		if(current->next==NULL)
		{
			return NULL;
		}
		else
		{   prev=current;
			current=current->next;
		}
		if(current==head)
		{
			head=head->next;
		}
		else
		{
			prev->next=current->next;
			return current;
		}
	}
}
void reverse(struct node** headref)
{
	struct node* prev=NULL;
	struct node* current=*headref;
	struct node* next;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
int main()
{
	struct node* det;
	int length1;
	insert(0,1);
	insert(1,2);
	insert(2,3);
	length1=len();
	printf("length=%d\n",length1);
//	printf("next\n");
	printt(&head);
	det=delet();
	printf("after delete\ndet->key = %d\tdet->data = %d\n",det->key,det->data);
	printt(&head);
	insert(2,3);
	printf("again after inserting the third element\n");
	printt(&head);
	det=deleteat(1);
	//det=delet();
	printf("after deleting at key 1\ndet->key = %d\tdet->data = %d\n",det->key,det->data);
	printt(&head);
	//insert(1,2);
	reverse(&head);
	printf("after reversing\n");
	printt(&head);
	
return 0;
}
