#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<bool> vis;

void dijkstra(int st) {
    priority_queue<pair<int, int>> pq;

    pq.push({0, st});
    dist[st] = 0;

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int x = cur.second;
        if (vis[x]) continue;
        vis[x] = 1;

        for (auto vp : graph[x]) {
            int v = vp.first;
            int w = vp.second;

            if (dist[v] > dist[x] + w) {
                dist[v] = dist[x] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    graph.resize(n+1, {});
    dist.assign(n+1, 1e18);
    vis.assign(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}