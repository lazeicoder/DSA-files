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
    Author : Mia_Cara
*/

int n, m, q;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int compo) {
    vis[node] = compo;
    
    for (auto neigh : g[node]) {
        if (vis[neigh] == -1) {
            dfs(neigh, compo);
        }
    }
}

signed main()
{
    cin >> n >> m;
    g.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        g[a].push_back(b);
        
        // if undirected
        g[b].push_back(a);
    }
    
    vis.assign(n+1, -1);
    
    int compo = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            compo++;
            dfs(i, compo);
        }
    }
    
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[vis[i]]++;
    }
    
    if (compo == 1) {
        cout << 0 << endl;
    }else {
        int res = 0, nodes = 0;
        for (int i = 1; i <= compo; i++) {
            res += nodes * mp[i];
            nodes += mp[i];
        }
        cout << res << endl;
    }

    return 0;
}