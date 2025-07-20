/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
    Author: Mia_Cara
    Problem : To print if the graph is bipartite or not.
*/

int n,m;
vector<vector<int>> g;
vector<int> vis;

bool is_bipartite = true;

void dfs(int node, int color) {
    vis[node] = color;
    for (auto neigh : g[node]) {
        if (vis[neigh] == -1) {
            dfs(neigh, 3-color);
        }else if (vis[node] == vis[neigh]) {
            is_bipartite = false;
        }
    }
}


int main()
{
    cin >> n >> m;
    g.resize(n+1);
    
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        
        g[a].push_back(b);
        // if undirected
        g[b].push_back(a);
    }
    
    vis.assign(n+1, -1);
    
    for (int i = 1; i <=n ; i++) {
        if (vis[i] == -1) {
            dfs(i, 1);
        }
    }
    
    if (is_bipartite) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
    
    for (int i = 1; i <= n; i++) {
        cout << i << ": " << vis[i] << endl;
    }

    return 0;
}