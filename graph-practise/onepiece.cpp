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
vector<vector<int>> wind;
vector<vector<int>> dist;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

bool check (int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    return 1;
}

void bfs01(int x, int y){
    deque<pair<int, int>> dq;
    dist[x][y] = 0;

    dq.push_front({x, y});

    while(!dq.empty()) {
        auto p = dq.front();
        dq.pop_front();

        int curx = p.first;
        int cury = p.second;

        for (int k = 0; k < 4; k++) {
            int nx = curx + dx[k];
            int ny = cury + dy[k];

            int wgt = (k+1 == wind[curx][cury] ? 0 : 1);
            if (check(nx, ny) && dist[nx][ny] > dist[curx][cury] + wgt) {
                dist[nx][ny] = dist[curx][cury]+wgt;
                if (wgt == 0) {
                    dq.push_front({nx, ny});
                }else {
                    dq.push_back({nx, ny});
                }
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    wind.resize(n, vector<int> (m));
    dist.resize(n, vector<int> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> wind[i][j];

            dist[i][j] = 1e9;
        }
    }

    bfs01(0, 0);

    cout << dist[n-1][m-1] << endl;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}