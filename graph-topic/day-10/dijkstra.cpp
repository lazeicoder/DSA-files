/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<bool> vis;

void dijkstra(int st) {
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, st});
    dist[st] = 0;
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        int x = cur.second;
        
        if (vis[x] == true) continue;
        vis[x] = true;
        
        for (auto vp : graph[x]) {
            int v = vp.first, w = vp.second;
            
            if(dist[v] > dist[x] + w) {
                dist[v] = dist[x] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

signed main()
{
    cin >> n >> m;
    graph.resize(n+1, {});
    dist.assign(n+1, 1e18);
    vis.assign(n+1, false);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    int source;
    cin >> source;
    
    dijkstra(source);
    
    for (auto dis : dist) {
        cout << (dis == 1e18? -1: dis) << endl;
    }

    return 0;
}