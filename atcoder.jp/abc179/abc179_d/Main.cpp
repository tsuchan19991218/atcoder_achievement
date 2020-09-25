#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

ll mod = 998244353;

int main(){
    int n, k; cin >> n >> k;
    vector <pair<int, int>> l_r(k);
    rep(i, k){
        int l, r; cin >> l >> r;
        l_r.at(i) = make_pair(l, r);
    }
    vector <ll> dp(n + 1); dp.at(1) = 1;
    vector <ll> accum_dp(n + 1); accum_dp.at(1) = 1;

    for(int now_maze = 2; now_maze < n + 1; now_maze ++){
        int pre_far;
        int pre_near;
        ll tmp = 0;
        for(auto p: l_r){
            pre_far = max(now_maze - p.second - 1, 0);
            pre_near = max(now_maze - p.first, 0);
            tmp = (tmp + accum_dp.at(pre_near) - accum_dp.at(pre_far) + mod) % mod;
        }
        dp.at(now_maze) = tmp;
        accum_dp.at(now_maze) = (accum_dp.at(now_maze - 1) + dp.at(now_maze)) % mod;
    }
    cout << dp.at(n) << endl;
}