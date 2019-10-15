/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void rev(string &name, int start, int end){
    while(start<end){
        char temp = name[start];
        name[start] = name[end];
        name[end] = temp;
        start++;
        end--;
    }
}

void reverse(string &name, int start, int end){
    
    int i = 0;
    for(int j=0;j<end;j++){
        if(name[j] == ' '){
            rev(name, i, j-1);
            i=j+1;
        }
    }
    rev(name, i, name.length()-1);
    rev(name, 0, name.length()-1);
}



int main()
{
    string name = "Vijay kumar";
    
    reverse(name, 0, name.length());
    cout<<name;
    return 0;
}
