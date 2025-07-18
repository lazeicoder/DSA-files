/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
Problem-statement : Given a sorted array containing only 0's and 1's, find the index of the 
first occurrence of '1' in the given array.

Input Format :
	1. first line contains 1 <= N <= 1e15, the size of the array
	2. second line contains N elements of the array arr[i], arr[i] = {0, 1} 
	
Output Format :
	Prints a single line containing the index of the first occurrence of '1'.
	
Sample Input:

	9
	0 0 0 0 1 1 1 1 1
	
Sample Output:

	4
*/


// Template code is given below :: 

bool check (int x) {
    if (x == 1) {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int lo = 0, hi = n-1;
    int ans = -1;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(arr[mid])) {
            ans = mid;
            hi = mid - 1;
        }else {
            lo = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
