/*

418. Sentence Screen Fitting

Given a rows x cols screen and a sentence represented as a list of strings, return the number of times the given sentence can be fitted on the screen.

The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. A single space must separate two consecutive words in a line.

 

Example 1:

Input: sentence = ["hello","world"], rows = 2, cols = 8
Output: 1
Explanation:
hello---
world---
The character '-' signifies an empty space on the screen.

*/

class Solution {
public:
//     int wordsTyping(vector<string>& sentence, int rows, int cols) {
//         int totalWords = sentence.size();
//         int sentenceLen = totalWords;
//         for(int i=0; i<totalWords; i++) {
//             sentenceLen += sentence[i].length();
//         }
        
//         return (rows*cols) / sentenceLen;
//     }
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        string sentenceStr = "";
        for(int i=0;i<n;i++) {
            sentenceStr += sentence[i] + " ";
        }
        int sentenceLen = sentenceStr.length();
        
        int cursor = 0;
        for(int i=0; i<rows; i++) {
            cursor += cols;
            if (sentenceStr[cursor%sentenceLen] == ' ') {
                cursor += 1;
            } else {
                while(cursor>=0 && (sentenceStr[cursor%sentenceLen] != ' ')) {
                    cursor--;
                }
                cursor++;
            }
        }
        return cursor/sentenceLen;
    }
};