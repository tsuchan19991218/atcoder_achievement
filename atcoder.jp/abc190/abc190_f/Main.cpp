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

int main(){
    int n; cin >> n;
    vector <int> a(n);
    ll ans = 0;
    rep(i, n){
        cin >> a.at(i);
    }

    fenwick_tree <ll> fw(n);
    rep(i, n){
        ll tmp = fw.sum(0, a.at(i));
        ans += i - tmp;
        fw.add(a.at(i), 1);
    }

    rep(i, n){
        cout << ans << endl;
        ans += n - 1 - a.at(i);
        ans -= a.at(i);
    }

}