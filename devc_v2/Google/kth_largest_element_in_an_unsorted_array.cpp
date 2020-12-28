/*
LeetCode: 215

215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.


*/
// First approach using priority_queue (max heap).

#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> q;
    int b[] = {3,2,1,5,6,4}, i = 0;
    int size = sizeof(b)/sizeof(b[0]);
    for(int i = 0; i< size; i++) {
        q.push(b[i]);
    }
    int limit = 3;
    i = 0; 
    while (i < limit - 1)
    {
        cout<<q.top();
        q.pop();
        i++;
    }
    cout<<"The kth largest element is "<<q.top();
    return 0;
}

// Second approach constructing a max heap.


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


