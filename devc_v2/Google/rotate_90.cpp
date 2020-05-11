#include<bits/stdc++.h>
using namespace std;


#define N 4 

int a[N][N] = 
    { {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16} 
    }; 

void rotate_clock_90(){
	for(int x=0;x<N/2;x++){
		for(int y=x;y<N-x-1;y++){
//			cout<<"Camehere";
			int temp = a[x][y];
			a[x][y]=a[N-1-y][x];
			a[N-1-y][x]=a[N-1-x][N-1-y];
			a[N-1-x][N-1-y] = a[y][N-1-x];
			a[y][N-1-x]=temp;
		}
	}

}
    
void rotate_anti_90(){
	for(int x=0;x<N/2;x++){
		for(int y=x;y<N-x-1;y++){
			int temp=a[x][y];
			a[x][y] = a[y][N-1-x];
			a[y][N-1-x]=a[N-1-x][N-1-y];
			a[N-1-x][N-1-y]=a[N-1-y][x];
			a[N-1-y][x]=temp;

//			int temp = a[x][y]; 
//  
//            // move values from right to top 
//            a[x][y] = a[y][N-1-x]; 
//  
//            // move values from bottom to right 
//            a[y][N-1-x] = a[N-1-x][N-1-y]; 
//  
//            // move values from left to bottom 
//            a[N-1-x][N-1-y] = a[N-1-y][x]; 
//  
//            // assign temp to left 
//            a[N-1-y][x] = temp; 
		}
	}
}

//void disp(){
//	for(int i=0;i<N;i++){
//    	for(int j=0;j<N;j++){
//    		cout<<a[i][j];
//		}
//		cout<"\n";
//	}
//}
   
   void displayMatrix() 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf("%2d ", a[i][j]); 
  
        printf("\n"); 
    } 
    printf("\n"); 
} 
    
int main(){
	 
    displayMatrix();
    rotate_anti_90();
    displayMatrix();
    rotate_clock_90();
    displayMatrix();
	return 0;
}
