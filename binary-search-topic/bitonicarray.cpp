/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement : Given an array of n integers, find the 
index of the peak,i.e, the element with the highest value
, element in the given array. (Bitonic Array problem).

Input Format :
    1. first line is n, x. Where n is the size of the array.
    2. second line contains n elements of the array, arr[i], 0 <= i < n.
    
Output Format :
    Prints a single line that denotes the index of the element.
    
    
Sample Input :
    7
    7 9 11 13 4 3 1
    
Sample Output :
    3
*/

int n;
int arr[100100];

bool check (int ind) {
    if (arr[ind] > arr[ind+1] || ind == n-1) return 1;
    return 0;
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int low = 0, high = n-1;
    int ans = n-1;
    
    while(low <= high) {
        int mid = low + (high - low)/2;
        
        if (check(mid)) {
            ans = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
