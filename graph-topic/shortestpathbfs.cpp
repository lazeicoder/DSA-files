/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
using state = pair<int, int>;

int n, m, a, b, x, y;

vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

bool check (int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m /*|| blocked[i][j]*/) {
        return false;
    }
    return true;
}

vector<vector<int>> dist;
int bfs(int sx, int sy) {
    dist.resize(n+1, vector<int>(m+1, 1e9));
    
    queue<state> q;
    q.push({sx, sy});
    
    dist[sx][sy] = 0;
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        
        int x = cur.first;
        int y = cur.second;
        
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (check(nx, ny) && dist[nx][ny] > dist[x][y]+1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m >> x >> y >> a >> b;
    
    bfs(x, y);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}