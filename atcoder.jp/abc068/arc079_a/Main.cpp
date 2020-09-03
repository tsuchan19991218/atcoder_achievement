#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n + 1);
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }  
    vector<int> dist(n + 1, 1000000000);
    queue<int> que;

    dist[1] = 0;
    que.push(1);
    while (!que.empty()){
        int v = que.front();
        que.pop();

        for (int next_v : G[v]){
            if (dist[next_v] <= dist[v] + 1) continue;
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
//    for (int i = 1; i <= n; i ++) cout << dist[i] << endl;
    if (dist[n] <= 2){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}