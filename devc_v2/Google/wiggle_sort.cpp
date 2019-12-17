#include<bits/stdc++.h>
using namespace std;

//imporved solution

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	
	for(int i=0;i<a.size()-1;i++){
		int temp;
		if((i%2==0)==(a[i]>a[i+1])){
			temp = a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}
	vector<int>::iterator it;
	for(it=a.begin();it!=a.end();it++){
		cout<<*it;
	}
	return 0;
}


//
//
//
//
//
//
//
//
//
//
//#define max 6
//
//int a[6] = {1, 3, 5, 6, 4, 2};
//int b[10];
//
//void merging(int low, int mid, int high) {
//   int l1, l2, i;
//
//   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
//      if(a[l1] <= a[l2])
//         b[i] = a[l1++];
//      else
//         b[i] = a[l2++];
//   }
//   
//   while(l1 <= mid)    
//      b[i++] = a[l1++];
//
//   while(l2 <= high)   
//      b[i++] = a[l2++];
//
//   for(i = low; i <= high; i++)
//      a[i] = b[i];
//}
//
//void sort(int low, int high) {
//   int mid;
//   
//   if(low < high) {
//      mid = (low + high) / 2;
//      sort(low, mid);
//      sort(mid+1, high);
//      merging(low, mid, high);
//   } else { 
//      return;
//   }   
//}
//
//int main() { 
//   int i, j;
////
////   printf("List before sorting\n");
////   
////   for(i = 0; i <= max; i++)
////      printf("%d ", a[i]);
//
//   sort(0, max);
//
////   printf("\nList after sorting\n");
////   
////   for(i = 0; i <= max; i++)
////      printf("%d ", a[i]);
////      
//    i=1,j=6;
//    while(i<j){
//    	printf("%d%d", a[i++], a[j--]);
//	}
//	
//}
