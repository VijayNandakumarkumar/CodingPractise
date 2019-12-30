#include<bits/stdc++.h>

using namespace std;

struct node{
	int key;
	int value;
	struct node* next;
	struct node* prev;
};

typedef struct node* Node;

Node new_node(int key, int value){
	Node n = (Node)malloc(sizeof(struct node));
	n->key = key;
	n->value = value;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

struct lru{
	Node head = NULL;
	Node tail = NULL;
	int capacity;
	int length;
};

map<int, struct node*> m;
struct lru* l = NULL;

void swap_lru(int key){
	Node n = m[key];
	n->prev->next = n->next;
	n->next->prev = n->prev;
	n->prev = l->tail;
	n->next = l->tail->next;
	l->tail->next = n;
	l->tail = n;
}

int get(int key){
	int value;
	
	if(m.find(key)!=m.end()){
		if(m[key]!=l->tail)
			swap_lru(key);
		return m[key]->value;
	}
	
	return -1;
}
void put(int key, int value){
	if(m.find(key)!=m.end()){
		m[key]->value = value;
		swap_lru(key);
	}
	else{
		Node n = new_node(key, value);
		n->next = l->tail->next;
		n->prev = l->tail;
		l->tail->next = n;
		l->tail =  n;
		l->length += 1;
		m.insert(pair<int, Node> (key, n));
	}
	if(l->length>l->capacity){
		Node remove = l->head->next;
		l->head->next = remove->next;
		l->head->next->prev = l->head;
		l->length -= 1;
		m.erase(remove->key);
	}
}


int main(){
	l = (struct lru*)malloc(sizeof(struct lru));
	l->head = new_node(-1, -1);
	l->tail=l->head;
	l->capacity = 3;
	l->length = 0;
	
	put(1, 1);
	put(2, 2);
	put(3, 3);
	put(4, 4);
	
	cout<<"\n";
	
	cout<<l->capacity;
	cout<<l->length;
	
	cout<<"\n";
	
	put(3, 6);
	cout<<"Came here";
	cout<<"\n";
	cout<<"CAme here";
	cout<<"\n";
	cout<<get(2);
	cout<<"\n";
	cout<<get(4);
	cout<<"\n";
	cout<<get(3);
	cout<<"\n";
	cout<<get(3);
	cout<<"\n";
	return 0;
}

