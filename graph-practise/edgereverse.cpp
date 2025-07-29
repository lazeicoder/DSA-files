/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void solve(){
    cin >> n >> m;
    graph.assign(n+1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 1});
    }

    deque<int> q;
    dist.assign(n+1, 1e9);

    int s = 1;
    q.push_front(s);
    dist[s] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop_front();

        for (auto p : graph[x]) {
            int v = p.first, w = p.second;
            if (dist[v] > dist[x]+w) {
                dist[v] = dist[x]+w;
                if (w == 0) {
                    q.push_front(v);
                }else {
                    q.push_back(v);
                }
            }
        }
    }

    cout << (dist[n] == 1e9? -1: dist[n]) << endl;
}

signed main(){
    synced;
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}