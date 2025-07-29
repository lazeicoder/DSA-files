/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;

int dp[100100];

// saves the longest path starting from node
int rec(int node) {
    if(dp[node] != -1) return dp[node];
    int ans = 1;
    for (auto neigh : graph[node]) {
        ans = max(ans, 1+rec(neigh));
    }
    return dp[node]=ans;
}

int main()
{
    cin >> n >> m;
    graph.resize(n+1);
    
    for (int i = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    
    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, rec(i));
    }
    cout << ans << endl;

    return 0;
}