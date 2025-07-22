/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
    Author: Mia_Cara
    Problem : https://maang.in/problems/Round-Trip-II-388?resourceUrl=cs99-cp522-pl3548-rs388&returnUrl=%5B%22%2Fcourses%2FPremium-Day-Wise-Course-99%3Ftab%3Dchapters%22%5D
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m;
vector<vector<int>> graph;
vector<int> vis;
bool is_cycle;

void dfs(int node) {
    if (is_cycle) return;
    vis[node] = 2;    

    for (auto neigh : graph[node]) {
        if (vis[neigh] == 1) {
            dfs(neigh);
        }
        if (vis[neigh] == 2) {
            // cycle detected
            is_cycle = true;
            return;
        }
    }

    vis[node] = 3;
}

void solve(){
    cin >> n >> m;
    graph.assign(n+1, vector<int> ());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    vis.assign(n+1, 1);

    is_cycle = false;
    for(int i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            dfs(i);
        }
    }

    if (is_cycle) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
}

signed main(){
    synced;
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}