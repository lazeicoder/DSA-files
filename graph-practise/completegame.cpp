#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
vector<vector<int>> back;

int dp[100100];

int rec(int x) { // no of ways to reach node x from node 1
    if (x == 1) return 1;
    if (dp[x] != -1) return dp[x];

    int ans = 0;
    for (auto v : back[x]) {
        ans = (ans + rec(v)) % mod;
    }

    dp[x] = ans;
    return dp[x];
}
void solve(){
    cin >> n >> m;
    back.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        back[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));

    int ans = rec(n);

    cout << ans << endl;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}