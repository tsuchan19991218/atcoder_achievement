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
    int n, m, q; cin >> n >> m >> q;
    vector <pair<int, int>> v_w(n);
    rep(i, n){
        int v, w; cin >> w >> v;
        v_w.at(i) = make_pair(v, w);
    }
    sort(v_w.rbegin(), v_w.rend());
    vector <int> x(m);
    rep(i, m) cin >> x.at(i);
    while(q--){
        int l, r; cin >> l >> r;
        l --; r --;
        vector <pair<int, int>> new_bags;
        //cout << "____" << endl;
        for(int i = 0; i < m; i ++){
            if(l <= i && i <= r) continue;
            //cout << x.at(i) << endl;
            new_bags.push_back(make_pair(x.at(i), 0));
        }
        sort(new_bags.begin(), new_bags.end());


        int ans = 0;
        for(auto p: v_w){
            int value = p.first;
            int weight = p.second;

            //cout << value << endl;

            for(int y = 0; y < new_bags.size(); y ++){
                if(new_bags.at(y).first < weight) continue;
                if(new_bags.at(y).second != 0) continue;
                ans += value;
                new_bags.at(y).second = 1;
                break;
            }

            // for(auto &limit_used: new_bags){
            //     if(limit_used.second != 0) continue;
            //     if(limit_used.first < weight) continue;
            //     ans += value;
            //     limit_used.second = 1;
            // }

        }
        cout << ans << endl;
    }
}