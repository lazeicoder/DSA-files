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
Problem Link : https://atcoder.jp/contests/abc231/tasks/abc231_c
*/

signed main()
{
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    while (q--) {
        int x;
        cin >> x;
        
        int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int count = n - ind;
        cout << count << endl;
    }

    return 0;
}