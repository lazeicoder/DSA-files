/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
Problem Link : https://codeforces.com/problemset/problem/1352/C
Author : Mia_Cara
*/

signed main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        
        int low = 1, high = 2e9;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high-low)/2;
            int num = mid - (mid/n);
            if (num >= k) {
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}