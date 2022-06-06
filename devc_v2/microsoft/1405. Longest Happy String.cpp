/*

1405. Longest Happy String

A string s is called happy if it satisfies the following conditions:

    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.

Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. 
If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

*/

#define iPair pair<int, char>
#include <queue>
class Solution {
public:
    
    /* We thought alike - can put some more thought to get at the solution.


    string longestDiverseString(int a, int b, int c) {
       int n=a+b+c;
        auto comp = [](iPair a, iPair b) {
          return a.first < b.first;  
        };
        priority_queue<iPair> q;
        if (a)
            q.push({a, 'a'});
        if (b)
            q.push({b, 'b'});
        if (c)
            q.push({c, 'c'});
        string s="";
        int freq = 1;
        while(!q.empty()) {
            iPair one = q.top();
            q.pop();
            if (s.size() and s.back() == one.second and freq > 2) {
                // cout<<"\n first";
                if (q.empty()) {
                    return s;
                }
                iPair two = q.top();
                q.pop();
                s+=two.second;
                two.first--;
                if (two.first) {
                    q.push(two);
                }
                freq=1;
                q.push(one);
            } else {
                // cout<<"\n second";
                s+=one.second;
                one.first--;
                if(one.first)
                    q.push(one);
                freq += s.size() and s.back() == one.second;
                // cout<<"\n freq "<<freq;
            }
        }   
        return s;
    }*/
    string s="";
    int ac=0, bc=0, cc=0; // a_count, b_count and c_count respectively
    string longestDiverseString(int a, int b, int c) {
        if(a<=0 && b<=0 && c<=0)
        return s;
    
    
    if((a>0 && a>=b && a>=c && ac!=2) || (a>0 && (bc==2 || cc==2)))
       {
        s+='a';
        ac++;
        bc=0;
        cc=0;
       
    longestDiverseString(a-1, b, c);
    }
    
   else if((b>0 && b>=c && b>=a && bc!=2) || (b>0 && (ac==2 || cc==2)))
    {
        s+='b';
        bc++;
        ac=0;
        cc=0;
            
    longestDiverseString(a, b-1, c);
    }
    
   else if((c>0 && c>=a && c>=b && cc!=2) || (c>0 && (ac==2 || bc==2)))
    {
        s+='c';
        cc++;
        ac=0;
        bc=0;
    longestDiverseString(a, b, c-1);
    }
    
    
    
    return s;if(a<=0 && b<=0 && c<=0)
        return s;
    
    
    if((a>0 && a>=b && a>=c && ac!=2) || (a>0 && (bc==2 || cc==2)))
       {
        s+='a';
        ac++;
        bc=0;
        cc=0;
       
    longestDiverseString(a-1, b, c);
    }
    
   else if((b>0 && b>=c && b>=a && bc!=2) || (b>0 && (ac==2 || cc==2)))
    {
        s+='b';
        bc++;
        ac=0;
        cc=0;
            
    longestDiverseString(a, b-1, c);
    }
    
   else if((c>0 && c>=a && c>=b && cc!=2) || (c>0 && (ac==2 || bc==2)))
    {
        s+='c';
        cc++;
        ac=0;
        bc=0;
    longestDiverseString(a, b, c-1);
    }
    
    return s;
        
    }
};