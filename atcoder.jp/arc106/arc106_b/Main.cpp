#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int n, m; cin >> n >> m;
    vector <int> a(n), b(n);
    rep(i, n) cin >> a.at(i);
    rep(i, n) cin >> b.at(i);

    dsu G(n);

    rep(i, m){
        int c, d; cin >> c >> d;
        G.merge(c - 1, d - 1);
    }

    auto groups = G.groups();
    bool flag = true;
    for(int i = 0; i < groups.size(); i ++){
        ll sum_a, sum_b;
        sum_a = 0; sum_b = 0;
        for(auto num: groups.at(i)){
            sum_a += a.at(num);
            sum_b += b.at(num);
        }
        if(sum_a == sum_b) continue;
        flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}