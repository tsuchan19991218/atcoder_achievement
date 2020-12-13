#include <bits/stdc++.h>
#include <atcoder/all>
#include <math.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

ll op(ll a, ll b) {
        return a ^ b;
    }

ll e() {
    return (ll)0;
}

int main(){
    int n, q; cin >> n >> q;
    vector <ll> a(n);
    rep(i, n){
        cin >> a.at(i);
    }

    segtree <ll, op, e> seg(n);
    rep(i, n){
        seg.set(i, a.at(i));
    }

    vector <int> t(q), x(q), y(q);
    rep(i, q){
        int _t, _x, _y;
        cin >> _t >> _x >> _y;
        t.at(i) = _t;
        if(_t == 2){
            x.at(i) = _x - 1;
            y.at(i) = _y;
        }
        else{
            x.at(i) = _x - 1;
            y.at(i) = _y;
        }
    }

    rep(i, q){
        if(t.at(i) == 1){
            seg.set(x.at(i), seg.get(x.at(i)) ^ y.at(i));
        }
        else{
            cout << seg.prod(x.at(i), y.at(i)) << endl;
        }
    }
}