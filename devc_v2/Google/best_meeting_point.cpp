#include<bits/stdc++.h>

using namespace std;
int diff(int p, int q){
	int res=p-q;
	if(res<0){
		return res * -1;
	}
	return res;
}
int dist(int p, int q){
	
	int p1=0, q1=0, p2 =0, q2=4,p3=2, q3=2;
	int dist1=0, dist2=0, dist3=0;
	dist1=diff(p, p1)+diff(q, q1);
	dist2=diff(p, p2)+diff(q, q2);
	dist3=diff(p, p3)+diff(q, q3);
	int dist = dist1+dist2+dist3;
	return dist;
}

int main(){
	int a[3][5];
//	a[0].push_back(1);
//	a[0].push_back(0);
//	a[0].push_back(0);
//	a[0].push_back(0);
//	a[0].push_back(1);
//	a[1].push_back(0);
//	a[1].push_back(0);
//	a[1].push_back(0);
//	a[1].push_back(0);
//	a[1].push_back(0);
//	a[2].push_back(0);
//	a[2].push_back(0);
//	a[2].push_back(1);
//	a[2].push_back(0);
//	a[2].push_back(0);
	int i, j, val=0;
   for(i=0; i<3; i++) {
      for(j=0;j<5;j++) {
         printf("Enter value for disp[%d][%d]:", i, j);
         scanf("%d", &a[i][j]);
      }
   }
   
   for(i=0; i<3; i++) {
      for(j=0;j<5;j++) {
	  cout<<a[i][j];
	  }
	  cout<<"\n";}
	  
	
	int dist_val = 0, min = 9999, x=0,y=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			if(a[i][j]==0){
				
				dist_val = dist(i, j);
				if(min>dist_val){
					a[i][j]=min;
					min=dist_val;
					x=i;
					y=j;
				}
			}
		}
	}
	cout<<x<<"\t"<<y;
	
	return 0;
}
