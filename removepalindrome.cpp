// C++ implementation to remove all the 
// palindromic words from the given sentence
#include <bits/stdc++.h>
using namespace std;
 
// function to check if 'str' is palindrome
bool isPalindrome(string str) {
  int i = 0, j = str.size() - 1;
 
  // traversing from both the ends
  while (i < j)
 
    // not palindrome
    if (str[i++] != str[j--])
      return false;
 
  // palindrome
  return true;
}
 
// function to remove all the palindromic words
// from the given sentence
string removePalinWords(string str) {
 
  // 'final_str' to store the final string and
  // 'word' to one by one store each word of 'str'
  string final_str = "", word = "";
 
  // add space at the end of 'str'
  str = str + " ";
  int n = str.size();
 
  // traversing 'str'
  for (int i = 0; i < n; i++) {
 
    // accumulating characters of the current word
    if (str[i] != ' ')
      word = word + str[i];
 
    else {
 
      // if 'word' is not palindrome then a
      // add it to 'final_str'
      if (!(isPalindrome(word)))
        final_str += word + " ";
 
      // reset
      word = "";
    }
  }
 
  // required final string
  return final_str;
}
 
// Driver program to test above
int main() {
  string str;//"Text contains malayalam and level words";
  getline(cin,str);
  cout << removePalinWords(str);
  return 0;
}

