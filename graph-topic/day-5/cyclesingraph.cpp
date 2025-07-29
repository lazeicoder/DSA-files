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
    Problem : To print if the graph contains cycle or not.
*/

int n,m;
vector<vector<int>> g;
vector<int> vis;

bool is_cyclic = false;

void dfs(int node, int parent) {
    vis[node] = 1;
    for (auto neigh : g[node]) {
        if (vis[neigh] == -1) {
            dfs(neigh, node);
        }else if (neigh != parent) {
            cout << neigh << " " << parent << endl;
            is_cyclic = true;
        }
    }
}


int main()
{
    cin >> n >> m;
    g.resize(n+1);
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        
        g[a].push_back(b);
        // if undirected
        g[b].push_back(a);
    }
    
    vis.assign(n+1, -1);
    
    int compo = 0;
    for (int i = 1; i <=n ; i++) {
        if (vis[i] == -1) {
            compo++;
            is_cyclic = false;
            dfs(i, -1);
            
            cout << compo << " compo is cyclic or not : " << (is_cyclic? "Yes": "No") << endl;
        }
    }
    

    return 0;
}