/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
    Author: Mia_Cara
    Problem : https://maang.in/problems/Round-Trip-194?resourceUrl=cs99-cp522-pl3548-rs194&returnUrl=%5B%22%2Fcourses%2FPremium-Day-Wise-Course-99%3Ftab%3Dchapters%22%5D
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m;
vector<vector<int>> graph;
vector<bool> vis;

bool dfs(int node, int parent) {
    vis[node] = true;
    for (auto neigh : graph[node]) {
        if (!vis[neigh]) {
            if (dfs(neigh, node) == true) {
                return true;
            }
        }else if (neigh != parent) {
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    graph.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vis.assign(n+1, false);
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfs(i, -1)) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
    return;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}