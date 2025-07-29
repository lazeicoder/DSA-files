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
    4. Given q queries, each line having 2 integers x, y. find if x and y are in 
    the same connected component.
    
    
Input Format :
    1. first line contains n, m. n is the number os nodes and m is the number of 
    edges of the given graph.
    2. the next m lines contains the edge between the 2 nodes, u and v.
    3. the next line contains an integer q.
    4. then the next q lines, contain 2 integers x and y.
    
Output Format :
    1. The number of components of the graph, x.
    2. Size of each component.
    3. Set of the nodes in the components.
    4. Yes if x and y are in the same component else print NO.
    
Sample Input :
    9 7
    1 2 
    2 3
    3 4
    4 1
    5 6
    5 7
    8 9
    5
    2 3
    2 6
    5 9
    8 9
    4 1
    
Sample Output :
    3
    
    Compo 0 Size : 4
    Compo 1 Size : 3
    Compo 2 Size : 2
    
    Compo 0 Elements : 1 2 3 4 
    Compo 1 Elements : 5 6 7 
    Compo 2 Elements : 8 9 
    
    Belongs to the same component : 1
    Different components!!
    Different components!!
    Belongs to the same component : 3
    Belongs to the same component : 1
    
*/

int n,m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node, vector<int>& compo, int col) {
    vis[node] = col;
    compo.push_back(node);
    
    for (auto neigh : g[node]) {
        if (vis[neigh] == -1) {
            dfs(neigh, compo, col);
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
            dfs(i, compo, components);
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
    
    int q;
    cin >> q;
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        if (vis[x] == vis[y]) {
            cout << "Belongs to the same component : " << vis[x] << endl;
        }else {
            cout << "Different components!!\n";
        }
    }

    return 0;
}