#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int INF = 1000000000;

int MAX_A = 300001;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return 0;
}

int main(){
    int n, k; cin >> n >> k;
    vector <int> a(n);
    rep(i, n) cin >> a.at(i);
    segtree <int, op, e> dp(MAX_A);
    for(auto num: a){
        int m = dp.prod(max(0, num - k), min(MAX_A, num + k + 1));
        int plus_cnt = m + 1;
        dp.set(num, max(dp.get(num), plus_cnt));
    }
    cout << dp.all_prod() << endl;
}