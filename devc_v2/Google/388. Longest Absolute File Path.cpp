/*

388. Longest Absolute File Path

Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:

Here, we have dir as the only directory in the root. dir contains two subdirectories, subdir1 and subdir2. subdir1 contains a file file1.ext and subdirectory subsubdir1. subdir2 contains a subdirectory subsubdir2, which contains a file file2.ext.

In text form, it looks like this (with ⟶ representing the tab character):

dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext

If we were to write this representation in code, it will look like this: "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext". Note that the '\n' and '\t' are the new-line and tab characters.

Every file and directory has a unique absolute path in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by '/'s. Using the above example, the absolute path to file2.ext is "dir/subdir2/subsubdir2/file2.ext". Each directory name consists of letters, digits, and/or spaces. Each file name is of the form name.extension, where name and extension consist of letters, digits, and/or spaces.

Given a string input representing the file system in the explained format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

 

Example 1:

Input: input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
Output: 20
Explanation: We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.

Example 2:

Input: input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
Output: 32
Explanation: We have two files:
"dir/subdir1/file1.ext" of length 21
"dir/subdir2/subsubdir2/file2.ext" of length 32.
We return 32 since it is the longest absolute path to a file.

Example 3:

Input: input = "a"
Output: 0
Explanation: We do not have any files, just a single directory named "a".

*/

class Solution {
public:

	// Both from discussion
    /* More easy to get. But next one is 0ms.

    int lengthLongestPath(string input) {
        stack<int> s;
        int longest_path = 0;
        for(int p1=0, p2=0; p1 < input.size(); p1=p2+1) {
            p2 = min(input.find('\n', p1), input.size());
            cout<<"p2 "<<p2<<endl;
            int levels = count(input.begin()+p1, input.begin()+p2, '\t');
            cout<<"levels "<<levels<<endl<<"s.size "<<s.size()<<endl;
            while(s.size() > levels) s.pop();
            s.push(p2-p1 - levels + (s.empty()?0:s.top()+1));
            cout<<"s.top "<<s.top()<<endl;
            if(count(input.begin()+p1, input.begin()+p2, '.'))
                longest_path = max(longest_path, s.top());
            cout<<"longestPath "<<longest_path<<endl;
        }
        return longest_path;
    }
    */
    int index = 0;
    inline int GetTokenLength(string &input, bool &isFile) {
        int length = 0;
        isFile = false;
        while (index < input.size()) {
            auto c = input[index++];
            if (c == '\n') { //Reached the end of the token
                break;
            } 
            ++length;
            if (c == '.')  {
                isFile = true;
                while (index < input.size() && input[index++] != '\n') {
                    ++length;
                }
                break;
            }
        }
        return length;
    }
    inline int GetNextDepth(string &input) {
        if (input[index] == '\n') {
            ++index;
        }
        int depth = 0;
        while (index < input.size() && input[index] == '\t') {
            ++depth;
            ++index;
        }
        return depth;
    }
    
    int lengthLongestPath(string input) {
        if (input.size() == 0 || input.find('.') == std::string::npos)
            return 0;
        int max_length = 0;
        bool isFile;
        stack<int> lengths; //Stores the length of the absolute path to the current subdirectory (without any trailing / symbol)
        lengths.push(0);
        while (index < input.size()) {
            int token_length = GetTokenLength(input, isFile);
            if (isFile) {
                int path_length = lengths.top() + token_length;
                if (path_length > max_length)
                    max_length = path_length;
            } else { //Token was folder
                lengths.push(lengths.top() + 1 + token_length);
            }
            if (index == input.size())
                break ;
            int depth_of_next = GetNextDepth(input);
            while (lengths.size() > depth_of_next + 1)
                lengths.pop();
        }
        return max_length;
    }
};