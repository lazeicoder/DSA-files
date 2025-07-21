/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
    Author: Mia_Cara
    Problem : https://cses.fi/problemset/task/1666
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m;
vector<vector<int>> graph;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;
    
    for (auto neigh : graph[node]) {
        if (!vis[neigh]) {
            dfs(neigh);
        }
    }
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

    vis.assign(n+1, 0);
    map<int, int> mpp;
    int prevNode = -1, compo = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if(prevNode != -1) {
                mpp[prevNode] = i;
            }
            dfs(i);
            prevNode = i;
            compo++;
        }
    }
    
    cout << compo-1 << endl;
    
    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}