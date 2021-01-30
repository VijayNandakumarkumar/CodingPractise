/*

Root of Number

In this question we’ll implement a function root that calculates the n’th root of a number. The function takes a nonnegative number x and a positive integer n, and returns the positive n’th root of x within an error of 0.001 (i.e. suppose the real root is y, then the error is: |y-root(x,n)| and must satisfy |y-root(x,n)| < 0.001).

Don’t be intimidated by the question. While there are many algorithms to calculate roots that require prior knowledge in numerical analysis (some of them are mentioned here), there is also an elementary method which doesn’t require more than guessing-and-checking. Try to think more in terms of the latter.

Examples:

input:  x = 7, n = 3
output: 1.913

input:  x = 9, n = 2
output: 3

*/

#include <iostream>
using namespace std;

double root(double x, unsigned int n) 
{
  // your code goes here
  
  double low = 1;
  double high = x;
  double mid = 0.0;
  
while(low<high) {
  
  mid = (low + high) /2;
  if ((mid - low) <= 0.001) {
    break;
  }
  
  double val = 1;
  int i = 0;
  
  while (i<n) {
      val *= mid;
      i++;
    }

    if ((val) < x) {
      low = mid;
    } else {
      high = mid;
    }
  }
  
  return mid;
  
}

int main() {
  cout<<root(7,3);
  return 0;
}
