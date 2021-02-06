/*

Pramp
https://www.pramp.com/challenge/W5EJq2Jld3t2ny9jyZXG

Word Count Engine
Implement a document scanning function wordCountEngine, which receives a string document and returns a list of all unique words in it and their number of occurrences, sorted by the number of occurrences in a descending order. If two or more words have the same count, they should be sorted according to their order in the original sentence. Assume that all letters are in english alphabet. You function should be case-insensitive, so for instance, the words “Perfect” and “perfect” should be considered the same word.

The engine should strip out punctuation (even in the middle of a word) and use whitespaces to separate words.

Analyze the time and space complexities of your solution. Try to optimize for time while keeping a polynomial space complexity.

Examples:

input:  document = "Practice makes perfect. you'll only
                    get Perfect by practice. just practice!"

output: [ ["practice", "3"], ["perfect", "2"],
          ["makes", "1"], ["youll", "1"], ["only", "1"], 
          ["get", "1"], ["by", "1"], ["just", "1"] ]


*/



#include <iostream>
#include <string>
#include <vector>
#include <list>
#include<unordered_map>


using namespace std;


unordered_map<int, list<string>> freq_string;
unordered_map<string, int> string_freq;
int maxFreq = 0;


vector<vector<string>> wordCountEngine( const string& document ) 
{
  vector<vector<string>> ans;
  string doc (document.begin(), document.end());
  doc.push_back(' ');
  vector<string> listOfWords;
  string s = "";
  for (int i = 0; i<doc.length(); i++) {
    if ((doc[i] == ' ') && (s.length() > 0)) {
      if (!string_freq.count(s))
         listOfWords.push_back(s);
      string_freq[s]++;
      maxFreq = (maxFreq < string_freq[s]) ? string_freq[s] : maxFreq;
      s = "";
      continue;
    } else if (isalpha(doc[i])) {
      s += tolower(doc[i]);
      continue;
    } else {
      continue;
    }
  }
  
  for(auto it = listOfWords.begin(); it != listOfWords.end(); it++) {
    cout<<*it<<" ";
    freq_string[string_freq[*it]].push_back(*it);
  }
  
  for(int i = maxFreq; i>=1; i--) {
    if (freq_string[i].size() == 0) 
      continue;
    for (auto it = freq_string[i].begin(); it != freq_string[i].end(); it++) {
      ans.push_back({*it, to_string(i)});
    }
  }
  return ans;
}

int main() {
  
  //string doc = "Practice makes perfect perfect. you'll only get Perfect by practice. just practice!";
  //wordCountEngine(doc); 
  return 0;
}

/*

"Practice makes perfect perfect. youll only get Perfect by practice. just practice! "
auto it
while()

//[string]


unordered_map<int, vector<string>> freq_string;
unordered_map<string, list<string>::iterator> key_itr;
unordered_map<string, int> string_freq;

{"perfect", itr} -> begin() + 3

maxFreq = 3

string_freq:
   {"practice", 1}
   {"makes", 1}
   {"perfect", 2}

{1, ["Practice", "makes", "perfect", "you'll"]}
{2, ["perfect"]}

insertion and deletion O(1)

*/
