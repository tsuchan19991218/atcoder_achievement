#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){
    int n, m; cin >> n >> m;
    vector <vector<pair<int, int>>> G(n);
    map <pair<int, int>, int> edge;
    rep(i, m){
        int a, b, c; cin >> a >> b >> c;
        a --; b --;
        G.at(a).push_back(make_pair(b, c));
        G.at(b).push_back(make_pair(a, c));
        edge[make_pair(a, b)] = i;
        edge[make_pair(b, a)] = i;
    }
    vector <int> is_used(m, -1);
    for(int i = 0; i < n; i ++){
        priority_queue <pair<pair<int, int>, int>, vector <pair<pair<int, int>, int>>, greater <pair<pair<int, int>, int>>> pq;
        vector <int> dist(n, INF);
        pq.push(make_pair(make_pair(0, i), -1));
        dist.at(i) = 0;
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            int now_cost = p.first.first;
            int now = p.first.second;
            int pre = p.second;
            if(now_cost > dist.at(now)) continue;
            if(pre != -1){
                is_used.at(edge[make_pair(pre, now)]) = 1;
            }
            for(auto next_cost: G.at(now)){
                int next = next_cost.first;
                int cost = next_cost.second;
                if(dist.at(next) <= dist.at(now) + cost) continue;
                dist.at(next) = dist.at(now) + cost;
                pq.push(make_pair(make_pair(dist.at(next), next), now));
            }
        }
    }

    int ans = 0;
    for(auto num: is_used) ans += (num == -1);
    cout << ans << endl;
}