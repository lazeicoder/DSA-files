/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem : https://maang.in/problems/Easy-Graph-Queries-400?resourceUrl=cs99-cp522-pl3545-rs400&returnUrl=%5B%22%2Fcourses%2FPremium-Day-Wise-Course-99%3Ftab%3Dchapters%22%5D
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

int main()
{
    cin >> n >> m >> q;
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
    
    while (q--) {
        int p;
        cin >> p;
        if (p == 1) {
            int x;
            cin >> x;
            
            int sz = mp[vis[x]];
            cout << sz << endl;
        }else {
            int x, y;
            cin >> x >> y;
            
            if (vis[x] == vis[y]) {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}