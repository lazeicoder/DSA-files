/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
Given a graph, with n nodes and m edges and find :
    1. The number of components of the graph, x.
    2. Size of each component.
    3. Set of the nodes in the components.
Input Format :
    1. first line contains n, m. n is the number os nodes and m is the number of 
    edges of the given graph.
    2. the next m lines contains the edge between the 2 nodes, u and v.
    
Output Format :
    1. The number of components of the graph, x.
    2. Size of each component.
    3. Set of the nodes in the components.
    
Sample Input :
    
    
Sample Output :
    
*/

int n,m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node, vector<int>& compo) {
    vis[node] = 1;
    compo.push_back(node);
    
    for (auto neigh : g[node]) {
        if (vis[neigh] == -1) {
            dfs(neigh, compo);
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
        g[v].push_back(u);
    }
    
    // Initialize the vis array with -1 (unvisited).
    vis.assign(n+1, -1);
    
    int components = 0;
    vector<int> sizes;
    vector<vector<int>> compoSet;
    
    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            components++;
            
            vector<int> compo;
            dfs(i, compo);
            sizes.push_back(compo.size());
            compoSet.push_back(compo);
        }
    }
    
    cout << components << endl;
    
    for (int i = 0; i < components; i++) {
        cout << "Compo " << i << " Size : " << sizes[i] << endl;
    }
    
    for (int i = 0; i < components; i++) {
        cout << "Compo " << i << " Elements : ";
        for (auto node : compoSet[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}