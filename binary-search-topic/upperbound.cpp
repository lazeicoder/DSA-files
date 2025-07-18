/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement : Given an array of n integers and an integer x, find the 
index of the first element that is greater than x. (Also, called 
the upper bound of x).

Input Format :
    1. first line is n, x. Where n is the size of the array and x is the element.
    2. second line contains n elements of the array, arr[i], 0 <= i < n.
    
Output Format :
    Prints a single line that denotes the index of the element.
    
    
Sample Input :
    9 7
    1 5 6 8 8 10 11 11 12
    
Sample Output :
    3 
*/

bool check(int a, int b) {
    if (a > b) return 1;
    return 0;
}

int main()
{
    int n, x;
    cin>>n>>x;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int lo = 0, hi = n-1;
    int ans = -1;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(arr[mid], x)) {
            ans = mid;
            hi = mid - 1;
        }else {
            lo = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}