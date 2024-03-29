/*

1618. Maximum Font to Fit a Sentence in a Screen

You are given a string text. We want to display text on a screen of width w and height h. You can choose any font size from array fonts, which contains the available font sizes in ascending order.

You can use the FontInfo interface to get the width and height of any character at any available font size.

The FontInfo interface is defined as such:

interface FontInfo {
  // Returns the width of character ch on the screen using font size fontSize.
  // O(1) per call
  public int getWidth(int fontSize, char ch);

  // Returns the height of any character on the screen using font size fontSize.
  // O(1) per call
  public int getHeight(int fontSize);
}

The calculated width of text for some fontSize is the sum of every getWidth(fontSize, text[i]) call for each 0 <= i < text.length (0-indexed). The calculated height of text for some fontSize is getHeight(fontSize). Note that text is displayed on a single line.

It is guaranteed that FontInfo will return the same value if you call getHeight or getWidth with the same parameters.

It is also guaranteed that for any font size fontSize and any character ch:

    getHeight(fontSize) <= getHeight(fontSize+1)
    getWidth(fontSize, ch) <= getWidth(fontSize+1, ch)

Return the maximum font size you can use to display text on the screen. If text cannot fit on the display with any font size, return -1.

 

Example 1:

Input: text = "helloworld", w = 80, h = 20, fonts = [6,8,10,12,14,16,18,24,36]
Output: 6

Example 2:

Input: text = "leetcode", w = 1000, h = 50, fonts = [1,2,4]
Output: 4

Example 3:

Input: text = "easyquestion", w = 100, h = 100, fonts = [10,15,20,25]
Output: -1

*/

/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int n = fonts.size();
        int low=0, high=n-1;
        int maxVal = -1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if (willFontWork(text, w, h, fontInfo, fonts[mid])) {
                cout<<"Came hrer";
                maxVal = fonts[mid];
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return maxVal;
    }
    
    int willFontWork(string text, int w, int h, FontInfo fontInfo, int fontSize) {
        if(fontInfo.getHeight(fontSize) > h) {
            cout<<"Herigh"<<endl;
            return 0;
        }
        
        int tw = 0;
        for(int i=0; i<text.size(); i++) {
            tw += fontInfo.getWidth(fontSize, text[i]);
            cout<<tw<<" "<<fontSize<<" "<<w<<endl;
            if (tw > w) {
                return 0;
            }
        }
        cout<<"Last "<<tw<<" "<<fontSize<<" "<<w<<endl;
        return 1;
    }
    
};