#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

// 昇順に処理する
// std::priority_queue<
//     int,                // 要素の型はint
//     std::vector<int>,   // 内部コンテナはstd::vector (デフォルトのまま)
//     std::greater<int>   // 昇順 (デフォルトはstd::less<T>)
// > que;

int main(){
    int n, m; cin >> n >> m;
    vector <vector<int>> cost(n, vector<int>(n, INF));
    vector <vector<int>> G_go(n), G_come(n);


    rep(i, m){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;

        cost.at(a).at(b) = min(c, cost.at(a).at(b));

        if(a == b) continue;
        G_go.at(a).push_back(b); // a -> b
        G_come.at(b).push_back(a); // b -> a
    }

    for(int i = 0; i < n; i ++){
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        vector <int> dist_go(n, INF);
        vector <int> dist_come(n, INF);
        dist_go.at(i) = 0; dist_come.at(i) = 0; 
        
        que.push(make_pair(0, i));
        while(que.size()){
            auto p = que.top();
            que.pop();
            int d = p.first;
            int now = p.second;
            //cout << d << " " << now << endl;
            if(dist_go.at(now) < d) continue;

            for(auto next: G_go.at(now)){
                if(cost.at(now).at(next) + d >= dist_go.at(next)) continue;
                //cout << cost.at(now).at(next) + d << " " << dist_go.at(next) << endl;
                dist_go.at(next) = cost.at(now).at(next) + d;
                que.push(make_pair(cost.at(now).at(next) + d, next));
            }
        }

        que.push(make_pair(0, i));
        while(que.size()){
            auto p = que.top();
            que.pop();
            int d = p.first;
            int now = p.second;
            if(dist_come.at(now) < d) continue;

            for(auto next: G_come.at(now)){
                if(cost.at(next).at(now) + d >= dist_come.at(next)) continue;
                dist_come.at(next) = cost.at(next).at(now) + d;
                que.push(make_pair(cost.at(next).at(now) + d, next));
            }
        }

        int ans = cost.at(i).at(i);

        for(int k = 0; k < n; k ++){
            if(i == k) continue;
            int tmp = dist_come.at(k) + dist_go.at(k);
            ans = min(ans, tmp);
        }

        if(ans >= INF){
            cout << -1 << endl;
        }
        else cout << ans << endl;
    }

}