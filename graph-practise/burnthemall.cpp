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
        if (vis[x] == true) continue;
        vis[x] = true;

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
    vis.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start;
    cin >> start;

    dijkstra(start);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto p : graph[i]) {
            int x = p.first, w = p.second;
            int temp = (dist[i] + dist[x] + w) * 5;
            ans = max(ans, temp);
        }
    }

    cout << ans << endl;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}