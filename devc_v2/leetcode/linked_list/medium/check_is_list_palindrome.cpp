/*


GeeksForGeeks: Check if Linked List is Palindrome 

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

*/


//Solution: https://ide.geeksforgeeks.org/ytRdEUZ9Po
//without using extra space.

Node* reverse(Node* slow)
   {
       Node* curr=slow;
       Node* next;
       Node* prev=NULL;
       while(curr!=NULL)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           
       }
       return prev;
   }
bool isPalindrome(Node *head)
{
    Node* slow=head;
          Node*  fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
           slow=slow->next;
            fast=fast->next->next;
        } 
        fast=head;
        slow=reverse(slow);
        // return checkit(str);
        while(slow!=NULL)
        {
            if(fast->data!=slow->data)
            {
                return false;
            }  
            slow=slow->next;
            fast=fast->next;
        } 
        return true;
}

//Solution: https://ide.geeksforgeeks.org/P6oifBaIiv
//Using extra string.



bool checkit(string str)
    {
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(str[i]!=str[n-i-1])
            {
                return false;
            }   
        }  
        return true;
    }


 bool isPalindrome(Node* head) {
        string str="";
        Node* t=head;
        while(t!=NULL)
        {
            str.push_back(t->data);
            t=t->next;
        }   
        return checkit(str);
}
