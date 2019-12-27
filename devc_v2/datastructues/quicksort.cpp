#include<bits/stdc++.h>;

using namespace std;

#define MAX 10

int a[MAX] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};

void printArray(){
	int i=0;
	for(i=0;i<MAX;i++){
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
}


void swap(int l1, int l2){
	int temp=0;
	temp = a[l1];
	a[l1]=a[l2];
	a[l2]=temp;
}

int partition(int left, int right, int pivot){
	int leftpointer = left - 1;
	int rightpointer =right;
	while(1){

	while(a[++leftpointer]<pivot){

	}
	
	while((rightpointer>0)&&(a[--rightpointer]>pivot)){
		
	}
	
	if(leftpointer>=rightpointer){
		break;
	}
	else{
		swap(leftpointer, rightpointer);
	}
}
swap(leftpointer, right);

return leftpointer;
	
}

void sort(int left, int right){
	
	if((right-left)<0){
		return;
	}
	
	else{
		int pivot=a[right];
		int partitionpoint = partition(left, right, pivot);
		sort(left, partitionpoint-1);
		sort(partitionpoint+1, right);
	}
	
}
int main(){
	printArray();
	sort(0, 10);
	printArray();
	return 0;
}
