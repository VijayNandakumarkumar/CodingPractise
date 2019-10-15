#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A;

string findMaxNumDiv235(string A){
    int n = A.length();
    string res;
    res = A;

    sort(res.rbegin(), res.rend()); // sort descending order

// Check division by 2 and 5:
    if (res[n-1]  != '0') return "no number can be formed";

// Check division by 3:
    int SumDigit = 0;
    for(int i=0; i<n; i++) SumDigit += res[i] - '0';

    // Divisible by 3?:
    if (SumDigit % 3 == 0) return res;

    // Not divisible by 3:
    // Delete 1 digit:
    cout<<res<<" "<<SumDigit;
    for(int i = n-2; i>=0; i--)
    if ( (res[i] - '0') %3 == SumDigit %3){
    	printf("\nCame here - %c\n", res[i]);
        res.erase(i,1);
        return res;
    };

    // Delete 2 digits:
    for(int i = n-2; i>=0; i--)
    if ( (res[i] - '0') %3 != 0){
    	printf("\nCame here - %c\n", res[i]);
        res.erase(i-1,2);
        cout<<res;
        return res;
    };

    return "no number can be formed";
};

int main()
{
//    A = "16870";
//    A = "01234567892";
		A = "174470";
//    A = "01";
    cout <<"Input: "<<A<<endl;
    cout <<"The biggest number is: "<<findMaxNumDiv235(A)<<endl;
    return 0;
}
