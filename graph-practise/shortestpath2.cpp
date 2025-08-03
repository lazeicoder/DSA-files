#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int dist[510][510];
int n, m, q;

void solve(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) dist[i][j] = 1e18;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--) {
        int x, y;
        cin >> x >> y;

        cout << (dist[x][y] == 1e18? -1 : dist[x][y]) << endl;
    }
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}