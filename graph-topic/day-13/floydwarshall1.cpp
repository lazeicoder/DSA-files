/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int adj[401][401];
int dist[401][401];

int n,m;

void floydWarshallAlgo() {
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] != -1) {
                dist[i][j] = adj[i][j];
            }else {
                dist[i][j] = 1e9;
            }
        }
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dist[i][j] == 1e9) dist[i][j] = -1;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    
    floydWarshallAlgo();

    return 0;
}