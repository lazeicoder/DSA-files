/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
Given a graph, with n nodes and m edges and find the dfs traversal of the graph.
Input Format :
    1. first line contains n, m. n is the number os nodes and m is the number of 
    edges of the given graph.
    2. the next m lines contains the edge between the 2 nodes, u and v.
    
Output Format :
    the visited array and the traversal array.
    
Sample Input :
    6 6
    1 2
    2 3
    3 4
    3 5
    1 6
    6 3
    
Sample Output :
    1 1
    2 1
    3 1
    4 1
    5 1
    6 1
    1 2 3 4 5 6 
*/

int n,m;
vector<vector<int>> g;
vector<int> vis;

vector<int> temp;

void dfs(int node) {
    vis[node] = 1;
    temp.push_back(node);
    
    for (auto neigh : g[node]) {
        if (vis[neigh] == -1) {
            dfs(neigh);
        }
    }
}

int main()
{
    cin >> n >> m;
    g.resize(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // if undirected
        // g[v].push_back(u);
    }
    
    // Initialize the vis array with -1 (unvisited).
    vis.assign(n+1, -1);
    
    // Start dfs traversal from node 1.
    dfs(1);
    
    for(int i = 1; i <= n; i++) {
        cout << i << " " << vis[i] << endl;
    }
    
    for(auto v : temp) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}