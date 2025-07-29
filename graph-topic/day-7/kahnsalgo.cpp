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
vector<int> indegree;

vector<int> topo;

void kahn() {
    queue<int> q;
    for (int i=1;i<=n;i++){
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        topo.push_back(node);
        
        for (auto neigh : graph[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n+1);
    indegree.assign(n+1, 0);
    
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        // maintaining the indegree of the nodes.
        indegree[b]++;
    }
    
    kahn();
    
    if (topo.size()!=n) {
        cout << -1 << endl;
        cout << "Cycle found\n";
    }else{
        for(auto v : topo) {
            cout << v << " ";
        }
        cout << endl;
    }
    
}