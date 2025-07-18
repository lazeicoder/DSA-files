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
Problem Link : https://codeforces.com/contest/706/problem/B
Author : Mia_Cara
*/

signed main()
{
    int n, q;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    cin >> q;
    
    while (q--) {
        int x;
        cin >> x;
        
        int ind = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (arr[ind-1] <= x) {
            cout << ind << endl;
        }else {
            cout << 0 << endl;
        }
    }

    return 0;
}