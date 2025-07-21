/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
    Author: Mia_Cara
    Problem : https://maang.in/problems/Colour-Tree-416?resourceUrl=cs99-cp522-pl3546-rs416&returnUrl=%5B%22%2Fcourses%2FPremium-Day-Wise-Course-99%3Ftab%3Dchapters%22%5D
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
map<int, int> degree;

void solve(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        degree[a]++;
        degree[b]++;
    }

    int res = -1;
    for (int i = 1; i <= n; i++) {
        res = max(res, degree[i]);
    }

    cout << res+1 << endl;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}