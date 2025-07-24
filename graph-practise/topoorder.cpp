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

bool is_cycle = false;

void dfs(int node) {
    vis[node] = 1;
    
    for (auto neigh : graph[node]) {
        if (vis[neigh] == 0) {
            dfs(neigh);
        }else if(vis[neigh] == 1) {
            is_cycle = true;
        }
    }
    topo.push_back(node);
    vis[node] = 2;
}

int main()
{
    cin >> n >> m;
    graph.resize(n+1);
    vis.assign(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= n ;i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    
    // reverse(topo.begin(), topo.end());
    
    if (is_cycle) {
        cout << "IMPOSSIBLE\n";
    }else {
        for (auto v : topo) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
