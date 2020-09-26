#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const ll INF = 1000000000;

int main(){
    int n, q; cin >> n >> q;
    vector <tuple<int, int, int>> Q(q);
    rep(i, q){
        int t, u, v; cin >> t >> u >> v;
        Q.at(i) = make_tuple(t, u, v);
    }

    dsu d(n);
    for(auto p: Q){
        int t, u, v;
        tie(t, u, v) = p;
        if(t == 0) d.merge(u, v);
        else{
            cout << (int)(d.same(u, v)) << endl;
        }
    }
}