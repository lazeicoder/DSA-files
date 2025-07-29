/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void bfs01 (int st) {
    deque<int> dq;
    
    dq.push_front(st);
    dist[st] = 0;
    
    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        
        for (auto node_wgt_p : graph[cur]) {
            int node = node_wgt_p.first;
            int wgt = node_wgt_p.second;
            
            if (dist[node] > dist[cur] + wgt) {
                dist[node] = dist[cur] + wgt;
                if (wgt == 0) {
                    dq.push_front(node);
                }else {
                    dq.push_back(node);
                }
            }
            
        }
    }
}

int main()
{
    cin >> n >> m;
    
    graph.resize(n+1, {});
    dist.assign(n+1, 1e9);
    
    for (int i = 0; i < m; i++) {
        
        int a, b, w;
        cin >> a >> b >> w;
        
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
        
    }
    
    bfs01(1);
    
    for (auto dis : dist) {
        if (dis == 1e9) dis = -1;
        
        cout << dis << " ";
    }
    cout << endl;
    
    cout << dist[n] << endl;

    return 0;
}