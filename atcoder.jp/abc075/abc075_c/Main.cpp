#include <atcoder/all>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){

    int n, m; cin >> n >> m;
    vector <int> a(m), b(m);
    rep(i, m){
        int _a, _b; cin >> _a >> _b;
        _a--;
        _b--;
        a.at(i) = _a;
        b.at(i) = _b;
    }

    int ans = 0;
    rep(i, m){

        dsu d(n);
        rep(j, m){
            if(j == i) continue;

            d.merge(a.at(j), b.at(j));
        }

        if(d.groups().size() != 1) ans ++;
    }
    cout << ans << endl;

}