/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int dist[404][404];
int parent[404][404];
int n, m;

void printPath(int i, int j){
    if(i!=j) printPath(i, parent[i][j]);
    cout << j << " ";
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i!=j) dist[i][j] = 1e9;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            parent[i][j] = i;
        }
    }
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    // i -> x -> y -> .. -> parent[i][j] -> j
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    return 0;
}