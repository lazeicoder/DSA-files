/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
    Author: Mia_Cara
    Problem : https://maang.in/problems/Find-the-Number-of-Rooms-191?resourceUrl=cs99-cp522-pl3546-rs191&returnUrl=%5B%22%2Fcourses%2FPremium-Day-Wise-Course-99%3Ftab%3Dchapters%22%5D
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define synced ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m;
vector<string> building;
vector<vector<bool>> vis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool checkMove(int i, int j) {
    if (i >= n || i < 0 || j >= m || j < 0) return false;
    else return true;
}

void dfs(int i, int j) {
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (checkMove(nx, ny) && building[nx][ny] == '.') {
            if (!vis[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    building.resize(n+1);
    for (int i = 0; i < n; i++) {
        cin >> building[i];
    }
    
    vis.resize(n, vector<bool>(m ,false));
    
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && building[i][j]=='.') {
                rooms++;
                dfs(i, j);
            }
        }
    }

    cout << rooms << endl;
}

signed main(){
    synced;
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}