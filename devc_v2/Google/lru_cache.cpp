/*

146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

*/


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

