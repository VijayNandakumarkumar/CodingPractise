#include<bits/stdc++.h>
using namespace std;
std::string encrypt(std::string text, int s)
{
    string result = "";
    string neww ="";
 
    // traverse text
    for (int i=0;i<text.length();i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i])){
		
            result += ((text[i]+s-65)%26 +65);
// strcat(neww,result);
 }
    // Encrypt Lowercase letters
    else
        result += ((text[i]+s-97)%26 +97);
    }
 
    // Return the resulting string
    return result;
}
 
// Driver program to test the above function
int main()
{
    std::string text="";
    int s = 4;
    cout<<"enter text\n";
	getline(cin,text);
	cout<<atoi('X');
    cout << "Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher: " << encrypt(text, s);
    return 0;
}
