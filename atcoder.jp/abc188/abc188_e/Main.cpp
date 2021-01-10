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
    vector <ll> a(n);
    rep(i, n) cin >> a.at(i);
    vector <vector<int>> G(n);
    rep(i, m){
        int x, y; cin >> x >> y;
        x--; y--;
        G.at(x).push_back(y);
    }

    vector <ll> dp(n, -INFLL);
    ll ans = -INFLL;
    vector <int> seen(n, -1);
    for(int i = n - 1; i >= 0; i --){
        seen.at(i) = 1;
        auto children = G.at(i);
        //if(children.size() == 0) continue;
        //sort(children.rbegin(), children.rend());
        // auto great_child = children.at(0);
        // dp.at(i) = max(dp.at(i), max(dp.at(great_child) + a.at(great_child) - a.at(i), a.at(great_child) - a.at(i)));
        for(auto child: children){
            dp.at(i) = max(dp.at(i), max(dp.at(child) + a.at(child) - a.at(i), a.at(child) - a.at(i)));
        }
        ans = max(ans, dp.at(i));
        //cout << dp.at(i) << endl;
    }

    cout << ans << endl;

}