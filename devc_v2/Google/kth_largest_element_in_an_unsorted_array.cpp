#include<bits/stdc++.h>
using namespace std;


vector<int> a;
vector<int> b;

int Left(int i){
	return 2*i+1;
}

int Right(int i){
	return (2*i)+2;
}

int Parent(int i){
	return (i-1)/2;
}

void heapify_down(int i){
	int left = Left(i);
	int right = Right(i);
	int largest = i;
	
	if((left<(int)a.size())&&(a[left]>a[i])){
		largest = left;
	}
	
	if((right<(int)a.size())&&(a[largest]<a[right])){
		largest = right;
	}
	if(largest!=i){
		swap(a[i], a[largest]);
		heapify_down(largest);
	}
	
}

void heapify_up(int i){
	if(i&&(a[Parent(i)]<a[i])){
		swap(a[i], a[Parent(i)]);
		heapify_up(Parent(i));
	}
}

void push(int key){
	a.push_back(key);
	int ind = (int)a.size()-1;
	heapify_up(ind);
}

void pop(){
	if((int)a.size()!=0){
		int result = a.at(0);
		a[0] = a.back();
		a.pop_back();
		heapify_down(0);
	}
}

void swap(int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int top()
{
	if((int)a.size()!=0){
		return a.at(0);
	}
}
void display_heap(vector<int> &a){
	cout<<"\n";
	int i=0;
	for(i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
}

void heap_sort(){
	int i=0;
	for(i=(int)a.size() - 1;i>=0;i--){
		b[i] = top();
		pop();
	}
}
int main(){
	int b[] = {3,2,1,5,6,4}, i = 0;
	for(i=0;i<6;i++){
		push(b[i]);
	}
	int key = 8, limit = a.size();
	for(i=limit;i>limit-key+1;i--){
		pop();
	}
//	display_heap(a);
	cout<<top();
	return 0;
}


