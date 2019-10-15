//#include<bits/stdc++.h>
//using namespace std;
//
//struct node{
//    int key;
//    struct node* left;
//    struct node* right;
//};
//
//typedef struct node* Node;
//
//Node root = NULL;
//Node current = NULL;
//Node parent = NULL;
//
//Node new_node(int key){
//    Node n = (Node)malloc(sizeof(struct node));
//    n->key=key;
//    n->left=NULL;
//    n->right=NULL;
//    return n;
//};
//
//
//
//vector<int> solve (vector<int> A,int N) {
//    // Return an a vector of N elements, ith element representing level of A[i]
//    // Write your code here
//    
//    
////    1 2 2 3 4 3 3
//
//    vector<int> ret_arr;
//    int level=0;
//    for(int i=0;i<=N;i++){
//		level=1;
//        int key=A[i];
//        cout<<"Current Element "<<key<<"\n";
//        Node n=new_node(key);
//        current = root;
//        if(current==NULL){
//            root=n;
//            ret_arr.push_back(level);
//            continue;
//        }
//        else{
//		current=root;
//		parent=NULL;
//        while(1)
//        {
//        	parent = current;
//            if(current->key<=key){
//                current=current->right;
//                level++;
//				if(current==NULL){
//                	parent->right=n;
//                	ret_arr.push_back(level);
//                	cout<<"Level "<<level<<"\n";
//                	break;
//                }                
//            }
//            else {
//                current=current->left;
//                level++;
//				if(current==NULL){
//                	parent->left=n;
//                	ret_arr.push_back(level);
//                	cout<<"Level "<<level<<"\n";
//                	break;
//            	}
//            }
//        }
//		}
//		   
//    }
//    return ret_arr;
//    
//}
//
//int main() {
//
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int N;
//    cin >> N;
//    vector<int> A(N);
//    for(int i_A=0; i_A<N; i_A++)
//    {
//    	cin >> A[i_A];
//    }
//
//    vector<int> out_;
//    out_ = solve(A,N);
//    cout << out_[0];
//    for(int i_out_=1; i_out_<N; i_out_++)
//    {
//    	cout << " " << out_[i_out_];
//    }
//}


#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    struct node* left;
    struct node* right;
};

typedef struct node* Node;

Node root = NULL;
Node current = NULL;
Node parent = NULL;
vector<int>ret_arr; 


Node new_node(int key){
    Node n = (Node)malloc(sizeof(struct node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    return n;
};

// vector<int> solve (vector<int> A,int N) {
//     // Return an a vector of N elements, ith element representing level of A[i]
//     // Write your code here
//     // vector<int> ret_arr;
//     int level=0;
//     for(int i=0;i<N;i++){
//         level=1;
//         int key=A[i];
//         Node n=new_node(key);
//         current = root;
//         if(current==NULL){
//             root=n;
//             // ret_arr.push_back(level);
//             A[i]=level;
//             continue;
//         }
//         else{
//             current = root;
//             parent=NULL;
//             while(1)
//             {
//                 parent=current;
//                 if(current->key<=key){
//                     current=current->right;
//                     level++;
//                     if(current == NULL){
//                         parent->right=n;
//                         break;
//                     }
//                 }
//                 else{
//                     current=current->left;
//                     level++;
//                     if(current == NULL){
//                         parent->left=n;
//                         break;
//                     }
//                 }
//             }
//         }
//         // ret_arr.push_back(level);
//         A[i]=level;
//     }
//     return A;
    
// }
int level=0;
void solve (int key, int i) {
    // Return an a vector of N elements, ith element representing level of A[i]
    // Write your code here
    // vector<int> ret_arr;
    level=1;
    Node n=new_node(key);
    current = root;
    if(current==NULL){
        root=n;
        ret_arr.push_back(level);
        cout<<"key "<<key<<"level "<<level<<"\n";
        return;
    }
    else{
        current = root;
        parent=NULL;
        while(1)
        {
            parent=current;
            if(current->key<=key){
                current=current->right;
                level++;
                if(current == NULL){
                    parent->right=n;
                    cout<<"key "<<key<<"level "<<level<<"\n";
                    ret_arr.push_back(level);
                    return;
                }
            }
            else{
                current=current->left;
                level++;
                if(current == NULL){
                    parent->left=n;
                    cout<<"key "<<key<<"level "<<level<<"\n";
                    ret_arr.push_back(level);
                    return;
                }
            }
        }
         
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N	);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
//    	cout<<A[i_A];
    	solve(A[i_A], i_A);
    }

    
    
    cout << ret_arr[0];
    for(int i_out_=1; i_out_<N; i_out_++)
    {
    	cout << " " << ret_arr[i_out_];
    }
}
