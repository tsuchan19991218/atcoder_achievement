#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n, m; cin >> n >> m;
    vector <vector<int>> G(n + 1);
    rep(i, m){
        int u, v; cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    vector <int> seen(n + 1, -1);

    deque <pair<int, int>> d;

    int cnt = 0;
    for(int i = 1; i < n + 1; i ++){
        if(seen.at(i) != -1) continue;
        seen.at(i) = 1;
        d.push_back(make_pair(i, -1));

        bool ok = true;
        while(!d.empty()){
            auto v = d.front();
            d.pop_front();

            for(auto to: G.at(v.first)){
                if(to == v.second) continue;
                if(seen.at(to) != -1){
                    //cout << v << " " << to << endl;
                    ok = false;
                    continue;
                }
                seen.at(to) = 1;
                d.push_back(make_pair(to, v.first));
            }
        }
        if(ok) cnt += 1;
    }

    cout << cnt << endl;
}