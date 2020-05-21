/**
1108. Defanging an IP Address

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/

#include<bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) {
    for(int i = 0;i<address.length();i++){
        if(address[i]=='.'){
            address.insert(i,"[");
            i+=2;
            address.insert(i,"]");
        }
    }
    return address;
}

int main() {
	string s = "255.100.50.0";
	cout<<defangIPaddr(s);
	return 0;
}
