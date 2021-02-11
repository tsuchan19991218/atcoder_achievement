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
    vector <ll> x(n);
    rep(i, m){
        ll _x, _y; cin >> _x >> _y;
        _x--; _y--;
        x.at(_x) |= (1 << _y);
    }
    //x[i] = s　ならば、頂点iから頂点集合sに向かって友好編が張っている

    vector <ll> dp((1 << n));
    dp.at(0) = 1;
    rep(s, (1 << n)){
        //cout << s << endl;
        for(int i = 0; i < n; i ++){
            //頂点集合sは頂点iを含んでいるか？
            if(!((s >> i) & 1)) continue;

            //今考えている頂点集合sの中から末端（右端）の頂点を探す
            //頂点iは右端か？　つまり、他のsに含まれる頂点へ辺が張っていないか？
            if(x.at(i) & s) continue;


            //dp[s]を足す
            dp.at(s) += dp.at(s ^ (1 << i));
        }
    }

    cout << dp.at((1 << n) - 1) << endl;;
}