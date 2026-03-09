/*

3863. Minimum Operations to Sort a String.

You are given a string s consisting of lowercase English letters.

In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.

Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

 

Example 1:

Input: s = "dog"

Output: 1

Explanation:​​​​​​​

Sort substring "og" to "go".
Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.
Example 2:

Input: s = "card"

Output: 2

Explanation:

Sort substring "car" to "acr", so s = "acrd".
Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending order. Thus, the answer is 2.
Example 3:

Input: s = "gf"

Output: -1

Explanation:

It is impossible to sort s under the given constraints. Thus, the answer is -1.
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

*/


using namespace std;

class Solution {
public:
    int minOperations(string s) {
        string target = s;
        int n = s.length();
        sort(target.begin(), target.end());
        
        if (s == target) return 0; // no sorting needed

        if (s.length() == 0 || (s.length()==2)) // if len is 0 or 2 can't sort with substrings
            return -1;

        string ops1 = s, ops2=s;
        if ( (sortFromBegining(ops1) == target) || (sortTillEnd(ops2) == target) ) {
            return 1; // if either first characted is smallest or last character is largest then we need only on sort of substring either at the begining or at the ending
        }

        ops1 = s, ops2=s;

        if ((sortFromBegining(sortTillEnd(ops1)) ==target) || (sortTillEnd(sortFromBegining(ops2))==target)) {
            return 2; // case: "jgg". If we can sort using ops 1 and ops 2 then it's 2/
        }
        
        return 3; // case: "cba" entirely reversed, largest characted is first and smallest characted is last.
    }

    string sortFromBegining(string s) {
        sort(s.begin(), s.end()-1);
        return s;
    }
    string sortTillEnd(string s) {
        sort(s.begin()+1, s.end());
        return s;
    }
};
