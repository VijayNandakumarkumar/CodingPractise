/*

735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.


*/

class Solution {
public:
    
    //Another optimal solution using stack and vector.
    /*
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        stack<int>s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty() || asteroids[i]>0)
                s.push(asteroids[i]);
            else if(asteroids[i]<0)
            {
                int f=0;
                while(!s.empty() && s.top()>0 && s.top()<=abs(asteroids[i]))
                {
                    if(s.top()==abs(asteroids[i]))
                    {
                        f=1;
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                if(f==1)
                    continue;
                if(s.empty() || s.top()<0)
                    s.push(asteroids[i]);
            }
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
    */
    
    //Our solution - optimal only, but only using vector. We also did the same one as above used vector as more or less stack.
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        int n=asteroids.size();
        for(int i=0; i<n; i++) {
            if (v.empty() || asteroids[i] >= 0 || v.back() < 0) {
                v.push_back(asteroids[i]);
            } else {
                int a = asteroids[i];
                int col = 0;
                while (v.size() > 0 && v.back() > 0) {
                    col = v.back() + a;
                    if (col > 0) {
                        break;
                    } else if (col == 0) {
                        v.pop_back();
                        break;
                    } else {
                        v.pop_back();
                    }
                }
                if (col<0) {
                    v.push_back(a);
                }
            }
        }
        return v;
    }
    
};