#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
vector<vector<int>> edge;
vector<int> dist;

void solve(){
    cin >> n >> m;
    edge.resize(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i][0] = u;
        edge[i][1] = v;
        edge[i][2] = -w;
    }

    dist.assign(n+1, 1e18);
    dist[1] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u = edge[j][0], v = edge[j][1], w = edge[j][2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    bool neg = false;
    for(int i = 0; i < m; i++) {
        int u = edge[i][0], v = edge[i][1], w = edge[i][2];
        if (dist[v] != 1e18 && dist[u] != 1e18 && dist[v] > dist[u] + w) {
            neg = true;
            break;
        }
    }

    cout << (neg == false? -dist[n]: -1) << endl;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}