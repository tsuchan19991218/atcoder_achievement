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
    int n, m, x, y; cin >> n >> m >> x >> y;
    x--; y--;
    //vector <ll> a(m), b(m), t(m), k(m);
    // vector <vector<pair<int, int>>> time_k(n, vector<pair<int, int>>(n));
    // vector <vector<int>> G(n);
    vector <vector<pair<ll, pair<ll, ll>>>> G(n);
    rep(i, m){
        ll _a, _b, _t, _k; cin >> _a >> _b >> _t >> _k;
        _a --;
        _b --;
        // a.at(i) = _a;
        // b.at(i) = _b;
        // t.at(i) = _t;
        // k.at(i) = _k;

        G.at(_a).push_back(make_pair(_b, make_pair(_t, _k)));
        G.at(_b).push_back(make_pair(_a, make_pair(_t, _k)));
    }

    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> d;

    vector <ll> ans(n, INFLL);
    //ans.at(x) = 0;
    d.push(make_pair(0, x));

    while(d.size()){
        auto p = d.top();
        d.pop();

        ll now_time = p.first;
        int now_station = p.second;

        if(now_time > ans.at(now_station)) continue;

        //cout << now_time << " " << now_station << endl;

        for(auto next_t_k: G.at(now_station)){
            int next_station = next_t_k.first;
            ll t = next_t_k.second.first;
            ll k = next_t_k.second.second;

            if(now_time % k == 0){
                ll next_time = now_time + t;
                if(next_time >= ans.at(next_station)) continue;
                d.push(make_pair(next_time, next_station));
                ans.at(next_station) = next_time;
            }
            else{
                ll next_time = ((now_time / k) * k) + k + t;
                if(next_time >= ans.at(next_station)) continue;
                d.push(make_pair(next_time, next_station));
                ans.at(next_station) = next_time;
            }
        }
    }

    if(ans.at(y) == INFLL){
        cout << -1 << endl;
    }
    else cout << ans.at(y) << endl;
}