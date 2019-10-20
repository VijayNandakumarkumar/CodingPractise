//#include<bits/stdc++.h>
//using namespace std;
//
//struct node{
//	int val;
//	bool visited;
//};
//queue<int> q;
//vector< vector<int> > v(7, vector<int>(0));
//
//struct node* listVertices[7];
//
//int adj[7][7] = {0};
//
//
//int vertexCount = 0;
//struct node* createVertex(int val){
//	struct node* new_node = (struct node*)malloc(sizeof(struct node));
//	new_node->val = val;
//	new_node->visited = false;
//	listVertices[vertexCount++] = new_node;
//	return new_node;
//}
//
//void addEdge(int one, int two){
//	adj[one][two] = 1;
//
//}
//
//int getAdjVertex(int vertex){
//	int i = vertex;
//	for(int j=0;j<7;j++){
//		if((adj[i][j] == 1)&& (listVertices[j]->visited== false)){
//			return j;
//		}
//	}
//	return -1;
//}
//
//void bfs(){
//	
//	listVertices[0]->visited = true;
//	q.push(0);
//	int unvisitedVertex;
//	int i=0, j = 0;
//	cout<<listVertices[0]->val<<" -";
//	while(!q.empty()){
//		int temp = q.front();
//		q.pop();
//		while((unvisitedVertex = getAdjVertex(temp)) != -1){
//			cout<<listVertices[unvisitedVertex]->val<<" - ";
//			v[i].push_back(listVertices[unvisitedVertex]->val);
//			listVertices[unvisitedVertex]->visited = true;
//			q.push(unvisitedVertex);
//			
//		}
//		i++;
//	}
//	
//}
//
//int main(){
//	for(int i=0;i<7;i++){
//	for(int j=0;j<7;j++){
//		adj[i][j] = 0;
//	}
//}
//	createVertex(1);   // 0
//   createVertex(2);   // 1
//   createVertex(3);   // 2
//   createVertex(4);   // 3
//   createVertex(5);   // 4
//   createVertex(6);		//5
//   createVertex(7);		//6
//
//   addEdge(0, 1);    // S - A
//   addEdge(0, 2);    // S - B
//   addEdge(1, 6);    // S - C
//   addEdge(1, 5);    // A - D
//   addEdge(2, 4);    // B - D
//   addEdge(2, 3);    // C - D
//   
//   for(int i =0;i<7;i++)
//   	{
//	   for(int j=0;j<7;j++)
//   		cout<<adj[i][j]<<" ";
//   	cout<<"\n";}		
//	bfs();
//	return 0;
//}


#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node* Nde;

Nde newNode(int data){
	Nde new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
}


void zizagtraversal(Nde root){
	if(root ==  NULL){
		return;
	}
	stack<Nde> current;
	stack<Nde> next;
	bool lefttoright = true;
	current.push(root);
	cout<<"Came here";
	while(!current.empty()){
		Nde temp = current.top();
		current.pop();
		if(temp){
			cout<<temp->data;
			
			if(lefttoright){
				if(temp->left)
					next.push(temp->left);
				if(temp->right)
					next.push(temp->right);
			}
			else{
				if(temp->right)
					next.push(temp->right);
				if(temp->left)
					next.push(temp->left);
			}
			if(current.empty()){
				lefttoright = !lefttoright;
				swap(current, next);
			}
		}
	}
}

//void zizagtraversal(struct Node* root) 
//{ 
//    // if null then return 
//    if (!root) 
//        return; 
//  
//    // declare two stacks 
//    stack<struct Node*> currentlevel; 
//    stack<struct Node*> nextlevel; 
//  
//    // push the root 
//    currentlevel.push(root); 
//  
//    // check if stack is empty    
//    bool lefttoright = true; 
//    while (!currentlevel.empty()) { 
//  
//        // pop out of stack 
//        struct Node* temp = currentlevel.top(); 
//        currentlevel.pop(); 
//  
//        // if not null 
//        if (temp) { 
//  
//            // print the data in it 
//            cout << temp->data << " "; 
//  
//            // store data according to current 
//            // order. 
//            if (lefttoright) { 
//                if (temp->left) 
//                    nextlevel.push(temp->left); 
//                if (temp->right) 
//                    nextlevel.push(temp->right); 
//            } 
//            else { 
//                if (temp->right) 
//                    nextlevel.push(temp->right); 
//                if (temp->left) 
//                    nextlevel.push(temp->left); 
//            } 
//        } 
//  
//        if (currentlevel.empty()) { 
//            lefttoright = !lefttoright; 
//            swap(currentlevel, nextlevel); 
//        } 
//    } 
//} 
  
int main() 
{ 
    // create tree 
    Nde root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    cout << "ZigZag Order traversal of binary tree is \n"; 
  
    zizagtraversal(root); 
  
    return 0; 
} 

