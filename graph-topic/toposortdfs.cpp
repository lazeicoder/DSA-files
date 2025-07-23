/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> vis;

vector<int> topo;

void dfs(int node) {
    vis[node] = 1;
    for (auto neigh : graph[node]) {
        if (!vis[neigh]) {
            dfs(neigh);
        }
    }
    topo.push_back(node);
}

int main()
{
    cin >> n >> m;
    graph.resize(n+1);
    
    for (int i = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    vis.assign(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    
    reverse(topo.begin(), topo.end());
    
    for (auto v : topo) {
        cout << v << " ";
    }

    return 0;
}