#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int INF = 1000000000;

int main(){
    int n, m; cin >> n >> m;
    dsu d(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        d.merge(a - 1, b - 1);
    }
    auto vec = d.groups();
    cout << vec.size() - 1 << endl;
}