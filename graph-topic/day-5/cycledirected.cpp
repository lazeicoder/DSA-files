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
vector<int> parent;
bool is_cycle = false;

vector<int> cycle;

void dfs(int node, int par) {
    vis[node] = 2;
    parent[node] = par;
    
    for (auto neigh : g[node]) {
        if (vis[neigh] == 1) {
            // node to neigh is a forward edge
            dfs(neigh, node);
        }else if (vis[neigh] == 2) {
            // node neigh is a back edge
            // we found a cycle
            if (is_cycle == 0) {
                int temp = node;
                while (temp != neigh) {
                    cycle.push_back(temp);
                    temp = parent[temp];
                }
                cycle.push_back(temp);
                reverse(cycle.begin(), cycle.end());
            }
            is_cycle = 1;
        }
    }
    
    vis[node] = 3;
}

signed main()
{
    cin >> n >> m;
    g.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        g[a].push_back(b);
        
    }
    
    vis.assign(n+1, 1);
    parent.assign(n+1, -1);
    
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            dfs(i, -1);
        }
    }
    
    cout << (is_cycle? "YES\n" : "NO\n");
    
    for (auto v : cycle) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}