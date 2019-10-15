#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string word)
{
	int i = 0, j = word.length()-1, flag = 0;
	while(i<j)
	{
		if(word[i++] == word[j--])
		{
			//cout<<"\n in";
			flag = 1;
		}
		else
		{	//cout<<"\tout";
			flag = 0;
			break;
		}
	}
if(flag == 1)
{
//cout<<"\npalindrome"<<word;
return true;
}else
{
//cout<<"\n not palindrome"<<word;
return false;
}
}
int main()
{
	string final = "",word = "";
	string input = "";
	getline(cin,input);
	input += " ";
	//cout<<input;
	//cout<<input.size();
	int n = input.size();
	//cout<<n;
/*	for (int i = 0; i < n; i++) {
 
    // accumulating characters of the current word
    if ((input[i] != ' ')&&(input[i] != '\0'))
    {	
      word = word + input[i];
 		//cout<<word<<"\t";
	 }
    else {
 cout<<word<<"\t";
      // if 'word' is not palindrome then a
      // add it to 'final_str'
      if (!(ispalindrome(word)))
        final += word + " ";
 
      // reset
      word = "";
    }*/
	for(int i=0;i<n;i++)
	{
		if(input[i] != ' ')
		{
			word += input[i];
		}
		else
		{	//	cout<<"\n the word is"<<word;
					if(!(ispalindrome(word)))
			{
				final += word + " ";
			//	cout<<"\n final ="<<final;
			}
			
		
				word = "";//NULL;
		
		}
	}
	cout<<"\n"<<final;
	return 0;
}
